// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CancelOrderRequest.proto

#include "CancelOrderRequest.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_OrderCancel_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_OrderCancel_OrderCancel_2eproto;
namespace protobuf {
class CancelOrderRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CancelOrderRequest> _instance;
} _CancelOrderRequest_default_instance_;
}  // namespace protobuf
static void InitDefaultsscc_info_CancelOrderRequest_CancelOrderRequest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf::_CancelOrderRequest_default_instance_;
    new (ptr) ::protobuf::CancelOrderRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf::CancelOrderRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_CancelOrderRequest_CancelOrderRequest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_CancelOrderRequest_CancelOrderRequest_2eproto}, {
      &scc_info_OrderCancel_OrderCancel_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_CancelOrderRequest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_CancelOrderRequest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_CancelOrderRequest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_CancelOrderRequest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protobuf::CancelOrderRequest, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::protobuf::CancelOrderRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protobuf::CancelOrderRequest, orderid_),
  PROTOBUF_FIELD_OFFSET(::protobuf::CancelOrderRequest, ordercancel_),
  1,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::protobuf::CancelOrderRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protobuf::_CancelOrderRequest_default_instance_),
};

const char descriptor_table_protodef_CancelOrderRequest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030CancelOrderRequest.proto\022\010protobuf\032\021Or"
  "derCancel.proto\"w\n\022CancelOrderRequest\022\024\n"
  "\007orderId\030\001 \001(\005H\000\210\001\001\022/\n\013orderCancel\030\002 \001(\013"
  "2\025.protobuf.OrderCancelH\001\210\001\001B\n\n\010_orderId"
  "B\016\n\014_orderCancelBB\n\026com.ib.client.protob"
  "ufB\027CancelOrderRequestProto\252\002\016IBApi.prot"
  "obufb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_CancelOrderRequest_2eproto_deps[1] = {
  &::descriptor_table_OrderCancel_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_CancelOrderRequest_2eproto_sccs[1] = {
  &scc_info_CancelOrderRequest_CancelOrderRequest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_CancelOrderRequest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CancelOrderRequest_2eproto = {
  false, false, descriptor_table_protodef_CancelOrderRequest_2eproto, "CancelOrderRequest.proto", 252,
  &descriptor_table_CancelOrderRequest_2eproto_once, descriptor_table_CancelOrderRequest_2eproto_sccs, descriptor_table_CancelOrderRequest_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_CancelOrderRequest_2eproto::offsets,
  file_level_metadata_CancelOrderRequest_2eproto, 1, file_level_enum_descriptors_CancelOrderRequest_2eproto, file_level_service_descriptors_CancelOrderRequest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_CancelOrderRequest_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_CancelOrderRequest_2eproto)), true);
namespace protobuf {

// ===================================================================

void CancelOrderRequest::InitAsDefaultInstance() {
  ::protobuf::_CancelOrderRequest_default_instance_._instance.get_mutable()->ordercancel_ = const_cast< ::protobuf::OrderCancel*>(
      ::protobuf::OrderCancel::internal_default_instance());
}
class CancelOrderRequest::_Internal {
 public:
  using HasBits = decltype(std::declval<CancelOrderRequest>()._has_bits_);
  static void set_has_orderid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static const ::protobuf::OrderCancel& ordercancel(const CancelOrderRequest* msg);
  static void set_has_ordercancel(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::protobuf::OrderCancel&
CancelOrderRequest::_Internal::ordercancel(const CancelOrderRequest* msg) {
  return *msg->ordercancel_;
}
void CancelOrderRequest::clear_ordercancel() {
  if (GetArena() == nullptr && ordercancel_ != nullptr) {
    delete ordercancel_;
  }
  ordercancel_ = nullptr;
  _has_bits_[0] &= ~0x00000001u;
}
CancelOrderRequest::CancelOrderRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protobuf.CancelOrderRequest)
}
CancelOrderRequest::CancelOrderRequest(const CancelOrderRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_ordercancel()) {
    ordercancel_ = new ::protobuf::OrderCancel(*from.ordercancel_);
  } else {
    ordercancel_ = nullptr;
  }
  orderid_ = from.orderid_;
  // @@protoc_insertion_point(copy_constructor:protobuf.CancelOrderRequest)
}

void CancelOrderRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CancelOrderRequest_CancelOrderRequest_2eproto.base);
  ::memset(&ordercancel_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&orderid_) -
      reinterpret_cast<char*>(&ordercancel_)) + sizeof(orderid_));
}

CancelOrderRequest::~CancelOrderRequest() {
  // @@protoc_insertion_point(destructor:protobuf.CancelOrderRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void CancelOrderRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete ordercancel_;
}

void CancelOrderRequest::ArenaDtor(void* object) {
  CancelOrderRequest* _this = reinterpret_cast< CancelOrderRequest* >(object);
  (void)_this;
}
void CancelOrderRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CancelOrderRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CancelOrderRequest& CancelOrderRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CancelOrderRequest_CancelOrderRequest_2eproto.base);
  return *internal_default_instance();
}


void CancelOrderRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf.CancelOrderRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    if (GetArena() == nullptr && ordercancel_ != nullptr) {
      delete ordercancel_;
    }
    ordercancel_ = nullptr;
  }
  orderid_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CancelOrderRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 orderId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_orderid(&has_bits);
          orderid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .protobuf.OrderCancel orderCancel = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_ordercancel(), ptr);
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
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CancelOrderRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf.CancelOrderRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 orderId = 1;
  if (_internal_has_orderid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_orderid(), target);
  }

  // .protobuf.OrderCancel orderCancel = 2;
  if (_internal_has_ordercancel()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::ordercancel(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf.CancelOrderRequest)
  return target;
}

size_t CancelOrderRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf.CancelOrderRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // .protobuf.OrderCancel orderCancel = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *ordercancel_);
    }

    // int32 orderId = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_orderid());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CancelOrderRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protobuf.CancelOrderRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const CancelOrderRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CancelOrderRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protobuf.CancelOrderRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protobuf.CancelOrderRequest)
    MergeFrom(*source);
  }
}

void CancelOrderRequest::MergeFrom(const CancelOrderRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf.CancelOrderRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_ordercancel()->::protobuf::OrderCancel::MergeFrom(from._internal_ordercancel());
    }
    if (cached_has_bits & 0x00000002u) {
      orderid_ = from.orderid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void CancelOrderRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protobuf.CancelOrderRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CancelOrderRequest::CopyFrom(const CancelOrderRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf.CancelOrderRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CancelOrderRequest::IsInitialized() const {
  return true;
}

void CancelOrderRequest::InternalSwap(CancelOrderRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CancelOrderRequest, orderid_)
      + sizeof(CancelOrderRequest::orderid_)
      - PROTOBUF_FIELD_OFFSET(CancelOrderRequest, ordercancel_)>(
          reinterpret_cast<char*>(&ordercancel_),
          reinterpret_cast<char*>(&other->ordercancel_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CancelOrderRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf::CancelOrderRequest* Arena::CreateMaybeMessage< ::protobuf::CancelOrderRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protobuf::CancelOrderRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
