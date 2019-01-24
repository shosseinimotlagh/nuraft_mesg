///
// Copyright 2018 (c) eBay Corporation
//
// Authors:
//      Brian Szmyd <bszmyd@ebay.com>
//

#pragma once

#include <sds_logging/logging.h>

SDS_LOGGING_DECL(raft_core)

struct sds_logger : ::cornerstone::logger {
    void debug(const std::string& log_line) override {
        LOGDEBUGMOD(raft_core, "{}", log_line);
    }

    void info(const std::string& log_line) override {
        LOGINFOMOD(raft_core, "{}", log_line);
    }

    void warn(const std::string& log_line) override {
        LOGWARNMOD(raft_core, "{}", log_line);
    }

    void err(const std::string& log_line) override {
       LOGERRORMOD(raft_core, "{}", log_line);
    }

    void set_level(int l) override {
        LOGINFOMOD(raft_core, "Updating level to: {}", l);
        SDS_LOG_LEVEL(raft_core, static_cast<spdlog::level::level_enum>(abs(l - 6)));
    }

    void put_details(int level,
                     const char* source_file,
                     const char* func_name,
                     size_t line_number,
                     const std::string& log_line) override {
        switch(level) {
        case 1: { LOGCRITICALMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        case 2: { LOGERRORMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        case 3: { LOGWARNMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        case 4: { LOGINFOMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        case 5: { LOGDEBUGMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        default: { LOGTRACEMOD(raft_core, "{}:{}#{} : {}", file_name(source_file), func_name, line_number, log_line); } break;;
        }
    }
};

