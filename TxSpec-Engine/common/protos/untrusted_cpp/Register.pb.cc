// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Register.proto

#include "Register.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace request_proto {
constexpr RegisterRequest::RegisterRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : chaintype_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , chainid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct RegisterRequestDefaultTypeInternal {
  constexpr RegisterRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RegisterRequestDefaultTypeInternal() {}
  union {
    RegisterRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RegisterRequestDefaultTypeInternal _RegisterRequest_default_instance_;
constexpr RegisterResponse::RegisterResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : ias_attestation_report_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , enclave_pk_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , error_info_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct RegisterResponseDefaultTypeInternal {
  constexpr RegisterResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RegisterResponseDefaultTypeInternal() {}
  union {
    RegisterResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RegisterResponseDefaultTypeInternal _RegisterResponse_default_instance_;
}  // namespace request_proto
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Register_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Register_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Register_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Register_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterRequest, chaintype_),
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterRequest, chainid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterResponse, ias_attestation_report_),
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterResponse, enclave_pk_),
  PROTOBUF_FIELD_OFFSET(::request_proto::RegisterResponse, error_info_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::request_proto::RegisterRequest)},
  { 7, -1, sizeof(::request_proto::RegisterResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_RegisterRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_RegisterResponse_default_instance_),
};

const char descriptor_table_protodef_Register_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016Register.proto\022\rrequest_proto\"5\n\017Regis"
  "terRequest\022\021\n\tChainType\030\001 \001(\t\022\017\n\007ChainId"
  "\030\002 \001(\t\"Z\n\020RegisterResponse\022\036\n\026ias_attest"
  "ation_report\030\001 \001(\t\022\022\n\nenclave_pk\030\002 \001(\t\022\022"
  "\n\nerror_info\030\003 \001(\t2h\n\010Register\022\\\n\031Regist"
  "erRegulatoryService\022\036.request_proto.Regi"
  "sterRequest\032\037.request_proto.RegisterResp"
  "onseb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Register_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Register_2eproto = {
  false, false, 292, descriptor_table_protodef_Register_2eproto, "Register.proto", 
  &descriptor_table_Register_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_Register_2eproto::offsets,
  file_level_metadata_Register_2eproto, file_level_enum_descriptors_Register_2eproto, file_level_service_descriptors_Register_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_Register_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Register_2eproto);
  return descriptor_table_Register_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Register_2eproto(&descriptor_table_Register_2eproto);
namespace request_proto {

// ===================================================================

class RegisterRequest::_Internal {
 public:
};

RegisterRequest::RegisterRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.RegisterRequest)
}
RegisterRequest::RegisterRequest(const RegisterRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  chaintype_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_chaintype().empty()) {
    chaintype_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_chaintype(), 
      GetArena());
  }
  chainid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_chainid().empty()) {
    chainid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_chainid(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:request_proto.RegisterRequest)
}

void RegisterRequest::SharedCtor() {
chaintype_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
chainid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

RegisterRequest::~RegisterRequest() {
  // @@protoc_insertion_point(destructor:request_proto.RegisterRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RegisterRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  chaintype_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chainid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RegisterRequest::ArenaDtor(void* object) {
  RegisterRequest* _this = reinterpret_cast< RegisterRequest* >(object);
  (void)_this;
}
void RegisterRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RegisterRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RegisterRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.RegisterRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  chaintype_.ClearToEmpty();
  chainid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RegisterRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string ChainType = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_chaintype();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.RegisterRequest.ChainType"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string ChainId = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_chainid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.RegisterRequest.ChainId"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RegisterRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.RegisterRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string ChainType = 1;
  if (this->chaintype().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_chaintype().data(), static_cast<int>(this->_internal_chaintype().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.RegisterRequest.ChainType");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_chaintype(), target);
  }

  // string ChainId = 2;
  if (this->chainid().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_chainid().data(), static_cast<int>(this->_internal_chainid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.RegisterRequest.ChainId");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_chainid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.RegisterRequest)
  return target;
}

size_t RegisterRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.RegisterRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string ChainType = 1;
  if (this->chaintype().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chaintype());
  }

  // string ChainId = 2;
  if (this->chainid().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chainid());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RegisterRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.RegisterRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const RegisterRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RegisterRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.RegisterRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.RegisterRequest)
    MergeFrom(*source);
  }
}

