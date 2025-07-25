// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OrderStatus.proto

#include "OrderStatus.pb.h"

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
class OrderStatusDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<OrderStatus> _instance;
} _OrderStatus_default_instance_;
}  // namespace protobuf
static void InitDefaultsscc_info_OrderStatus_OrderStatus_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf::_OrderStatus_default_instance_;
    new (ptr) ::protobuf::OrderStatus();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf::OrderStatus::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_OrderStatus_OrderStatus_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_OrderStatus_OrderStatus_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_OrderStatus_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_OrderStatus_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_OrderStatus_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_OrderStatus_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, orderid_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, status_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, filled_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, remaining_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, avgfillprice_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, permid_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, parentid_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, lastfillprice_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, clientid_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, whyheld_),
  PROTOBUF_FIELD_OFFSET(::protobuf::OrderStatus, mktcapprice_),
  4,
  0,
  1,
  2,
  6,
  7,
  5,
  8,
  10,
  3,
  9,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 16, sizeof(::protobuf::OrderStatus)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protobuf::_OrderStatus_default_instance_),
};

const char descriptor_table_protodef_OrderStatus_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021OrderStatus.proto\022\010protobuf\"\243\003\n\013OrderS"
  "tatus\022\024\n\007orderId\030\001 \001(\005H\000\210\001\001\022\023\n\006status\030\002 "
  "\001(\tH\001\210\001\001\022\023\n\006filled\030\003 \001(\tH\002\210\001\001\022\026\n\tremaini"
  "ng\030\004 \001(\tH\003\210\001\001\022\031\n\014avgFillPrice\030\005 \001(\001H\004\210\001\001"
  "\022\023\n\006permId\030\006 \001(\003H\005\210\001\001\022\025\n\010parentId\030\007 \001(\005H"
  "\006\210\001\001\022\032\n\rlastFillPrice\030\010 \001(\001H\007\210\001\001\022\025\n\010clie"
  "ntId\030\t \001(\005H\010\210\001\001\022\024\n\007whyHeld\030\n \001(\tH\t\210\001\001\022\030\n"
  "\013mktCapPrice\030\013 \001(\001H\n\210\001\001B\n\n\010_orderIdB\t\n\007_"
  "statusB\t\n\007_filledB\014\n\n_remainingB\017\n\r_avgF"
  "illPriceB\t\n\007_permIdB\013\n\t_parentIdB\020\n\016_las"
  "tFillPriceB\013\n\t_clientIdB\n\n\010_whyHeldB\016\n\014_"
  "mktCapPriceB;\n\026com.ib.client.protobufB\020O"
  "rderStatusProto\252\002\016IBApi.protobufb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_OrderStatus_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_OrderStatus_2eproto_sccs[1] = {
  &scc_info_OrderStatus_OrderStatus_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_OrderStatus_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_OrderStatus_2eproto = {
  false, false, descriptor_table_protodef_OrderStatus_2eproto, "OrderStatus.proto", 520,
  &descriptor_table_OrderStatus_2eproto_once, descriptor_table_OrderStatus_2eproto_sccs, descriptor_table_OrderStatus_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_OrderStatus_2eproto::offsets,
  file_level_metadata_OrderStatus_2eproto, 1, file_level_enum_descriptors_OrderStatus_2eproto, file_level_service_descriptors_OrderStatus_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_OrderStatus_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_OrderStatus_2eproto)), true);
namespace protobuf {

// ===================================================================

void OrderStatus::InitAsDefaultInstance() {
}
class OrderStatus::_Internal {
 public:
  using HasBits = decltype(std::declval<OrderStatus>()._has_bits_);
  static void set_has_orderid(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_status(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_filled(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_remaining(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_avgfillprice(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_permid(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_parentid(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_lastfillprice(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_clientid(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
  static void set_has_whyheld(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_mktcapprice(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
};

OrderStatus::OrderStatus(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protobuf.OrderStatus)
}
OrderStatus::OrderStatus(const OrderStatus& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_status()) {
    status_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_status(),
      GetArena());
  }
  filled_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_filled()) {
    filled_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_filled(),
      GetArena());
  }
  remaining_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_remaining()) {
    remaining_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_remaining(),
      GetArena());
  }
  whyheld_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_whyheld()) {
    whyheld_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_whyheld(),
      GetArena());
  }
  ::memcpy(&orderid_, &from.orderid_,
    static_cast<size_t>(reinterpret_cast<char*>(&clientid_) -
    reinterpret_cast<char*>(&orderid_)) + sizeof(clientid_));
  // @@protoc_insertion_point(copy_constructor:protobuf.OrderStatus)
}

void OrderStatus::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_OrderStatus_OrderStatus_2eproto.base);
  status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  filled_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  remaining_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  whyheld_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&orderid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&clientid_) -
      reinterpret_cast<char*>(&orderid_)) + sizeof(clientid_));
}

OrderStatus::~OrderStatus() {
  // @@protoc_insertion_point(destructor:protobuf.OrderStatus)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void OrderStatus::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  status_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  filled_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  remaining_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  whyheld_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void OrderStatus::ArenaDtor(void* object) {
  OrderStatus* _this = reinterpret_cast< OrderStatus* >(object);
  (void)_this;
}
void OrderStatus::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void OrderStatus::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const OrderStatus& OrderStatus::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_OrderStatus_OrderStatus_2eproto.base);
  return *internal_default_instance();
}


