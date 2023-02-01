// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_NURAFTMESGCONFIG_NURAFTMESGCFG_H_
#define FLATBUFFERS_GENERATED_NURAFTMESGCONFIG_NURAFTMESGCFG_H_

#include "flatbuffers/flatbuffers.h"

#include "sisl/utility/non_null_ptr.hpp"

namespace nuraftmesgcfg {

struct MesgFactoryConfig;
struct MesgFactoryConfigBuilder;
struct MesgFactoryConfigT;

struct NuraftMesgConfig;
struct NuraftMesgConfigBuilder;
struct NuraftMesgConfigT;

inline const flatbuffers::TypeTable *MesgFactoryConfigTypeTable();

inline const flatbuffers::TypeTable *NuraftMesgConfigTypeTable();

struct MesgFactoryConfigT : public flatbuffers::NativeTable {
  typedef MesgFactoryConfig TableType;
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nuraftmesgcfg.MesgFactoryConfigT";
  }
  uint16_t raft_request_deadline;
  uint16_t data_request_deadline;
  MesgFactoryConfigT()
      : raft_request_deadline(2),
        data_request_deadline(2) {
  }
};

struct MesgFactoryConfig FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MesgFactoryConfigT NativeTableType;
  typedef MesgFactoryConfigBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return MesgFactoryConfigTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nuraftmesgcfg.MesgFactoryConfig";
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_RAFT_REQUEST_DEADLINE = 4,
    VT_DATA_REQUEST_DEADLINE = 6
  };
  uint16_t raft_request_deadline() const {
    return GetField<uint16_t>(VT_RAFT_REQUEST_DEADLINE, 2);
  }
  bool mutate_raft_request_deadline(uint16_t _raft_request_deadline) {
    return SetField<uint16_t>(VT_RAFT_REQUEST_DEADLINE, _raft_request_deadline, 2);
  }
  uint16_t data_request_deadline() const {
    return GetField<uint16_t>(VT_DATA_REQUEST_DEADLINE, 2);
  }
  bool mutate_data_request_deadline(uint16_t _data_request_deadline) {
    return SetField<uint16_t>(VT_DATA_REQUEST_DEADLINE, _data_request_deadline, 2);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint16_t>(verifier, VT_RAFT_REQUEST_DEADLINE) &&
           VerifyField<uint16_t>(verifier, VT_DATA_REQUEST_DEADLINE) &&
           verifier.EndTable();
  }
  MesgFactoryConfigT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(MesgFactoryConfigT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<MesgFactoryConfig> Pack(flatbuffers::FlatBufferBuilder &_fbb, const MesgFactoryConfigT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct MesgFactoryConfigBuilder {
  typedef MesgFactoryConfig Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_raft_request_deadline(uint16_t raft_request_deadline) {
    fbb_.AddElement<uint16_t>(MesgFactoryConfig::VT_RAFT_REQUEST_DEADLINE, raft_request_deadline, 2);
  }
  void add_data_request_deadline(uint16_t data_request_deadline) {
    fbb_.AddElement<uint16_t>(MesgFactoryConfig::VT_DATA_REQUEST_DEADLINE, data_request_deadline, 2);
  }
  explicit MesgFactoryConfigBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MesgFactoryConfigBuilder &operator=(const MesgFactoryConfigBuilder &);
  flatbuffers::Offset<MesgFactoryConfig> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<MesgFactoryConfig>(end);
    return o;
  }
};

inline flatbuffers::Offset<MesgFactoryConfig> CreateMesgFactoryConfig(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint16_t raft_request_deadline = 2,
    uint16_t data_request_deadline = 2) {
  MesgFactoryConfigBuilder builder_(_fbb);
  builder_.add_data_request_deadline(data_request_deadline);
  builder_.add_raft_request_deadline(raft_request_deadline);
  return builder_.Finish();
}

flatbuffers::Offset<MesgFactoryConfig> CreateMesgFactoryConfig(flatbuffers::FlatBufferBuilder &_fbb, const MesgFactoryConfigT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct NuraftMesgConfigT : public flatbuffers::NativeTable {
  typedef NuraftMesgConfig TableType;
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nuraftmesgcfg.NuraftMesgConfigT";
  }
  sisl::embedded_t<nuraftmesgcfg::MesgFactoryConfigT> mesg_factory_config;
  NuraftMesgConfigT() {
  }
};

struct NuraftMesgConfig FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NuraftMesgConfigT NativeTableType;
  typedef NuraftMesgConfigBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return NuraftMesgConfigTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nuraftmesgcfg.NuraftMesgConfig";
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MESG_FACTORY_CONFIG = 4
  };
  const nuraftmesgcfg::MesgFactoryConfig *mesg_factory_config() const {
    return GetPointer<const nuraftmesgcfg::MesgFactoryConfig *>(VT_MESG_FACTORY_CONFIG);
  }
  nuraftmesgcfg::MesgFactoryConfig *mutable_mesg_factory_config() {
    return GetPointer<nuraftmesgcfg::MesgFactoryConfig *>(VT_MESG_FACTORY_CONFIG);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_MESG_FACTORY_CONFIG) &&
           verifier.VerifyTable(mesg_factory_config()) &&
           verifier.EndTable();
  }
  NuraftMesgConfigT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(NuraftMesgConfigT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<NuraftMesgConfig> Pack(flatbuffers::FlatBufferBuilder &_fbb, const NuraftMesgConfigT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct NuraftMesgConfigBuilder {
  typedef NuraftMesgConfig Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_mesg_factory_config(flatbuffers::Offset<nuraftmesgcfg::MesgFactoryConfig> mesg_factory_config) {
    fbb_.AddOffset(NuraftMesgConfig::VT_MESG_FACTORY_CONFIG, mesg_factory_config);
  }
  explicit NuraftMesgConfigBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NuraftMesgConfigBuilder &operator=(const NuraftMesgConfigBuilder &);
  flatbuffers::Offset<NuraftMesgConfig> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NuraftMesgConfig>(end);
    return o;
  }
};

inline flatbuffers::Offset<NuraftMesgConfig> CreateNuraftMesgConfig(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<nuraftmesgcfg::MesgFactoryConfig> mesg_factory_config = 0) {
  NuraftMesgConfigBuilder builder_(_fbb);
  builder_.add_mesg_factory_config(mesg_factory_config);
  return builder_.Finish();
}

flatbuffers::Offset<NuraftMesgConfig> CreateNuraftMesgConfig(flatbuffers::FlatBufferBuilder &_fbb, const NuraftMesgConfigT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline MesgFactoryConfigT *MesgFactoryConfig::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  sisl::embedded_t<nuraftmesgcfg::MesgFactoryConfigT> _o = sisl::embedded_t<nuraftmesgcfg::MesgFactoryConfigT>(new MesgFactoryConfigT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void MesgFactoryConfig::UnPackTo(MesgFactoryConfigT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = raft_request_deadline(); _o->raft_request_deadline = _e; }
  { auto _e = data_request_deadline(); _o->data_request_deadline = _e; }
}

inline flatbuffers::Offset<MesgFactoryConfig> MesgFactoryConfig::Pack(flatbuffers::FlatBufferBuilder &_fbb, const MesgFactoryConfigT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateMesgFactoryConfig(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<MesgFactoryConfig> CreateMesgFactoryConfig(flatbuffers::FlatBufferBuilder &_fbb, const MesgFactoryConfigT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const MesgFactoryConfigT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _raft_request_deadline = _o->raft_request_deadline;
  auto _data_request_deadline = _o->data_request_deadline;
  return nuraftmesgcfg::CreateMesgFactoryConfig(
      _fbb,
      _raft_request_deadline,
      _data_request_deadline);
}

inline NuraftMesgConfigT *NuraftMesgConfig::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT> _o = sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT>(new NuraftMesgConfigT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void NuraftMesgConfig::UnPackTo(NuraftMesgConfigT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = mesg_factory_config(); if (_e) _o->mesg_factory_config = sisl::embedded_t<nuraftmesgcfg::MesgFactoryConfigT>(_e->UnPack(_resolver)); }
}

inline flatbuffers::Offset<NuraftMesgConfig> NuraftMesgConfig::Pack(flatbuffers::FlatBufferBuilder &_fbb, const NuraftMesgConfigT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateNuraftMesgConfig(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<NuraftMesgConfig> CreateNuraftMesgConfig(flatbuffers::FlatBufferBuilder &_fbb, const NuraftMesgConfigT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const NuraftMesgConfigT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _mesg_factory_config = _o->mesg_factory_config ? CreateMesgFactoryConfig(_fbb, _o->mesg_factory_config.get(), _rehasher) : 0;
  return nuraftmesgcfg::CreateNuraftMesgConfig(
      _fbb,
      _mesg_factory_config);
}

inline const flatbuffers::TypeTable *MesgFactoryConfigTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_USHORT, 0, -1 },
    { flatbuffers::ET_USHORT, 0, -1 }
  };
  static const char * const names[] = {
    "raft_request_deadline",
    "data_request_deadline"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *NuraftMesgConfigTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    nuraftmesgcfg::MesgFactoryConfigTypeTable
  };
  static const char * const names[] = {
    "mesg_factory_config"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 1, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const nuraftmesgcfg::NuraftMesgConfig *GetNuraftMesgConfig(const void *buf) {
  return flatbuffers::GetRoot<nuraftmesgcfg::NuraftMesgConfig>(buf);
}

inline const nuraftmesgcfg::NuraftMesgConfig *GetSizePrefixedNuraftMesgConfig(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<nuraftmesgcfg::NuraftMesgConfig>(buf);
}

inline NuraftMesgConfig *GetMutableNuraftMesgConfig(void *buf) {
  return flatbuffers::GetMutableRoot<NuraftMesgConfig>(buf);
}

inline bool VerifyNuraftMesgConfigBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<nuraftmesgcfg::NuraftMesgConfig>(nullptr);
}

inline bool VerifySizePrefixedNuraftMesgConfigBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<nuraftmesgcfg::NuraftMesgConfig>(nullptr);
}

inline void FinishNuraftMesgConfigBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<nuraftmesgcfg::NuraftMesgConfig> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedNuraftMesgConfigBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<nuraftmesgcfg::NuraftMesgConfig> root) {
  fbb.FinishSizePrefixed(root);
}

inline sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT> UnPackNuraftMesgConfig(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT>(GetNuraftMesgConfig(buf)->UnPack(res));
}

inline sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT> UnPackSizePrefixedNuraftMesgConfig(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return sisl::embedded_t<nuraftmesgcfg::NuraftMesgConfigT>(GetSizePrefixedNuraftMesgConfig(buf)->UnPack(res));
}

}  // namespace nuraftmesgcfg

#endif  // FLATBUFFERS_GENERATED_NURAFTMESGCONFIG_NURAFTMESGCFG_H_
