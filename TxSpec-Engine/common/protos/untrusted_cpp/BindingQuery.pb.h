// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BindingQuery.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_BindingQuery_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_BindingQuery_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_BindingQuery_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_BindingQuery_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_BindingQuery_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_BindingQuery_2eproto_metadata_getter(int index);
namespace request_proto {
class BindingQueryItem;
struct BindingQueryItemDefaultTypeInternal;
extern BindingQueryItemDefaultTypeInternal _BindingQueryItem_default_instance_;
class BindingQueryMessage;
struct BindingQueryMessageDefaultTypeInternal;
extern BindingQueryMessageDefaultTypeInternal _BindingQueryMessage_default_instance_;
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
template<> ::request_proto::BindingQueryItem* Arena::CreateMaybeMessage<::request_proto::BindingQueryItem>(Arena*);
template<> ::request_proto::BindingQueryMessage* Arena::CreateMaybeMessage<::request_proto::BindingQueryMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace request_proto {

// ===================================================================

class BindingQueryItem PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request_proto.BindingQueryItem) */ {
 public:
  inline BindingQueryItem() : BindingQueryItem(nullptr) {}
  virtual ~BindingQueryItem();
  explicit constexpr BindingQueryItem(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BindingQueryItem(const BindingQueryItem& from);
  BindingQueryItem(BindingQueryItem&& from) noexcept
    : BindingQueryItem() {
    *this = ::std::move(from);
  }

  inline BindingQueryItem& operator=(const BindingQueryItem& from) {
    CopyFrom(from);
    return *this;
  }
  inline BindingQueryItem& operator=(BindingQueryItem&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BindingQueryItem& default_instance() {
    return *internal_default_instance();
  }
  static inline const BindingQueryItem* internal_default_instance() {
    return reinterpret_cast<const BindingQueryItem*>(
               &_BindingQueryItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BindingQueryItem& a, BindingQueryItem& b) {
    a.Swap(&b);
  }
  inline void Swap(BindingQueryItem* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BindingQueryItem* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BindingQueryItem* New() const final {
    return CreateMaybeMessage<BindingQueryItem>(nullptr);
  }

  BindingQueryItem* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BindingQueryItem>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BindingQueryItem& from);
  void MergeFrom(const BindingQueryItem& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BindingQueryItem* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request_proto.BindingQueryItem";
  }
  protected:
  explicit BindingQueryItem(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_BindingQuery_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kContractIDFieldNumber = 1,
    kContractBindingFieldNumber = 2,
  };
  // string contractID = 1;
  void clear_contractid();
  const std::string& contractid() const;
  void set_contractid(const std::string& value);
  void set_contractid(std::string&& value);
  void set_contractid(const char* value);
  void set_contractid(const char* value, size_t size);
  std::string* mutable_contractid();
  std::string* release_contractid();
  void set_allocated_contractid(std::string* contractid);
  private:
  const std::string& _internal_contractid() const;
  void _internal_set_contractid(const std::string& value);
  std::string* _internal_mutable_contractid();
  public:

  // string contractBinding = 2;
  void clear_contractbinding();
  const std::string& contractbinding() const;
  void set_contractbinding(const std::string& value);
  void set_contractbinding(std::string&& value);
  void set_contractbinding(const char* value);
  void set_contractbinding(const char* value, size_t size);
  std::string* mutable_contractbinding();
  std::string* release_contractbinding();
  void set_allocated_contractbinding(std::string* contractbinding);
  private:
  const std::string& _internal_contractbinding() const;
  void _internal_set_contractbinding(const std::string& value);
  std::string* _internal_mutable_contractbinding();
  public:

  // @@protoc_insertion_point(class_scope:request_proto.BindingQueryItem)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr contractid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr contractbinding_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BindingQuery_2eproto;
};
// -------------------------------------------------------------------

class BindingQueryMessage PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request_proto.BindingQueryMessage) */ {
 public:
  inline BindingQueryMessage() : BindingQueryMessage(nullptr) {}
  virtual ~BindingQueryMessage();
  explicit constexpr BindingQueryMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BindingQueryMessage(const BindingQueryMessage& from);
  BindingQueryMessage(BindingQueryMessage&& from) noexcept
    : BindingQueryMessage() {
    *this = ::std::move(from);
  }

  inline BindingQueryMessage& operator=(const BindingQueryMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline BindingQueryMessage& operator=(BindingQueryMessage&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BindingQueryMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const BindingQueryMessage* internal_default_instance() {
    return reinterpret_cast<const BindingQueryMessage*>(
               &_BindingQueryMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(BindingQueryMessage& a, BindingQueryMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(BindingQueryMessage* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BindingQueryMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BindingQueryMessage* New() const final {
    return CreateMaybeMessage<BindingQueryMessage>(nullptr);
  }

  BindingQueryMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BindingQueryMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BindingQueryMessage& from);
  void MergeFrom(const BindingQueryMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BindingQueryMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request_proto.BindingQueryMessage";
  }
  protected:
  explicit BindingQueryMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_BindingQuery_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kItemsFieldNumber = 1,
  };
  // repeated .request_proto.BindingQueryItem items = 1;
  int items_size() const;
  private:
  int _internal_items_size() const;
  public:
  void clear_items();
  ::request_proto::BindingQueryItem* mutable_items(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request_proto::BindingQueryItem >*
      mutable_items();
  private:
  const ::request_proto::BindingQueryItem& _internal_items(int index) const;
  ::request_proto::BindingQueryItem* _internal_add_items();
  public:
  const ::request_proto::BindingQueryItem& items(int index) const;
  ::request_proto::BindingQueryItem* add_items();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request_proto::BindingQueryItem >&
      items() const;

  // @@protoc_insertion_point(class_scope:request_proto.BindingQueryMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request_proto::BindingQueryItem > items_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BindingQuery_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BindingQueryItem

// string contractID = 1;
inline void BindingQueryItem::clear_contractid() {
  contractid_.ClearToEmpty();
}
inline const std::string& BindingQueryItem::contractid() const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryItem.contractID)
  return _internal_contractid();
}
inline void BindingQueryItem::set_contractid(const std::string& value) {
  _internal_set_contractid(value);
  // @@protoc_insertion_point(field_set:request_proto.BindingQueryItem.contractID)
}
inline std::string* BindingQueryItem::mutable_contractid() {
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryItem.contractID)
  return _internal_mutable_contractid();
}
inline const std::string& BindingQueryItem::_internal_contractid() const {
  return contractid_.Get();
}
inline void BindingQueryItem::_internal_set_contractid(const std::string& value) {
  
  contractid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void BindingQueryItem::set_contractid(std::string&& value) {
  
  contractid_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.BindingQueryItem.contractID)
}
inline void BindingQueryItem::set_contractid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  contractid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.BindingQueryItem.contractID)
}
inline void BindingQueryItem::set_contractid(const char* value,
    size_t size) {
  
  contractid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.BindingQueryItem.contractID)
}
inline std::string* BindingQueryItem::_internal_mutable_contractid() {
  
  return contractid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* BindingQueryItem::release_contractid() {
  // @@protoc_insertion_point(field_release:request_proto.BindingQueryItem.contractID)
  return contractid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void BindingQueryItem::set_allocated_contractid(std::string* contractid) {
  if (contractid != nullptr) {
    
  } else {
    
  }
  contractid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), contractid,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.BindingQueryItem.contractID)
}

// string contractBinding = 2;
inline void BindingQueryItem::clear_contractbinding() {
  contractbinding_.ClearToEmpty();
}
inline const std::string& BindingQueryItem::contractbinding() const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryItem.contractBinding)
  return _internal_contractbinding();
}
inline void BindingQueryItem::set_contractbinding(const std::string& value) {
  _internal_set_contractbinding(value);
  // @@protoc_insertion_point(field_set:request_proto.BindingQueryItem.contractBinding)
}
inline std::string* BindingQueryItem::mutable_contractbinding() {
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryItem.contractBinding)
  return _internal_mutable_contractbinding();
}
inline const std::string& BindingQueryItem::_internal_contractbinding() const {
  return contractbinding_.Get();
}
inline void BindingQueryItem::_internal_set_contractbinding(const std::string& value) {
  
  contractbinding_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void BindingQueryItem::set_contractbinding(std::string&& value) {
  
  contractbinding_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.BindingQueryItem.contractBinding)
}
inline void BindingQueryItem::set_contractbinding(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  contractbinding_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.BindingQueryItem.contractBinding)
}
inline void BindingQueryItem::set_contractbinding(const char* value,
    size_t size) {
  
  contractbinding_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.BindingQueryItem.contractBinding)
}
inline std::string* BindingQueryItem::_internal_mutable_contractbinding() {
  
  return contractbinding_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* BindingQueryItem::release_contractbinding() {
  // @@protoc_insertion_point(field_release:request_proto.BindingQueryItem.contractBinding)
  return contractbinding_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void BindingQueryItem::set_allocated_contractbinding(std::string* contractbinding) {
  if (contractbinding != nullptr) {
    
  } else {
    
  }
  contractbinding_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), contractbinding,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.BindingQueryItem.contractBinding)
}

