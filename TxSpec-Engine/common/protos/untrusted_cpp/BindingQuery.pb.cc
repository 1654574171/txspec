// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BindingQuery.proto

#include "BindingQuery.pb.h"

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
constexpr BindingQueryItem::BindingQueryItem(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : contractid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , contractbinding_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct BindingQueryItemDefaultTypeInternal {
  constexpr BindingQueryItemDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BindingQueryItemDefaultTypeInternal() {}
  union {
    BindingQueryItem _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BindingQueryItemDefaultTypeInternal _BindingQueryItem_default_instance_;
constexpr BindingQueryMessage::BindingQueryMessage(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : items_(){}
struct BindingQueryMessageDefaultTypeInternal {
  constexpr BindingQueryMessageDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BindingQueryMessageDefaultTypeInternal() {}
  union {
    BindingQueryMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BindingQueryMessageDefaultTypeInternal _BindingQueryMessage_default_instance_;
}  // namespace request_proto
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_BindingQuery_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_BindingQuery_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_BindingQuery_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_BindingQuery_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::BindingQueryItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::BindingQueryItem, contractid_),
  PROTOBUF_FIELD_OFFSET(::request_proto::BindingQueryItem, contractbinding_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::BindingQueryMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::BindingQueryMessage, items_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::request_proto::BindingQueryItem)},
  { 7, -1, sizeof(::request_proto::BindingQueryMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_BindingQueryItem_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_BindingQueryMessage_default_instance_),
};

const char descriptor_table_protodef_BindingQuery_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022BindingQuery.proto\022\rrequest_proto\"\?\n\020B"
  "indingQueryItem\022\022\n\ncontractID\030\001 \001(\t\022\027\n\017c"
  "ontractBinding\030\002 \001(\t\"E\n\023BindingQueryMess"
  "age\022.\n\005items\030\001 \003(\0132\037.request_proto.Bindi"
  "ngQueryItemb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_BindingQuery_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_BindingQuery_2eproto = {
  false, false, 179, descriptor_table_protodef_BindingQuery_2eproto, "BindingQuery.proto", 
  &descriptor_table_BindingQuery_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_BindingQuery_2eproto::offsets,
  file_level_metadata_BindingQuery_2eproto, file_level_enum_descriptors_BindingQuery_2eproto, file_level_service_descriptors_BindingQuery_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_BindingQuery_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_BindingQuery_2eproto);
  return descriptor_table_BindingQuery_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_BindingQuery_2eproto(&descriptor_table_BindingQuery_2eproto);
namespace request_proto {

// ===================================================================

class BindingQueryItem::_Internal {
 public:
};

BindingQueryItem::BindingQueryItem(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.BindingQueryItem)
}
BindingQueryItem::BindingQueryItem(const BindingQueryItem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  contractid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_contractid().empty()) {
    contractid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_contractid(), 
      GetArena());
  }
  contractbinding_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_contractbinding().empty()) {
    contractbinding_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_contractbinding(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:request_proto.BindingQueryItem)
}

void BindingQueryItem::SharedCtor() {
contractid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
contractbinding_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

BindingQueryItem::~BindingQueryItem() {
  // @@protoc_insertion_point(destructor:request_proto.BindingQueryItem)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BindingQueryItem::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  contractid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  contractbinding_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void BindingQueryItem::ArenaDtor(void* object) {
  BindingQueryItem* _this = reinterpret_cast< BindingQueryItem* >(object);
  (void)_this;
}
void BindingQueryItem::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BindingQueryItem::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BindingQueryItem::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.BindingQueryItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  contractid_.ClearToEmpty();
  contractbinding_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BindingQueryItem::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string contractID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_contractid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.BindingQueryItem.contractID"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string contractBinding = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_contractbinding();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.BindingQueryItem.contractBinding"));
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

