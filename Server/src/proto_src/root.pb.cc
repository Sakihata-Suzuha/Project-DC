// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: root.proto

#include "root.pb.h"

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
class rootDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<root> _instance;
} _root_default_instance_;
static void InitDefaultsscc_info_root_root_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_root_default_instance_;
    new (ptr) ::root();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::root::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_root_root_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_root_root_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_root_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_root_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_root_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_root_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::root, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::root, _type_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::root)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_root_default_instance_),
};

const char descriptor_table_protodef_root_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nroot.proto\"k\n\004root\022\037\n\005_type\030\001 \001(\0162\020.ro"
  "ot.AccessType\"B\n\nAccessType\022\t\n\005blank\020\000\022\n"
  "\n\005login\020\351\007\022\013\n\006logout\020\352\007\022\020\n\013textMessage\020\321"
  "\017b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_root_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_root_2eproto_sccs[1] = {
  &scc_info_root_root_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_root_2eproto_once;
static bool descriptor_table_root_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_root_2eproto = {
  &descriptor_table_root_2eproto_initialized, descriptor_table_protodef_root_2eproto, "root.proto", 129,
  &descriptor_table_root_2eproto_once, descriptor_table_root_2eproto_sccs, descriptor_table_root_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_root_2eproto::offsets,
  file_level_metadata_root_2eproto, 1, file_level_enum_descriptors_root_2eproto, file_level_service_descriptors_root_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_root_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_root_2eproto), true);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* root_AccessType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_root_2eproto);
  return file_level_enum_descriptors_root_2eproto[0];
}
bool root_AccessType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1001:
    case 1002:
    case 2001:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr root_AccessType root::blank;
constexpr root_AccessType root::login;
constexpr root_AccessType root::logout;
constexpr root_AccessType root::textMessage;
constexpr root_AccessType root::AccessType_MIN;
constexpr root_AccessType root::AccessType_MAX;
constexpr int root::AccessType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void root::InitAsDefaultInstance() {
}
class root::_Internal {
 public:
};

root::root()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:root)
}
root::root(const root& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  _type_ = from._type_;
  // @@protoc_insertion_point(copy_constructor:root)
}

void root::SharedCtor() {
  _type_ = 0;
}

root::~root() {
  // @@protoc_insertion_point(destructor:root)
  SharedDtor();
}

void root::SharedDtor() {
}

void root::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const root& root::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_root_root_2eproto.base);
  return *internal_default_instance();
}


void root::Clear() {
// @@protoc_insertion_point(message_clear_start:root)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _type_ = 0;
  _internal_metadata_.Clear();
}

const char* root::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .root.AccessType _type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set__type(static_cast<::root_AccessType>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* root::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:root)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .root.AccessType _type = 1;
  if (this->_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal__type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:root)
  return target;
}

size_t root::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:root)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .root.AccessType _type = 1;
  if (this->_type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal__type());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void root::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:root)
  GOOGLE_DCHECK_NE(&from, this);
  const root* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<root>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:root)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:root)
    MergeFrom(*source);
  }
}

void root::MergeFrom(const root& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:root)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._type() != 0) {
    _internal_set__type(from._internal__type());
  }
}

void root::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:root)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void root::CopyFrom(const root& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:root)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool root::IsInitialized() const {
  return true;
}

void root::InternalSwap(root* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_type_, other->_type_);
}

::PROTOBUF_NAMESPACE_ID::Metadata root::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::root* Arena::CreateMaybeMessage< ::root >(Arena* arena) {
  return Arena::CreateInternal< ::root >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>