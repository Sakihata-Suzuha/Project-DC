// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transeTest.proto

#include "transeTest.pb.h"

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
namespace transeTest {
class testBody_bDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<testBody_b> _instance;
} _testBody_b_default_instance_;
}  // namespace transeTest
static void InitDefaultsscc_info_testBody_b_transeTest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::transeTest::_testBody_b_default_instance_;
    new (ptr) ::transeTest::testBody_b();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::transeTest::testBody_b::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_testBody_b_transeTest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_testBody_b_transeTest_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_transeTest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_transeTest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_transeTest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_transeTest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::transeTest::testBody_b, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::transeTest::testBody_b, id_),
  PROTOBUF_FIELD_OFFSET(::transeTest::testBody_b, double_test_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::transeTest::testBody_b)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::transeTest::_testBody_b_default_instance_),
};

const char descriptor_table_protodef_transeTest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020transeTest.proto\022\ntranseTest\"-\n\ntestBo"
  "dy_b\022\n\n\002id\030\001 \001(\r\022\023\n\013double_test\030\002 \001(\001b\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_transeTest_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_transeTest_2eproto_sccs[1] = {
  &scc_info_testBody_b_transeTest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_transeTest_2eproto_once;
static bool descriptor_table_transeTest_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transeTest_2eproto = {
  &descriptor_table_transeTest_2eproto_initialized, descriptor_table_protodef_transeTest_2eproto, "transeTest.proto", 85,
  &descriptor_table_transeTest_2eproto_once, descriptor_table_transeTest_2eproto_sccs, descriptor_table_transeTest_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_transeTest_2eproto::offsets,
  file_level_metadata_transeTest_2eproto, 1, file_level_enum_descriptors_transeTest_2eproto, file_level_service_descriptors_transeTest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_transeTest_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_transeTest_2eproto), true);
namespace transeTest {

// ===================================================================

void testBody_b::InitAsDefaultInstance() {
}
class testBody_b::_Internal {
 public:
};

testBody_b::testBody_b()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:transeTest.testBody_b)
}
testBody_b::testBody_b(const testBody_b& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&double_test_, &from.double_test_,
    static_cast<size_t>(reinterpret_cast<char*>(&id_) -
    reinterpret_cast<char*>(&double_test_)) + sizeof(id_));
  // @@protoc_insertion_point(copy_constructor:transeTest.testBody_b)
}

void testBody_b::SharedCtor() {
  ::memset(&double_test_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&id_) -
      reinterpret_cast<char*>(&double_test_)) + sizeof(id_));
}

testBody_b::~testBody_b() {
  // @@protoc_insertion_point(destructor:transeTest.testBody_b)
  SharedDtor();
}

void testBody_b::SharedDtor() {
}

void testBody_b::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const testBody_b& testBody_b::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_testBody_b_transeTest_2eproto.base);
  return *internal_default_instance();
}


void testBody_b::Clear() {
// @@protoc_insertion_point(message_clear_start:transeTest.testBody_b)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&double_test_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&id_) -
      reinterpret_cast<char*>(&double_test_)) + sizeof(id_));
  _internal_metadata_.Clear();
}

const char* testBody_b::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double double_test = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          double_test_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
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

::PROTOBUF_NAMESPACE_ID::uint8* testBody_b::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:transeTest.testBody_b)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // double double_test = 2;
  if (!(this->double_test() <= 0 && this->double_test() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_double_test(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:transeTest.testBody_b)
  return target;
}

size_t testBody_b::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:transeTest.testBody_b)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double double_test = 2;
  if (!(this->double_test() <= 0 && this->double_test() >= 0)) {
    total_size += 1 + 8;
  }

  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void testBody_b::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:transeTest.testBody_b)
  GOOGLE_DCHECK_NE(&from, this);
  const testBody_b* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<testBody_b>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:transeTest.testBody_b)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:transeTest.testBody_b)
    MergeFrom(*source);
  }
}

void testBody_b::MergeFrom(const testBody_b& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:transeTest.testBody_b)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.double_test() <= 0 && from.double_test() >= 0)) {
    _internal_set_double_test(from._internal_double_test());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
}

void testBody_b::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:transeTest.testBody_b)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void testBody_b::CopyFrom(const testBody_b& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:transeTest.testBody_b)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool testBody_b::IsInitialized() const {
  return true;
}

void testBody_b::InternalSwap(testBody_b* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(double_test_, other->double_test_);
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata testBody_b::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace transeTest
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::transeTest::testBody_b* Arena::CreateMaybeMessage< ::transeTest::testBody_b >(Arena* arena) {
  return Arena::CreateInternal< ::transeTest::testBody_b >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