::PROTOBUF_NAMESPACE_ID::uint8* BindingQueryItem::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.BindingQueryItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string contractID = 1;
  if (this->contractid().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_contractid().data(), static_cast<int>(this->_internal_contractid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.BindingQueryItem.contractID");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_contractid(), target);
  }

  // string contractBinding = 2;
  if (this->contractbinding().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_contractbinding().data(), static_cast<int>(this->_internal_contractbinding().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.BindingQueryItem.contractBinding");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_contractbinding(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.BindingQueryItem)
  return target;
}

size_t BindingQueryItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.BindingQueryItem)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string contractID = 1;
  if (this->contractid().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_contractid());
  }

  // string contractBinding = 2;
  if (this->contractbinding().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_contractbinding());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BindingQueryItem::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.BindingQueryItem)
  GOOGLE_DCHECK_NE(&from, this);
  const BindingQueryItem* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BindingQueryItem>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.BindingQueryItem)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.BindingQueryItem)
    MergeFrom(*source);
  }
}

void BindingQueryItem::MergeFrom(const BindingQueryItem& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.BindingQueryItem)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.contractid().size() > 0) {
    _internal_set_contractid(from._internal_contractid());
  }
  if (from.contractbinding().size() > 0) {
    _internal_set_contractbinding(from._internal_contractbinding());
  }
}

void BindingQueryItem::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.BindingQueryItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BindingQueryItem::CopyFrom(const BindingQueryItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.BindingQueryItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BindingQueryItem::IsInitialized() const {
  return true;
}

void BindingQueryItem::InternalSwap(BindingQueryItem* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  contractid_.Swap(&other->contractid_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  contractbinding_.Swap(&other->contractbinding_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata BindingQueryItem::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class BindingQueryMessage::_Internal {
 public:
};

BindingQueryMessage::BindingQueryMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  items_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.BindingQueryMessage)
}
BindingQueryMessage::BindingQueryMessage(const BindingQueryMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      items_(from.items_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:request_proto.BindingQueryMessage)
}

void BindingQueryMessage::SharedCtor() {
}

BindingQueryMessage::~BindingQueryMessage() {
  // @@protoc_insertion_point(destructor:request_proto.BindingQueryMessage)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BindingQueryMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BindingQueryMessage::ArenaDtor(void* object) {
  BindingQueryMessage* _this = reinterpret_cast< BindingQueryMessage* >(object);
  (void)_this;
}
void BindingQueryMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BindingQueryMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BindingQueryMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.BindingQueryMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  items_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BindingQueryMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .request_proto.BindingQueryItem items = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_items(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* BindingQueryMessage::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.BindingQueryMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .request_proto.BindingQueryItem items = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_items_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_items(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.BindingQueryMessage)
  return target;
}

size_t BindingQueryMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.BindingQueryMessage)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .request_proto.BindingQueryItem items = 1;
  total_size += 1UL * this->_internal_items_size();
  for (const auto& msg : this->items_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BindingQueryMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.BindingQueryMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const BindingQueryMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BindingQueryMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.BindingQueryMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.BindingQueryMessage)
    MergeFrom(*source);
  }
}

void BindingQueryMessage::MergeFrom(const BindingQueryMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.BindingQueryMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  items_.MergeFrom(from.items_);
}

void BindingQueryMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.BindingQueryMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BindingQueryMessage::CopyFrom(const BindingQueryMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.BindingQueryMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BindingQueryMessage::IsInitialized() const {
  return true;
}

void BindingQueryMessage::InternalSwap(BindingQueryMessage* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  items_.InternalSwap(&other->items_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BindingQueryMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::request_proto::BindingQueryItem* Arena::CreateMaybeMessage< ::request_proto::BindingQueryItem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::BindingQueryItem >(arena);
}
template<> PROTOBUF_NOINLINE ::request_proto::BindingQueryMessage* Arena::CreateMaybeMessage< ::request_proto::BindingQueryMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::BindingQueryMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
