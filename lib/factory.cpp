/**
 * Copyright eBay Corporation 2018
 */

#include <nuraft_grpc/grpc_client.hpp>
#include <string>

#include "factory.h"
#include "service.h"
#include "messaging_service.grpc.pb.h"

SDS_LOGGING_DECL(sds_msg)

namespace sds::messaging {

class messaging_client : public sds::grpc_client< Messaging >, public std::enable_shared_from_this< messaging_client > {
public:
    using sds::grpc_client< Messaging >::grpc_client;
    ~messaging_client() override = default;

    using sds::grpc_base_client::send;

    std::atomic_uint bad_service;

    void send(RaftGroupMsg const& message, handle_resp complete) {
        auto weak_this = std::weak_ptr< messaging_client >(shared_from_this());
        auto group_compl = [weak_this, complete](auto response, auto status) mutable {
            if (::grpc::INVALID_ARGUMENT == status.error_code()) {
                LOGERRORMOD(sds_msg, "Sent message to wrong service, need to disconnect!");
                if (auto mc = weak_this.lock(); mc) { mc->bad_service.fetch_add(1, std::memory_order_relaxed); }
            }
            complete(*response.mutable_message(), status);
        };

        _stub->call_unary< RaftGroupMsg, RaftGroupMsg >(message, &Messaging::StubInterface::AsyncRaftStep, group_compl,
                                                        2 /* deadline in seconds */);
    }

protected:
    void send(sds::RaftMessage const&, handle_resp) override { throw std::runtime_error("Bad call!"); }
};

class group_client : public sds::grpc_base_client {
    shared< messaging_client > _client;
    group_name_t const _group_name;
    shared< group_metrics > _metrics;
    std::string const _client_addr;

public:
    group_client(shared< messaging_client > client, std::string const& client_addr, group_name_t const& grp_name,
                 shared< sisl::MetricsGroupWrapper > metrics) :
            sds::grpc_base_client(),
            _client(client),
            _group_name(grp_name),
            _metrics(std::static_pointer_cast< group_metrics >(metrics)),
            _client_addr(client_addr) {}

    ~group_client() override = default;

    shared< messaging_client > realClient() { return _client; }
    void setClient(shared< messaging_client > new_client) { _client = new_client; }

    void send(sds::RaftMessage const& message, handle_resp complete) override {
        RaftGroupMsg group_msg;

        LOGTRACEMOD(sds_msg, "Sending [{}] from: [{}] to: [{}] Group: [{}]",
                    nuraft::msg_type_to_string(nuraft::msg_type(message.base().type())), message.base().src(),
                    message.base().dest(), _group_name);
        if (_metrics) { COUNTER_INCREMENT(*_metrics, group_sends, 1); }
        group_msg.set_intended_addr(_client_addr);
        group_msg.set_group_name(_group_name);
        group_msg.mutable_message()->CopyFrom(message);
        _client->send(group_msg, complete);
    }
};

std::error_condition mesg_factory::create_client(const std::string& client,
                                                 nuraft::ptr< nuraft::rpc_client >& raft_client) {
    // Re-direct this call to a global factory so we can re-use clients to the same endpoints
    LOGDEBUGMOD(sds_msg, "Creating client to {}", client);
    auto m_client = std::dynamic_pointer_cast< messaging_client >(_group_factory->create_client(client));
    if (!m_client) { return std::make_error_condition(std::errc::connection_aborted); }
    raft_client = std::make_shared< group_client >(m_client, client, _group_name, _metrics);
    return (!raft_client) ? std::make_error_condition(std::errc::invalid_argument) : std::error_condition();
}

std::error_condition mesg_factory::reinit_client(const std::string& client,
                                                 sds::shared< nuraft::rpc_client >& raft_client) {
    LOGDEBUGMOD(sds_msg, "Re-init client to {}", client);
    auto g_client = std::dynamic_pointer_cast< group_client >(raft_client);
    auto new_raft_client = std::static_pointer_cast< nuraft::rpc_client >(g_client->realClient());
    if (auto err = _group_factory->reinit_client(client, new_raft_client); err) { return err; }
    g_client->setClient(std::dynamic_pointer_cast< messaging_client >(new_raft_client));
    return std::error_condition();
}

std::error_condition group_factory::create_client(const std::string& client,
                                                  nuraft::ptr< nuraft::rpc_client >& raft_client) {
    LOGDEBUGMOD(sds_msg, "Creating client to {}", client);
    auto endpoint = lookupEndpoint(client);
    if (endpoint.empty()) { return std::make_error_condition(std::errc::invalid_argument); }

    LOGDEBUGMOD(sds_msg, "Creating client for [{}] @ [{}]", client, endpoint);
    raft_client = sds::grpc::GrpcAsyncClient::make< messaging_client >(workerName(), endpoint);
    return (!raft_client) ? std::make_error_condition(std::errc::connection_aborted) : std::error_condition();
}

std::error_condition group_factory::reinit_client(const std::string& client,
                                                  sds::shared< nuraft::rpc_client >& raft_client) {
    LOGDEBUGMOD(sds_msg, "Re-init client to {}", client);
    assert(raft_client);
    auto mesg_client = std::dynamic_pointer_cast< messaging_client >(raft_client);
    if (!mesg_client->is_connection_ready() || 0 < mesg_client->bad_service.load(std::memory_order_relaxed)) {
        return create_client(client, raft_client);
    }
    return std::error_condition();
}

} // namespace sds::messaging