void OrderStatus::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf.OrderStatus)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      status_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      filled_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      remaining_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000008u) {
      whyheld_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x000000f0u) {
    ::memset(&orderid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&permid_) -
        reinterpret_cast<char*>(&orderid_)) + sizeof(permid_));
  }
  if (cached_has_bits & 0x00000700u) {
    ::memset(&lastfillprice_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&clientid_) -
        reinterpret_cast<char*>(&lastfillprice_)) + sizeof(clientid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* OrderStatus::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // string status = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_status();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderStatus.status"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string filled = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_filled();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderStatus.filled"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string remaining = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_remaining();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderStatus.remaining"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double avgFillPrice = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          _Internal::set_has_avgfillprice(&has_bits);
          avgfillprice_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // int64 permId = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_permid(&has_bits);
          permid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 parentId = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_parentid(&has_bits);
          parentid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double lastFillPrice = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 65)) {
          _Internal::set_has_lastfillprice(&has_bits);
          lastfillprice_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // int32 clientId = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          _Internal::set_has_clientid(&has_bits);
          clientid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string whyHeld = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 82)) {
          auto str = _internal_mutable_whyheld();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.OrderStatus.whyHeld"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double mktCapPrice = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 89)) {
          _Internal::set_has_mktcapprice(&has_bits);
          mktcapprice_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
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

::PROTOBUF_NAMESPACE_ID::uint8* OrderStatus::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf.OrderStatus)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 orderId = 1;
  if (_internal_has_orderid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_orderid(), target);
  }

  // string status = 2;
  if (_internal_has_status()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_status().data(), static_cast<int>(this->_internal_status().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderStatus.status");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_status(), target);
  }

  // string filled = 3;
  if (_internal_has_filled()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_filled().data(), static_cast<int>(this->_internal_filled().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderStatus.filled");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_filled(), target);
  }

  // string remaining = 4;
  if (_internal_has_remaining()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_remaining().data(), static_cast<int>(this->_internal_remaining().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderStatus.remaining");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_remaining(), target);
  }

  // double avgFillPrice = 5;
  if (_internal_has_avgfillprice()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(5, this->_internal_avgfillprice(), target);
  }

  // int64 permId = 6;
  if (_internal_has_permid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(6, this->_internal_permid(), target);
  }

  // int32 parentId = 7;
  if (_internal_has_parentid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(7, this->_internal_parentid(), target);
  }

  // double lastFillPrice = 8;
  if (_internal_has_lastfillprice()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(8, this->_internal_lastfillprice(), target);
  }

  // int32 clientId = 9;
  if (_internal_has_clientid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(9, this->_internal_clientid(), target);
  }

  // string whyHeld = 10;
  if (_internal_has_whyheld()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_whyheld().data(), static_cast<int>(this->_internal_whyheld().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.OrderStatus.whyHeld");
    target = stream->WriteStringMaybeAliased(
        10, this->_internal_whyheld(), target);
  }

  // double mktCapPrice = 11;
  if (_internal_has_mktcapprice()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(11, this->_internal_mktcapprice(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf.OrderStatus)
  return target;
}

size_t OrderStatus::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf.OrderStatus)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // string status = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_status());
    }

    // string filled = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_filled());
    }

    // string remaining = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_remaining());
    }

    // string whyHeld = 10;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_whyheld());
    }

    // int32 orderId = 1;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_orderid());
    }

    // int32 parentId = 7;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_parentid());
    }

    // double avgFillPrice = 5;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 + 8;
    }

    // int64 permId = 6;
    if (cached_has_bits & 0x00000080u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_permid());
    }

  }
  if (cached_has_bits & 0x00000700u) {
    // double lastFillPrice = 8;
    if (cached_has_bits & 0x00000100u) {
      total_size += 1 + 8;
    }

    // double mktCapPrice = 11;
    if (cached_has_bits & 0x00000200u) {
      total_size += 1 + 8;
    }

    // int32 clientId = 9;
    if (cached_has_bits & 0x00000400u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_clientid());
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

void OrderStatus::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protobuf.OrderStatus)
  GOOGLE_DCHECK_NE(&from, this);
  const OrderStatus* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<OrderStatus>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protobuf.OrderStatus)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protobuf.OrderStatus)
    MergeFrom(*source);
  }
}

void OrderStatus::MergeFrom(const OrderStatus& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf.OrderStatus)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_status(from._internal_status());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_filled(from._internal_filled());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_remaining(from._internal_remaining());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_set_whyheld(from._internal_whyheld());
    }
    if (cached_has_bits & 0x00000010u) {
      orderid_ = from.orderid_;
    }
    if (cached_has_bits & 0x00000020u) {
      parentid_ = from.parentid_;
    }
    if (cached_has_bits & 0x00000040u) {
      avgfillprice_ = from.avgfillprice_;
    }
    if (cached_has_bits & 0x00000080u) {
      permid_ = from.permid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00000700u) {
    if (cached_has_bits & 0x00000100u) {
      lastfillprice_ = from.lastfillprice_;
    }
    if (cached_has_bits & 0x00000200u) {
      mktcapprice_ = from.mktcapprice_;
    }
    if (cached_has_bits & 0x00000400u) {
      clientid_ = from.clientid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void OrderStatus::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protobuf.OrderStatus)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void OrderStatus::CopyFrom(const OrderStatus& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf.OrderStatus)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OrderStatus::IsInitialized() const {
  return true;
}

void OrderStatus::InternalSwap(OrderStatus* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  status_.Swap(&other->status_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  filled_.Swap(&other->filled_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  remaining_.Swap(&other->remaining_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  whyheld_.Swap(&other->whyheld_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(OrderStatus, clientid_)
      + sizeof(OrderStatus::clientid_)
      - PROTOBUF_FIELD_OFFSET(OrderStatus, orderid_)>(
          reinterpret_cast<char*>(&orderid_),
          reinterpret_cast<char*>(&other->orderid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata OrderStatus::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf::OrderStatus* Arena::CreateMaybeMessage< ::protobuf::OrderStatus >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protobuf::OrderStatus >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
