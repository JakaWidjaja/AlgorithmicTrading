// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OrderAllocation.proto

#include "OrderAllocation.pb.h"

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
namespace protobuf {
class OrderAllocationDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<OrderAllocation> _instance;
} _OrderAllocation_default_instance_;
}  // namespace protobuf
static void InitDefaultsscc_info_OrderAllocation_OrderAllocation_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf::_OrderAllocation_default_instance_;
    new (ptr) ::protobuf::OrderAllocation();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf::OrderAllocation::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_OrderAllocation_OrderAllocation_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_OrderAllocation_OrderAllocation_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_OrderAllocation_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_OrderAllocation_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_OrderAllocation_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_OrderAllocation_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, account_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, position_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, positiondesired_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, positionafter_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, desiredallocqty_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, allowedallocqty_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderAllocation, ismonetary_),
  0,
  1,
  2,
  3,
  4,
  5,
  6,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 12, sizeof(::protobuf::OrderAllocation)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protobuf::_OrderAllocation_default_instance_),
};

const char descriptor_table_protodef_OrderAllocation_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025OrderAllocation.proto\022\010protobuf\"\303\002\n\017Or"
  "derAllocation\022\024\n\007account\030\001 \001(\tH\000\210\001\001\022\025\n\010p"
  "osition\030\002 \001(\tH\001\210\001\001\022\034\n\017positionDesired\030\003 "
  "\001(\tH\002\210\001\001\022\032\n\rpositionAfter\030\004 \001(\tH\003\210\001\001\022\034\n\017"
  "desiredAllocQty\030\005 \001(\tH\004\210\001\001\022\034\n\017allowedAll"
  "ocQty\030\006 \001(\tH\005\210\001\001\022\027\n\nisMonetary\030\007 \001(\010H\006\210\001"
  "\001B\n\n\010_accountB\013\n\t_positionB\022\n\020_positionD"
  "esiredB\020\n\016_positionAfterB\022\n\020_desiredAllo"
  "cQtyB\022\n\020_allowedAllocQtyB\r\n\013_isMonetaryB"
  "\?\n\026com.ib.client.protobufB\024OrderAllocati"
  "onProto\252\002\016IBApi.protobufb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_OrderAllocation_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_OrderAllocation_2eproto_sccs[1] = {
  &scc_info_OrderAllocation_OrderAllocation_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_OrderAllocation_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_OrderAllocation_2eproto = {
  false, false, descriptor_table_protodef_OrderAllocation_2eproto, "OrderAllocation.proto", 432,
  &descriptor_table_OrderAllocation_2eproto_once, descriptor_table_OrderAllocation_2eproto_sccs, descriptor_table_OrderAllocation_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_OrderAllocation_2eproto::offsets,
  file_level_metadata_OrderAllocation_2eproto, 1, file_level_enum_descriptors_OrderAllocation_2eproto, file_level_service_descriptors_OrderAllocation_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_OrderAllocation_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_OrderAllocation_2eproto)), true);
namespace protobuf {

// ===================================================================

void OrderAllocation::InitAsDefaultInstance() {
}
class OrderAllocation::_Internal {
 public:
  using HasBits = decltype(std::declval<OrderAllocation>()._has_bits_);
  static void set_has_account(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_position(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_positiondesired(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_positionafter(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_desiredallocqty(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_allowedallocqty(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_ismonetary(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
};

OrderAllocation::OrderAllocation(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protobuf.OrderAllocation)
}
OrderAllocation::OrderAllocation(const OrderAllocation& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_account()) {
    account_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_account(),
      GetArena());
  }
  position_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_position()) {
    position_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_position(),
      GetArena());
  }
  positiondesired_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_positiondesired()) {
    positiondesired_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_positiondesired(),
      GetArena());
  }
  positionafter_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_positionafter()) {
    positionafter_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_positionafter(),
      GetArena());
  }
  desiredallocqty_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_desiredallocqty()) {
    desiredallocqty_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_desiredallocqty(),
      GetArena());
  }
  allowedallocqty_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_allowedallocqty()) {
    allowedallocqty_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_allowedallocqty(),
      GetArena());
  }
  ismonetary_ = from.ismonetary_;
  // @@protoc_insertion_point(copy_constructor:protobuf.OrderAllocation)
}

void OrderAllocation::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_OrderAllocation_OrderAllocation_2eproto.base);
  account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  position_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  positiondesired_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  positionafter_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  desiredallocqty_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  allowedallocqty_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ismonetary_ = false;
}