void RegisterRequest::MergeFrom(const RegisterRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.RegisterRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.chaintype().size() > 0) {
    _internal_set_chaintype(from._internal_chaintype());
  }
  if (from.chainid().size() > 0) {
    _internal_set_chainid(from._internal_chainid());
  }
}

void RegisterRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.RegisterRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RegisterRequest::CopyFrom(const RegisterRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.RegisterRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RegisterRequest::IsInitialized() const {
  return true;
}

void RegisterRequest::InternalSwap(RegisterRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  chaintype_.Swap(&other->chaintype_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  chainid_.Swap(&other->chainid_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata RegisterRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class RegisterResponse::_Internal {
 public:
};

RegisterResponse::RegisterResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.RegisterResponse)
}
RegisterResponse::RegisterResponse(const RegisterResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ias_attestation_report_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_ias_attestation_report().empty()) {
    ias_attestation_report_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_ias_attestation_report(), 
      GetArena());
  }
  enclave_pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_enclave_pk().empty()) {
    enclave_pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_enclave_pk(), 
      GetArena());
  }
  error_info_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_error_info().empty()) {
    error_info_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_error_info(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:request_proto.RegisterResponse)
}

void RegisterResponse::SharedCtor() {
ias_attestation_report_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
enclave_pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
error_info_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

RegisterResponse::~RegisterResponse() {
  // @@protoc_insertion_point(destructor:request_proto.RegisterResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RegisterResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  ias_attestation_report_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  enclave_pk_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  error_info_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RegisterResponse::ArenaDtor(void* object) {
  RegisterResponse* _this = reinterpret_cast< RegisterResponse* >(object);
  (void)_this;
}
void RegisterResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RegisterResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RegisterResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.RegisterResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ias_attestation_report_.ClearToEmpty();
  enclave_pk_.ClearToEmpty();
  error_info_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RegisterResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string ias_attestation_report = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_ias_attestation_report();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.RegisterResponse.ias_attestation_report"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string enclave_pk = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_enclave_pk();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.RegisterResponse.enclave_pk"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string error_info = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_error_info();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.RegisterResponse.error_info"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RegisterResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.RegisterResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string ias_attestation_report = 1;
  if (this->ias_attestation_report().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_ias_attestation_report().data(), static_cast<int>(this->_internal_ias_attestation_report().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.RegisterResponse.ias_attestation_report");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_ias_attestation_report(), target);
  }

  // string enclave_pk = 2;
  if (this->enclave_pk().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_enclave_pk().data(), static_cast<int>(this->_internal_enclave_pk().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.RegisterResponse.enclave_pk");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_enclave_pk(), target);
  }

  // string error_info = 3;
  if (this->error_info().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_error_info().data(), static_cast<int>(this->_internal_error_info().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.RegisterResponse.error_info");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_error_info(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.RegisterResponse)
  return target;
}

size_t RegisterResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.RegisterResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string ias_attestation_report = 1;
  if (this->ias_attestation_report().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_ias_attestation_report());
  }

  // string enclave_pk = 2;
  if (this->enclave_pk().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_enclave_pk());
  }

  // string error_info = 3;
  if (this->error_info().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_error_info());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RegisterResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.RegisterResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const RegisterResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RegisterResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.RegisterResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.RegisterResponse)
    MergeFrom(*source);
  }
}

void RegisterResponse::MergeFrom(const RegisterResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.RegisterResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.ias_attestation_report().size() > 0) {
    _internal_set_ias_attestation_report(from._internal_ias_attestation_report());
  }
  if (from.enclave_pk().size() > 0) {
    _internal_set_enclave_pk(from._internal_enclave_pk());
  }
  if (from.error_info().size() > 0) {
    _internal_set_error_info(from._internal_error_info());
  }
}

void RegisterResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.RegisterResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RegisterResponse::CopyFrom(const RegisterResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.RegisterResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RegisterResponse::IsInitialized() const {
  return true;
}

void RegisterResponse::InternalSwap(RegisterResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ias_attestation_report_.Swap(&other->ias_attestation_report_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  enclave_pk_.Swap(&other->enclave_pk_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  error_info_.Swap(&other->error_info_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata RegisterResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::request_proto::RegisterRequest* Arena::CreateMaybeMessage< ::request_proto::RegisterRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::RegisterRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::request_proto::RegisterResponse* Arena::CreateMaybeMessage< ::request_proto::RegisterResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::RegisterResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