// -------------------------------------------------------------------

// BindingQueryMessage

// repeated .request_proto.BindingQueryItem items = 1;
inline int BindingQueryMessage::_internal_items_size() const {
  return items_.size();
}
inline int BindingQueryMessage::items_size() const {
  return _internal_items_size();
}
inline void BindingQueryMessage::clear_items() {
  items_.Clear();
}
inline ::request_proto::BindingQueryItem* BindingQueryMessage::mutable_items(int index) {
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryMessage.items)
  return items_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request_proto::BindingQueryItem >*
BindingQueryMessage::mutable_items() {
  // @@protoc_insertion_point(field_mutable_list:request_proto.BindingQueryMessage.items)
  return &items_;
}
inline const ::request_proto::BindingQueryItem& BindingQueryMessage::_internal_items(int index) const {
  return items_.Get(index);
}
inline const ::request_proto::BindingQueryItem& BindingQueryMessage::items(int index) const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryMessage.items)
  return _internal_items(index);
}
inline ::request_proto::BindingQueryItem* BindingQueryMessage::_internal_add_items() {
  return items_.Add();
}
inline ::request_proto::BindingQueryItem* BindingQueryMessage::add_items() {
  // @@protoc_insertion_point(field_add:request_proto.BindingQueryMessage.items)
  return _internal_add_items();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::request_proto::BindingQueryItem >&
BindingQueryMessage::items() const {
  // @@protoc_insertion_point(field_list:request_proto.BindingQueryMessage.items)
  return items_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace request_proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_BindingQuery_2eproto
