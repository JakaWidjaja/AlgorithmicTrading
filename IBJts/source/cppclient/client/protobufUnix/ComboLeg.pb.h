// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ComboLeg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ComboLeg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ComboLeg_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ComboLeg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ComboLeg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ComboLeg_2eproto;
namespace protobuf {
class ComboLeg;
class ComboLegDefaultTypeInternal;
extern ComboLegDefaultTypeInternal _ComboLeg_default_instance_;
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> ::protobuf::ComboLeg* Arena::CreateMaybeMessage<::protobuf::ComboLeg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protobuf {

// ===================================================================

class ComboLeg PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protobuf.ComboLeg) */ {
 public:
  inline ComboLeg() : ComboLeg(nullptr) {};
  virtual ~ComboLeg();

  ComboLeg(const ComboLeg& from);
  ComboLeg(ComboLeg&& from) noexcept
    : ComboLeg() {
    *this = ::std::move(from);
  }

  inline ComboLeg& operator=(const ComboLeg& from) {
    CopyFrom(from);
    return *this;
  }
  inline ComboLeg& operator=(ComboLeg&& from) noexcept {
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
  static const ComboLeg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ComboLeg* internal_default_instance() {
    return reinterpret_cast<const ComboLeg*>(
               &_ComboLeg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ComboLeg& a, ComboLeg& b) {
    a.Swap(&b);
  }
  inline void Swap(ComboLeg* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ComboLeg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ComboLeg* New() const final {
    return CreateMaybeMessage<ComboLeg>(nullptr);
  }

  ComboLeg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ComboLeg>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ComboLeg& from);
  void MergeFrom(const ComboLeg& from);
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
  void InternalSwap(ComboLeg* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobuf.ComboLeg";
  }
  protected:
  explicit ComboLeg(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_ComboLeg_2eproto);
    return ::descriptor_table_ComboLeg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kActionFieldNumber = 3,
    kExchangeFieldNumber = 4,
    kDesignatedLocationFieldNumber = 7,
    kConIdFieldNumber = 1,
    kRatioFieldNumber = 2,
    kOpenCloseFieldNumber = 5,
    kShortSalesSlotFieldNumber = 6,
    kPerLegPriceFieldNumber = 9,
    kExemptCodeFieldNumber = 8,
  };
  // string action = 3;
  bool has_action() const;
  private:
  bool _internal_has_action() const;
  public:
  void clear_action();
  const std::string& action() const;
  void set_action(const std::string& value);
  void set_action(std::string&& value);
  void set_action(const char* value);
  void set_action(const char* value, size_t size);
  std::string* mutable_action();
  std::string* release_action();
  void set_allocated_action(std::string* action);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_action();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_action(
      std::string* action);
  private:
  const std::string& _internal_action() const;
  void _internal_set_action(const std::string& value);
  std::string* _internal_mutable_action();
  public:

  // string exchange = 4;
  bool has_exchange() const;
  private:
  bool _internal_has_exchange() const;
  public:
  void clear_exchange();
  const std::string& exchange() const;
  void set_exchange(const std::string& value);
  void set_exchange(std::string&& value);
  void set_exchange(const char* value);
  void set_exchange(const char* value, size_t size);
  std::string* mutable_exchange();
  std::string* release_exchange();
  void set_allocated_exchange(std::string* exchange);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_exchange();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_exchange(
      std::string* exchange);
  private:
  const std::string& _internal_exchange() const;
  void _internal_set_exchange(const std::string& value);
  std::string* _internal_mutable_exchange();
  public:

  // string designatedLocation = 7;
  bool has_designatedlocation() const;
  private:
  bool _internal_has_designatedlocation() const;
  public:
  void clear_designatedlocation();
  const std::string& designatedlocation() const;
  void set_designatedlocation(const std::string& value);
  void set_designatedlocation(std::string&& value);
  void set_designatedlocation(const char* value);
  void set_designatedlocation(const char* value, size_t size);
  std::string* mutable_designatedlocation();
  std::string* release_designatedlocation();
  void set_allocated_designatedlocation(std::string* designatedlocation);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_designatedlocation();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_designatedlocation(
      std::string* designatedlocation);
  private:
  const std::string& _internal_designatedlocation() const;
  void _internal_set_designatedlocation(const std::string& value);
  std::string* _internal_mutable_designatedlocation();
  public:

  // int32 conId = 1;
  bool has_conid() const;
  private:
  bool _internal_has_conid() const;
  public:
  void clear_conid();
  ::PROTOBUF_NAMESPACE_ID::int32 conid() const;
  void set_conid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_conid() const;
  void _internal_set_conid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 ratio = 2;
  bool has_ratio() const;
  private:
  bool _internal_has_ratio() const;
  public:
  void clear_ratio();
  ::PROTOBUF_NAMESPACE_ID::int32 ratio() const;
  void set_ratio(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_ratio() const;
  void _internal_set_ratio(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 openClose = 5;
  bool has_openclose() const;
  private:
  bool _internal_has_openclose() const;
  public:
  void clear_openclose();
  ::PROTOBUF_NAMESPACE_ID::int32 openclose() const;
  void set_openclose(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_openclose() const;
  void _internal_set_openclose(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 shortSalesSlot = 6;
  bool has_shortsalesslot() const;
  private:
  bool _internal_has_shortsalesslot() const;
  public:
  void clear_shortsalesslot();
  ::PROTOBUF_NAMESPACE_ID::int32 shortsalesslot() const;
  void set_shortsalesslot(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_shortsalesslot() const;
  void _internal_set_shortsalesslot(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // double perLegPrice = 9;
  bool has_perlegprice() const;
  private:
  bool _internal_has_perlegprice() const;
  public:
  void clear_perlegprice();
  double perlegprice() const;
  void set_perlegprice(double value);
  private:
  double _internal_perlegprice() const;
  void _internal_set_perlegprice(double value);
  public:

  // int32 exemptCode = 8;
  bool has_exemptcode() const;
  private:
  bool _internal_has_exemptcode() const;
  public:
  void clear_exemptcode();
  ::PROTOBUF_NAMESPACE_ID::int32 exemptcode() const;
  void set_exemptcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_exemptcode() const;
  void _internal_set_exemptcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:protobuf.ComboLeg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr action_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr exchange_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr designatedlocation_;
  ::PROTOBUF_NAMESPACE_ID::int32 conid_;
  ::PROTOBUF_NAMESPACE_ID::int32 ratio_;
  ::PROTOBUF_NAMESPACE_ID::int32 openclose_;
  ::PROTOBUF_NAMESPACE_ID::int32 shortsalesslot_;
  double perlegprice_;
  ::PROTOBUF_NAMESPACE_ID::int32 exemptcode_;
  friend struct ::TableStruct_ComboLeg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ComboLeg

// int32 conId = 1;
inline bool ComboLeg::_internal_has_conid() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool ComboLeg::has_conid() const {
  return _internal_has_conid();
}
inline void ComboLeg::clear_conid() {
  conid_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::_internal_conid() const {
  return conid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::conid() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.conId)
  return _internal_conid();
}
inline void ComboLeg::_internal_set_conid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000008u;
  conid_ = value;
}
inline void ComboLeg::set_conid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_conid(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.conId)
}

// int32 ratio = 2;
inline bool ComboLeg::_internal_has_ratio() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool ComboLeg::has_ratio() const {
  return _internal_has_ratio();
}
inline void ComboLeg::clear_ratio() {
  ratio_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::_internal_ratio() const {
  return ratio_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::ratio() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.ratio)
  return _internal_ratio();
}
inline void ComboLeg::_internal_set_ratio(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000010u;
  ratio_ = value;
}
inline void ComboLeg::set_ratio(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_ratio(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.ratio)
}

// string action = 3;
inline bool ComboLeg::_internal_has_action() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ComboLeg::has_action() const {
  return _internal_has_action();
}
inline void ComboLeg::clear_action() {
  action_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ComboLeg::action() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.action)
  return _internal_action();
}
inline void ComboLeg::set_action(const std::string& value) {
  _internal_set_action(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.action)
}
inline std::string* ComboLeg::mutable_action() {
  // @@protoc_insertion_point(field_mutable:protobuf.ComboLeg.action)
  return _internal_mutable_action();
}
inline const std::string& ComboLeg::_internal_action() const {
  return action_.Get();
}
inline void ComboLeg::_internal_set_action(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  action_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ComboLeg::set_action(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  action_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:protobuf.ComboLeg.action)
}
inline void ComboLeg::set_action(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  action_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:protobuf.ComboLeg.action)
}
inline void ComboLeg::set_action(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  action_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:protobuf.ComboLeg.action)
}
inline std::string* ComboLeg::_internal_mutable_action() {
  _has_bits_[0] |= 0x00000001u;
  return action_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ComboLeg::release_action() {
  // @@protoc_insertion_point(field_release:protobuf.ComboLeg.action)
  if (!_internal_has_action()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return action_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ComboLeg::set_allocated_action(std::string* action) {
  if (action != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  action_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), action,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:protobuf.ComboLeg.action)
}
inline std::string* ComboLeg::unsafe_arena_release_action() {
  // @@protoc_insertion_point(field_unsafe_arena_release:protobuf.ComboLeg.action)
  GOOGLE_DCHECK(GetArena() != nullptr);
  _has_bits_[0] &= ~0x00000001u;
  return action_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void ComboLeg::unsafe_arena_set_allocated_action(
    std::string* action) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (action != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  action_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      action, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protobuf.ComboLeg.action)
}

// string exchange = 4;
inline bool ComboLeg::_internal_has_exchange() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ComboLeg::has_exchange() const {
  return _internal_has_exchange();
}
inline void ComboLeg::clear_exchange() {
  exchange_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& ComboLeg::exchange() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.exchange)
  return _internal_exchange();
}
inline void ComboLeg::set_exchange(const std::string& value) {
  _internal_set_exchange(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.exchange)
}
inline std::string* ComboLeg::mutable_exchange() {
  // @@protoc_insertion_point(field_mutable:protobuf.ComboLeg.exchange)
  return _internal_mutable_exchange();
}
inline const std::string& ComboLeg::_internal_exchange() const {
  return exchange_.Get();
}
inline void ComboLeg::_internal_set_exchange(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  exchange_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ComboLeg::set_exchange(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  exchange_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:protobuf.ComboLeg.exchange)
}
inline void ComboLeg::set_exchange(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  exchange_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:protobuf.ComboLeg.exchange)
}
inline void ComboLeg::set_exchange(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000002u;
  exchange_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:protobuf.ComboLeg.exchange)
}
inline std::string* ComboLeg::_internal_mutable_exchange() {
  _has_bits_[0] |= 0x00000002u;
  return exchange_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ComboLeg::release_exchange() {
  // @@protoc_insertion_point(field_release:protobuf.ComboLeg.exchange)
  if (!_internal_has_exchange()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return exchange_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ComboLeg::set_allocated_exchange(std::string* exchange) {
  if (exchange != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  exchange_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), exchange,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:protobuf.ComboLeg.exchange)
}
inline std::string* ComboLeg::unsafe_arena_release_exchange() {
  // @@protoc_insertion_point(field_unsafe_arena_release:protobuf.ComboLeg.exchange)
  GOOGLE_DCHECK(GetArena() != nullptr);
  _has_bits_[0] &= ~0x00000002u;
  return exchange_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void ComboLeg::unsafe_arena_set_allocated_exchange(
    std::string* exchange) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (exchange != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  exchange_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      exchange, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protobuf.ComboLeg.exchange)
}

// int32 openClose = 5;
inline bool ComboLeg::_internal_has_openclose() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool ComboLeg::has_openclose() const {
  return _internal_has_openclose();
}
inline void ComboLeg::clear_openclose() {
  openclose_ = 0;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::_internal_openclose() const {
  return openclose_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::openclose() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.openClose)
  return _internal_openclose();
}
inline void ComboLeg::_internal_set_openclose(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000020u;
  openclose_ = value;
}
inline void ComboLeg::set_openclose(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_openclose(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.openClose)
}

// int32 shortSalesSlot = 6;
inline bool ComboLeg::_internal_has_shortsalesslot() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool ComboLeg::has_shortsalesslot() const {
  return _internal_has_shortsalesslot();
}
inline void ComboLeg::clear_shortsalesslot() {
  shortsalesslot_ = 0;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::_internal_shortsalesslot() const {
  return shortsalesslot_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::shortsalesslot() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.shortSalesSlot)
  return _internal_shortsalesslot();
}
inline void ComboLeg::_internal_set_shortsalesslot(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000040u;
  shortsalesslot_ = value;
}
inline void ComboLeg::set_shortsalesslot(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_shortsalesslot(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.shortSalesSlot)
}

// string designatedLocation = 7;
inline bool ComboLeg::_internal_has_designatedlocation() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ComboLeg::has_designatedlocation() const {
  return _internal_has_designatedlocation();
}
inline void ComboLeg::clear_designatedlocation() {
  designatedlocation_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& ComboLeg::designatedlocation() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.designatedLocation)
  return _internal_designatedlocation();
}
inline void ComboLeg::set_designatedlocation(const std::string& value) {
  _internal_set_designatedlocation(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.designatedLocation)
}
inline std::string* ComboLeg::mutable_designatedlocation() {
  // @@protoc_insertion_point(field_mutable:protobuf.ComboLeg.designatedLocation)
  return _internal_mutable_designatedlocation();
}
inline const std::string& ComboLeg::_internal_designatedlocation() const {
  return designatedlocation_.Get();
}
inline void ComboLeg::_internal_set_designatedlocation(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  designatedlocation_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ComboLeg::set_designatedlocation(std::string&& value) {
  _has_bits_[0] |= 0x00000004u;
  designatedlocation_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:protobuf.ComboLeg.designatedLocation)
}
inline void ComboLeg::set_designatedlocation(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000004u;
  designatedlocation_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:protobuf.ComboLeg.designatedLocation)
}
inline void ComboLeg::set_designatedlocation(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000004u;
  designatedlocation_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:protobuf.ComboLeg.designatedLocation)
}
inline std::string* ComboLeg::_internal_mutable_designatedlocation() {
  _has_bits_[0] |= 0x00000004u;
  return designatedlocation_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ComboLeg::release_designatedlocation() {
  // @@protoc_insertion_point(field_release:protobuf.ComboLeg.designatedLocation)
  if (!_internal_has_designatedlocation()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return designatedlocation_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ComboLeg::set_allocated_designatedlocation(std::string* designatedlocation) {
  if (designatedlocation != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  designatedlocation_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), designatedlocation,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:protobuf.ComboLeg.designatedLocation)
}
inline std::string* ComboLeg::unsafe_arena_release_designatedlocation() {
  // @@protoc_insertion_point(field_unsafe_arena_release:protobuf.ComboLeg.designatedLocation)
  GOOGLE_DCHECK(GetArena() != nullptr);
  _has_bits_[0] &= ~0x00000004u;
  return designatedlocation_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void ComboLeg::unsafe_arena_set_allocated_designatedlocation(
    std::string* designatedlocation) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (designatedlocation != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  designatedlocation_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      designatedlocation, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protobuf.ComboLeg.designatedLocation)
}

// int32 exemptCode = 8;
inline bool ComboLeg::_internal_has_exemptcode() const {
  bool value = (_has_bits_[0] & 0x00000100u) != 0;
  return value;
}
inline bool ComboLeg::has_exemptcode() const {
  return _internal_has_exemptcode();
}
inline void ComboLeg::clear_exemptcode() {
  exemptcode_ = 0;
  _has_bits_[0] &= ~0x00000100u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::_internal_exemptcode() const {
  return exemptcode_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ComboLeg::exemptcode() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.exemptCode)
  return _internal_exemptcode();
}
inline void ComboLeg::_internal_set_exemptcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000100u;
  exemptcode_ = value;
}
inline void ComboLeg::set_exemptcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_exemptcode(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.exemptCode)
}

// double perLegPrice = 9;
inline bool ComboLeg::_internal_has_perlegprice() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool ComboLeg::has_perlegprice() const {
  return _internal_has_perlegprice();
}
inline void ComboLeg::clear_perlegprice() {
  perlegprice_ = 0;
  _has_bits_[0] &= ~0x00000080u;
}
inline double ComboLeg::_internal_perlegprice() const {
  return perlegprice_;
}
inline double ComboLeg::perlegprice() const {
  // @@protoc_insertion_point(field_get:protobuf.ComboLeg.perLegPrice)
  return _internal_perlegprice();
}
inline void ComboLeg::_internal_set_perlegprice(double value) {
  _has_bits_[0] |= 0x00000080u;
  perlegprice_ = value;
}
inline void ComboLeg::set_perlegprice(double value) {
  _internal_set_perlegprice(value);
  // @@protoc_insertion_point(field_set:protobuf.ComboLeg.perLegPrice)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ComboLeg_2eproto