OrderAllocation::~OrderAllocation() {
  // @@protoc_insertion_point(destructor:protobuf.OrderAllocation)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void OrderAllocation::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  account_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  position_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  positiondesired_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  positionafter_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  desiredallocqty_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  allowedallocqty_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void OrderAllocation::ArenaDtor(void* object) {
  OrderAllocation* _this = reinterpret_cast< OrderAllocation* >(object);
  (void)_this;
}
void OrderAllocation::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void OrderAllocation::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const OrderAllocation& OrderAllocation::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_OrderAllocation_OrderAllocation_2eproto.base);
  return *internal_default_instance();
}


void OrderAllocation::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf.OrderAllocation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      account_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      position_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      positiondesired_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000008u) {
      positionafter_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000010u) {
      desiredallocqty_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000020u) {
      allowedallocqty_.ClearNonDefaultToEmpty();
    }
  }
  ismonetary_ = false;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* OrderAllocation::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string account = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_account();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.account"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string position = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_position();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.position"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string positionDesired = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_positiondesired();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.positionDesired"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string positionAfter = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_positionafter();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.positionAfter"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string desiredAllocQty = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_desiredallocqty();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.desiredAllocQty"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string allowedAllocQty = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          auto str = _internal_mutable_allowedallocqty();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderAllocation.allowedAllocQty"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool isMonetary = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_ismonetary(&has_bits);
          ismonetary_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* OrderAllocation::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf.OrderAllocation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string account = 1;
  if (_internal_has_account()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_account().data(), static_cast<int>(this->_internal_account().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.account");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_account(), target);
  }

  // string position = 2;
  if (_internal_has_position()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_position().data(), static_cast<int>(this->_internal_position().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.position");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_position(), target);
  }

  // string positionDesired = 3;
  if (_internal_has_positiondesired()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_positiondesired().data(), static_cast<int>(this->_internal_positiondesired().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.positionDesired");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_positiondesired(), target);
  }

  // string positionAfter = 4;
  if (_internal_has_positionafter()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_positionafter().data(), static_cast<int>(this->_internal_positionafter().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.positionAfter");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_positionafter(), target);
  }

  // string desiredAllocQty = 5;
  if (_internal_has_desiredallocqty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_desiredallocqty().data(), static_cast<int>(this->_internal_desiredallocqty().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.desiredAllocQty");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_desiredallocqty(), target);
  }

  // string allowedAllocQty = 6;
  if (_internal_has_allowedallocqty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_allowedallocqty().data(), static_cast<int>(this->_internal_allowedallocqty().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderAllocation.allowedAllocQty");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_allowedallocqty(), target);
  }

  // bool isMonetary = 7;
  if (_internal_has_ismonetary()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(7, this->_internal_ismonetary(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf.OrderAllocation)
  return target;
}

size_t OrderAllocation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf.OrderAllocation)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    // string account = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_account());
    }

    // string position = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_position());
    }

    // string positionDesired = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_positiondesired());
    }

    // string positionAfter = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_positionafter());
    }

    // string desiredAllocQty = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_desiredallocqty());
    }

    // string allowedAllocQty = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_allowedallocqty());
    }

    // bool isMonetary = 7;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 + 1;
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

void OrderAllocation::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protobuf.OrderAllocation)
  GOOGLE_DCHECK_NE(&from, this);
  const OrderAllocation* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<OrderAllocation>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protobuf.OrderAllocation)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protobuf.OrderAllocation)
    MergeFrom(*source);
  }
}

void OrderAllocation::MergeFrom(const OrderAllocation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf.OrderAllocation)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_account(from._internal_account());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_position(from._internal_position());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_positiondesired(from._internal_positiondesired());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_set_positionafter(from._internal_positionafter());
    }
    if (cached_has_bits & 0x00000010u) {
      _internal_set_desiredallocqty(from._internal_desiredallocqty());
    }
    if (cached_has_bits & 0x00000020u) {
      _internal_set_allowedallocqty(from._internal_allowedallocqty());
    }
    if (cached_has_bits & 0x00000040u) {
      ismonetary_ = from.ismonetary_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void OrderAllocation::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protobuf.OrderAllocation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void OrderAllocation::CopyFrom(const OrderAllocation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf.OrderAllocation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OrderAllocation::IsInitialized() const {
  return true;
}

void OrderAllocation::InternalSwap(OrderAllocation* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  account_.Swap(&other->account_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  position_.Swap(&other->position_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  positiondesired_.Swap(&other->positiondesired_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  positionafter_.Swap(&other->positionafter_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  desiredallocqty_.Swap(&other->desiredallocqty_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  allowedallocqty_.Swap(&other->allowedallocqty_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(ismonetary_, other->ismonetary_);
}

::PROTOBUF_NAMESPACE_ID::Metadata OrderAllocation::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf::OrderAllocation* Arena::CreateMaybeMessage< ::protobuf::OrderAllocation >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protobuf::OrderAllocation >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
