// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Regulator.proto

#include "Regulator.pb.h"

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
}  // namespace request_proto
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_Regulator_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Regulator_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Regulator_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Regulator_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_Regulator_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017Regulator.proto\022\rrequest_proto\032\022ProofR"
  "equest.proto\032\023ProofResponse.proto2b\n\tReg"
  "ulator\022U\n\022GetComplianceProof\022\033.request_p"
  "roto.ProofRequest\032\034.request_proto.ProofR"
  "esponse\"\000(\0010\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Regulator_2eproto_deps[2] = {
  &::descriptor_table_ProofRequest_2eproto,
  &::descriptor_table_ProofResponse_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Regulator_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Regulator_2eproto = {
  false, false, 181, descriptor_table_protodef_Regulator_2eproto, "Regulator.proto", 
  &descriptor_table_Regulator_2eproto_once, descriptor_table_Regulator_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_Regulator_2eproto::offsets,
  file_level_metadata_Regulator_2eproto, file_level_enum_descriptors_Regulator_2eproto, file_level_service_descriptors_Regulator_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_Regulator_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Regulator_2eproto);
  return descriptor_table_Regulator_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Regulator_2eproto(&descriptor_table_Regulator_2eproto);
namespace request_proto {

// @@protoc_insertion_point(namespace_scope)
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
