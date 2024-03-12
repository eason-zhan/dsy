// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/stats.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fstats_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fstats_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2fstats_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fstats_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fstats_2eproto;
namespace proto {
namespace ad {
class Stats;
struct StatsDefaultTypeInternal;
extern StatsDefaultTypeInternal _Stats_default_instance_;
class StatsOpt;
struct StatsOptDefaultTypeInternal;
extern StatsOptDefaultTypeInternal _StatsOpt_default_instance_;
}  // namespace ad
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::ad::Stats* Arena::CreateMaybeMessage<::proto::ad::Stats>(Arena*);
template<> ::proto::ad::StatsOpt* Arena::CreateMaybeMessage<::proto::ad::StatsOpt>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {
namespace ad {

// ===================================================================

class Stats final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.ad.Stats) */ {
 public:
  inline Stats() : Stats(nullptr) {}
  ~Stats() override;
  explicit PROTOBUF_CONSTEXPR Stats(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Stats(const Stats& from);
  Stats(Stats&& from) noexcept
    : Stats() {
    *this = ::std::move(from);
  }

  inline Stats& operator=(const Stats& from) {
    CopyFrom(from);
    return *this;
  }
  inline Stats& operator=(Stats&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Stats& default_instance() {
    return *internal_default_instance();
  }
  static inline const Stats* internal_default_instance() {
    return reinterpret_cast<const Stats*>(
               &_Stats_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Stats& a, Stats& b) {
    a.Swap(&b);
  }
  inline void Swap(Stats* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Stats* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Stats* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Stats>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Stats& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Stats& from) {
    Stats::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Stats* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.ad.Stats";
  }
  protected:
  explicit Stats(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBucketFieldNumber = 11,
    kHourBucketFieldNumber = 12,
    kAccBucketFieldNumber = 13,
    kTsFieldNumber = 1,
    kShowFieldNumber = 2,
    kClickFieldNumber = 3,
    kCostFieldNumber = 4,
    kHourShowFieldNumber = 5,
    kHourClickFieldNumber = 6,
    kHourCostFieldNumber = 7,
    kAccShowFieldNumber = 8,
    kAccClickFieldNumber = 9,
    kAccCostFieldNumber = 10,
  };
  // repeated int64 bucket = 11;
  int bucket_size() const;
  private:
  int _internal_bucket_size() const;
  public:
  void clear_bucket();
  private:
  int64_t _internal_bucket(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_bucket() const;
  void _internal_add_bucket(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_bucket();
  public:
  int64_t bucket(int index) const;
  void set_bucket(int index, int64_t value);
  void add_bucket(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      bucket() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_bucket();

  // repeated int64 hour_bucket = 12;
  int hour_bucket_size() const;
  private:
  int _internal_hour_bucket_size() const;
  public:
  void clear_hour_bucket();
  private:
  int64_t _internal_hour_bucket(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_hour_bucket() const;
  void _internal_add_hour_bucket(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_hour_bucket();
  public:
  int64_t hour_bucket(int index) const;
  void set_hour_bucket(int index, int64_t value);
  void add_hour_bucket(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      hour_bucket() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_hour_bucket();

  // repeated int64 acc_bucket = 13;
  int acc_bucket_size() const;
  private:
  int _internal_acc_bucket_size() const;
  public:
  void clear_acc_bucket();
  private:
  int64_t _internal_acc_bucket(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_acc_bucket() const;
  void _internal_add_acc_bucket(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_acc_bucket();
  public:
  int64_t acc_bucket(int index) const;
  void set_acc_bucket(int index, int64_t value);
  void add_acc_bucket(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      acc_bucket() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_acc_bucket();

  // int64 ts = 1;
  void clear_ts();
  int64_t ts() const;
  void set_ts(int64_t value);
  private:
  int64_t _internal_ts() const;
  void _internal_set_ts(int64_t value);
  public:

  // int64 show = 2;
  void clear_show();
  int64_t show() const;
  void set_show(int64_t value);
  private:
  int64_t _internal_show() const;
  void _internal_set_show(int64_t value);
  public:

  // int64 click = 3;
  void clear_click();
  int64_t click() const;
  void set_click(int64_t value);
  private:
  int64_t _internal_click() const;
  void _internal_set_click(int64_t value);
  public:

  // int64 cost = 4;
  void clear_cost();
  int64_t cost() const;
  void set_cost(int64_t value);
  private:
  int64_t _internal_cost() const;
  void _internal_set_cost(int64_t value);
  public:

  // int64 hour_show = 5;
  void clear_hour_show();
  int64_t hour_show() const;
  void set_hour_show(int64_t value);
  private:
  int64_t _internal_hour_show() const;
  void _internal_set_hour_show(int64_t value);
  public:

  // int64 hour_click = 6;
  void clear_hour_click();
  int64_t hour_click() const;
  void set_hour_click(int64_t value);
  private:
  int64_t _internal_hour_click() const;
  void _internal_set_hour_click(int64_t value);
  public:

  // int64 hour_cost = 7;
  void clear_hour_cost();
  int64_t hour_cost() const;
  void set_hour_cost(int64_t value);
  private:
  int64_t _internal_hour_cost() const;
  void _internal_set_hour_cost(int64_t value);
  public:

  // int64 acc_show = 8;
  void clear_acc_show();
  int64_t acc_show() const;
  void set_acc_show(int64_t value);
  private:
  int64_t _internal_acc_show() const;
  void _internal_set_acc_show(int64_t value);
  public:

  // int64 acc_click = 9;
  void clear_acc_click();
  int64_t acc_click() const;
  void set_acc_click(int64_t value);
  private:
  int64_t _internal_acc_click() const;
  void _internal_set_acc_click(int64_t value);
  public:

  // int64 acc_cost = 10;
  void clear_acc_cost();
  int64_t acc_cost() const;
  void set_acc_cost(int64_t value);
  private:
  int64_t _internal_acc_cost() const;
  void _internal_set_acc_cost(int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto.ad.Stats)
  public:
    class _Internal;

    template <typename T>
    friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    typedef void InternalArenaConstructable_;
    typedef void DestructorSkippable_;
    struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > bucket_;
    mutable std::atomic<int> _bucket_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > hour_bucket_;
    mutable std::atomic<int> _hour_bucket_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > acc_bucket_;
    mutable std::atomic<int> _acc_bucket_cached_byte_size_;
    int64_t ts_;
    int64_t show_;
    int64_t click_;
    int64_t cost_;
    int64_t hour_show_;
    int64_t hour_click_;
    int64_t hour_cost_;
    int64_t acc_show_;
    int64_t acc_click_;
    int64_t acc_cost_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fstats_2eproto;
};
// -------------------------------------------------------------------

class StatsOpt final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.ad.StatsOpt) */ {
 public:
  inline StatsOpt() : StatsOpt(nullptr) {}
  ~StatsOpt() override;
  explicit PROTOBUF_CONSTEXPR StatsOpt(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StatsOpt(const StatsOpt& from);
  StatsOpt(StatsOpt&& from) noexcept
    : StatsOpt() {
    *this = ::std::move(from);
  }

  inline StatsOpt& operator=(const StatsOpt& from) {
    CopyFrom(from);
    return *this;
  }
  inline StatsOpt& operator=(StatsOpt&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StatsOpt& default_instance() {
    return *internal_default_instance();
  }
  static inline const StatsOpt* internal_default_instance() {
    return reinterpret_cast<const StatsOpt*>(
               &_StatsOpt_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(StatsOpt& a, StatsOpt& b) {
    a.Swap(&b);
  }
  inline void Swap(StatsOpt* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StatsOpt* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StatsOpt* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StatsOpt>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StatsOpt& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const StatsOpt& from) {
    StatsOpt::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StatsOpt* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.ad.StatsOpt";
  }
  protected:
  explicit StatsOpt(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBucketFieldNumber = 11,
    kHourBucketFieldNumber = 12,
    kTsFieldNumber = 1,
    kShowFieldNumber = 2,
    kClickFieldNumber = 3,
    kCostFieldNumber = 4,
    kHourShowFieldNumber = 5,
    kHourClickFieldNumber = 6,
    kHourCostFieldNumber = 7,
  };
  // repeated int64 bucket = 11;
  int bucket_size() const;
  private:
  int _internal_bucket_size() const;
  public:
  void clear_bucket();
  private:
  int64_t _internal_bucket(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_bucket() const;
  void _internal_add_bucket(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_bucket();
  public:
  int64_t bucket(int index) const;
  void set_bucket(int index, int64_t value);
  void add_bucket(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      bucket() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_bucket();

  // repeated int64 hour_bucket = 12;
  int hour_bucket_size() const;
  private:
  int _internal_hour_bucket_size() const;
  public:
  void clear_hour_bucket();
  private:
  int64_t _internal_hour_bucket(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_hour_bucket() const;
  void _internal_add_hour_bucket(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_hour_bucket();
  public:
  int64_t hour_bucket(int index) const;
  void set_hour_bucket(int index, int64_t value);
  void add_hour_bucket(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      hour_bucket() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_hour_bucket();

  // int64 ts = 1;
  void clear_ts();
  int64_t ts() const;
  void set_ts(int64_t value);
  private:
  int64_t _internal_ts() const;
  void _internal_set_ts(int64_t value);
  public:

  // int64 show = 2;
  void clear_show();
  int64_t show() const;
  void set_show(int64_t value);
  private:
  int64_t _internal_show() const;
  void _internal_set_show(int64_t value);
  public:

  // int64 click = 3;
  void clear_click();
  int64_t click() const;
  void set_click(int64_t value);
  private:
  int64_t _internal_click() const;
  void _internal_set_click(int64_t value);
  public:

  // int64 cost = 4;
  void clear_cost();
  int64_t cost() const;
  void set_cost(int64_t value);
  private:
  int64_t _internal_cost() const;
  void _internal_set_cost(int64_t value);
  public:

  // int64 hour_show = 5;
  void clear_hour_show();
  int64_t hour_show() const;
  void set_hour_show(int64_t value);
  private:
  int64_t _internal_hour_show() const;
  void _internal_set_hour_show(int64_t value);
  public:

  // int64 hour_click = 6;
  void clear_hour_click();
  int64_t hour_click() const;
  void set_hour_click(int64_t value);
  private:
  int64_t _internal_hour_click() const;
  void _internal_set_hour_click(int64_t value);
  public:

  // int64 hour_cost = 7;
  void clear_hour_cost();
  int64_t hour_cost() const;
  void set_hour_cost(int64_t value);
  private:
  int64_t _internal_hour_cost() const;
  void _internal_set_hour_cost(int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto.ad.StatsOpt)
  public:
    class _Internal;

    template <typename T>
    friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    typedef void InternalArenaConstructable_;
    typedef void DestructorSkippable_;
    struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > bucket_;
    mutable std::atomic<int> _bucket_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > hour_bucket_;
    mutable std::atomic<int> _hour_bucket_cached_byte_size_;
    int64_t ts_;
    int64_t show_;
    int64_t click_;
    int64_t cost_;
    int64_t hour_show_;
    int64_t hour_click_;
    int64_t hour_cost_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fstats_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Stats

// int64 ts = 1;
inline void Stats::clear_ts() {
  _impl_.ts_ = int64_t{0};
}
inline int64_t Stats::_internal_ts() const {
  return _impl_.ts_;
}
inline int64_t Stats::ts() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.ts)
  return _internal_ts();
}
inline void Stats::_internal_set_ts(int64_t value) {
  
  _impl_.ts_ = value;
}
inline void Stats::set_ts(int64_t value) {
  _internal_set_ts(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.ts)
}

// int64 show = 2;
inline void Stats::clear_show() {
  _impl_.show_ = int64_t{0};
}
inline int64_t Stats::_internal_show() const {
  return _impl_.show_;
}
inline int64_t Stats::show() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.show)
  return _internal_show();
}
inline void Stats::_internal_set_show(int64_t value) {
  
  _impl_.show_ = value;
}
inline void Stats::set_show(int64_t value) {
  _internal_set_show(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.show)
}

// int64 click = 3;
inline void Stats::clear_click() {
  _impl_.click_ = int64_t{0};
}
inline int64_t Stats::_internal_click() const {
  return _impl_.click_;
}
inline int64_t Stats::click() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.click)
  return _internal_click();
}
inline void Stats::_internal_set_click(int64_t value) {
  
  _impl_.click_ = value;
}
inline void Stats::set_click(int64_t value) {
  _internal_set_click(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.click)
}

// int64 cost = 4;
inline void Stats::clear_cost() {
  _impl_.cost_ = int64_t{0};
}
inline int64_t Stats::_internal_cost() const {
  return _impl_.cost_;
}
inline int64_t Stats::cost() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.cost)
  return _internal_cost();
}
inline void Stats::_internal_set_cost(int64_t value) {
  
  _impl_.cost_ = value;
}
inline void Stats::set_cost(int64_t value) {
  _internal_set_cost(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.cost)
}

// int64 hour_show = 5;
inline void Stats::clear_hour_show() {
  _impl_.hour_show_ = int64_t{0};
}
inline int64_t Stats::_internal_hour_show() const {
  return _impl_.hour_show_;
}
inline int64_t Stats::hour_show() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.hour_show)
  return _internal_hour_show();
}
inline void Stats::_internal_set_hour_show(int64_t value) {
  
  _impl_.hour_show_ = value;
}
inline void Stats::set_hour_show(int64_t value) {
  _internal_set_hour_show(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.hour_show)
}

// int64 hour_click = 6;
inline void Stats::clear_hour_click() {
  _impl_.hour_click_ = int64_t{0};
}
inline int64_t Stats::_internal_hour_click() const {
  return _impl_.hour_click_;
}
inline int64_t Stats::hour_click() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.hour_click)
  return _internal_hour_click();
}
inline void Stats::_internal_set_hour_click(int64_t value) {
  
  _impl_.hour_click_ = value;
}
inline void Stats::set_hour_click(int64_t value) {
  _internal_set_hour_click(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.hour_click)
}

// int64 hour_cost = 7;
inline void Stats::clear_hour_cost() {
  _impl_.hour_cost_ = int64_t{0};
}
inline int64_t Stats::_internal_hour_cost() const {
  return _impl_.hour_cost_;
}
inline int64_t Stats::hour_cost() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.hour_cost)
  return _internal_hour_cost();
}
inline void Stats::_internal_set_hour_cost(int64_t value) {
  
  _impl_.hour_cost_ = value;
}
inline void Stats::set_hour_cost(int64_t value) {
  _internal_set_hour_cost(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.hour_cost)
}

// int64 acc_show = 8;
inline void Stats::clear_acc_show() {
  _impl_.acc_show_ = int64_t{0};
}
inline int64_t Stats::_internal_acc_show() const {
  return _impl_.acc_show_;
}
inline int64_t Stats::acc_show() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.acc_show)
  return _internal_acc_show();
}
inline void Stats::_internal_set_acc_show(int64_t value) {
  
  _impl_.acc_show_ = value;
}
inline void Stats::set_acc_show(int64_t value) {
  _internal_set_acc_show(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.acc_show)
}

// int64 acc_click = 9;
inline void Stats::clear_acc_click() {
  _impl_.acc_click_ = int64_t{0};
}
inline int64_t Stats::_internal_acc_click() const {
  return _impl_.acc_click_;
}
inline int64_t Stats::acc_click() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.acc_click)
  return _internal_acc_click();
}
inline void Stats::_internal_set_acc_click(int64_t value) {
  
  _impl_.acc_click_ = value;
}
inline void Stats::set_acc_click(int64_t value) {
  _internal_set_acc_click(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.acc_click)
}

// int64 acc_cost = 10;
inline void Stats::clear_acc_cost() {
  _impl_.acc_cost_ = int64_t{0};
}
inline int64_t Stats::_internal_acc_cost() const {
  return _impl_.acc_cost_;
}
inline int64_t Stats::acc_cost() const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.acc_cost)
  return _internal_acc_cost();
}
inline void Stats::_internal_set_acc_cost(int64_t value) {
  
  _impl_.acc_cost_ = value;
}
inline void Stats::set_acc_cost(int64_t value) {
  _internal_set_acc_cost(value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.acc_cost)
}

// repeated int64 bucket = 11;
inline int Stats::_internal_bucket_size() const {
  return _impl_.bucket_.size();
}
inline int Stats::bucket_size() const {
  return _internal_bucket_size();
}
inline void Stats::clear_bucket() {
  _impl_.bucket_.Clear();
}
inline int64_t Stats::_internal_bucket(int index) const {
  return _impl_.bucket_.Get(index);
}
inline int64_t Stats::bucket(int index) const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.bucket)
  return _internal_bucket(index);
}
inline void Stats::set_bucket(int index, int64_t value) {
  _impl_.bucket_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.bucket)
}
inline void Stats::_internal_add_bucket(int64_t value) {
  _impl_.bucket_.Add(value);
}
inline void Stats::add_bucket(int64_t value) {
  _internal_add_bucket(value);
  // @@protoc_insertion_point(field_add:proto.ad.Stats.bucket)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::_internal_bucket() const {
  return _impl_.bucket_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::bucket() const {
  // @@protoc_insertion_point(field_list:proto.ad.Stats.bucket)
  return _internal_bucket();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::_internal_mutable_bucket() {
  return &_impl_.bucket_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::mutable_bucket() {
  // @@protoc_insertion_point(field_mutable_list:proto.ad.Stats.bucket)
  return _internal_mutable_bucket();
}

// repeated int64 hour_bucket = 12;
inline int Stats::_internal_hour_bucket_size() const {
  return _impl_.hour_bucket_.size();
}
inline int Stats::hour_bucket_size() const {
  return _internal_hour_bucket_size();
}
inline void Stats::clear_hour_bucket() {
  _impl_.hour_bucket_.Clear();
}
inline int64_t Stats::_internal_hour_bucket(int index) const {
  return _impl_.hour_bucket_.Get(index);
}
inline int64_t Stats::hour_bucket(int index) const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.hour_bucket)
  return _internal_hour_bucket(index);
}
inline void Stats::set_hour_bucket(int index, int64_t value) {
  _impl_.hour_bucket_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.hour_bucket)
}
inline void Stats::_internal_add_hour_bucket(int64_t value) {
  _impl_.hour_bucket_.Add(value);
}
inline void Stats::add_hour_bucket(int64_t value) {
  _internal_add_hour_bucket(value);
  // @@protoc_insertion_point(field_add:proto.ad.Stats.hour_bucket)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::_internal_hour_bucket() const {
  return _impl_.hour_bucket_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::hour_bucket() const {
  // @@protoc_insertion_point(field_list:proto.ad.Stats.hour_bucket)
  return _internal_hour_bucket();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::_internal_mutable_hour_bucket() {
  return &_impl_.hour_bucket_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::mutable_hour_bucket() {
  // @@protoc_insertion_point(field_mutable_list:proto.ad.Stats.hour_bucket)
  return _internal_mutable_hour_bucket();
}

// repeated int64 acc_bucket = 13;
inline int Stats::_internal_acc_bucket_size() const {
  return _impl_.acc_bucket_.size();
}
inline int Stats::acc_bucket_size() const {
  return _internal_acc_bucket_size();
}
inline void Stats::clear_acc_bucket() {
  _impl_.acc_bucket_.Clear();
}
inline int64_t Stats::_internal_acc_bucket(int index) const {
  return _impl_.acc_bucket_.Get(index);
}
inline int64_t Stats::acc_bucket(int index) const {
  // @@protoc_insertion_point(field_get:proto.ad.Stats.acc_bucket)
  return _internal_acc_bucket(index);
}
inline void Stats::set_acc_bucket(int index, int64_t value) {
  _impl_.acc_bucket_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.ad.Stats.acc_bucket)
}
inline void Stats::_internal_add_acc_bucket(int64_t value) {
  _impl_.acc_bucket_.Add(value);
}
inline void Stats::add_acc_bucket(int64_t value) {
  _internal_add_acc_bucket(value);
  // @@protoc_insertion_point(field_add:proto.ad.Stats.acc_bucket)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::_internal_acc_bucket() const {
  return _impl_.acc_bucket_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
Stats::acc_bucket() const {
  // @@protoc_insertion_point(field_list:proto.ad.Stats.acc_bucket)
  return _internal_acc_bucket();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::_internal_mutable_acc_bucket() {
  return &_impl_.acc_bucket_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
Stats::mutable_acc_bucket() {
  // @@protoc_insertion_point(field_mutable_list:proto.ad.Stats.acc_bucket)
  return _internal_mutable_acc_bucket();
}

// -------------------------------------------------------------------

// StatsOpt

// int64 ts = 1;
inline void StatsOpt::clear_ts() {
  _impl_.ts_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_ts() const {
  return _impl_.ts_;
}
inline int64_t StatsOpt::ts() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.ts)
  return _internal_ts();
}
inline void StatsOpt::_internal_set_ts(int64_t value) {
  
  _impl_.ts_ = value;
}
inline void StatsOpt::set_ts(int64_t value) {
  _internal_set_ts(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.ts)
}

// int64 show = 2;
inline void StatsOpt::clear_show() {
  _impl_.show_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_show() const {
  return _impl_.show_;
}
inline int64_t StatsOpt::show() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.show)
  return _internal_show();
}
inline void StatsOpt::_internal_set_show(int64_t value) {
  
  _impl_.show_ = value;
}
inline void StatsOpt::set_show(int64_t value) {
  _internal_set_show(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.show)
}

// int64 click = 3;
inline void StatsOpt::clear_click() {
  _impl_.click_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_click() const {
  return _impl_.click_;
}
inline int64_t StatsOpt::click() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.click)
  return _internal_click();
}
inline void StatsOpt::_internal_set_click(int64_t value) {
  
  _impl_.click_ = value;
}
inline void StatsOpt::set_click(int64_t value) {
  _internal_set_click(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.click)
}

// int64 cost = 4;
inline void StatsOpt::clear_cost() {
  _impl_.cost_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_cost() const {
  return _impl_.cost_;
}
inline int64_t StatsOpt::cost() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.cost)
  return _internal_cost();
}
inline void StatsOpt::_internal_set_cost(int64_t value) {
  
  _impl_.cost_ = value;
}
inline void StatsOpt::set_cost(int64_t value) {
  _internal_set_cost(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.cost)
}

// int64 hour_show = 5;
inline void StatsOpt::clear_hour_show() {
  _impl_.hour_show_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_hour_show() const {
  return _impl_.hour_show_;
}
inline int64_t StatsOpt::hour_show() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.hour_show)
  return _internal_hour_show();
}
inline void StatsOpt::_internal_set_hour_show(int64_t value) {
  
  _impl_.hour_show_ = value;
}
inline void StatsOpt::set_hour_show(int64_t value) {
  _internal_set_hour_show(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.hour_show)
}

// int64 hour_click = 6;
inline void StatsOpt::clear_hour_click() {
  _impl_.hour_click_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_hour_click() const {
  return _impl_.hour_click_;
}
inline int64_t StatsOpt::hour_click() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.hour_click)
  return _internal_hour_click();
}
inline void StatsOpt::_internal_set_hour_click(int64_t value) {
  
  _impl_.hour_click_ = value;
}
inline void StatsOpt::set_hour_click(int64_t value) {
  _internal_set_hour_click(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.hour_click)
}

// int64 hour_cost = 7;
inline void StatsOpt::clear_hour_cost() {
  _impl_.hour_cost_ = int64_t{0};
}
inline int64_t StatsOpt::_internal_hour_cost() const {
  return _impl_.hour_cost_;
}
inline int64_t StatsOpt::hour_cost() const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.hour_cost)
  return _internal_hour_cost();
}
inline void StatsOpt::_internal_set_hour_cost(int64_t value) {
  
  _impl_.hour_cost_ = value;
}
inline void StatsOpt::set_hour_cost(int64_t value) {
  _internal_set_hour_cost(value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.hour_cost)
}

// repeated int64 bucket = 11;
inline int StatsOpt::_internal_bucket_size() const {
  return _impl_.bucket_.size();
}
inline int StatsOpt::bucket_size() const {
  return _internal_bucket_size();
}
inline void StatsOpt::clear_bucket() {
  _impl_.bucket_.Clear();
}
inline int64_t StatsOpt::_internal_bucket(int index) const {
  return _impl_.bucket_.Get(index);
}
inline int64_t StatsOpt::bucket(int index) const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.bucket)
  return _internal_bucket(index);
}
inline void StatsOpt::set_bucket(int index, int64_t value) {
  _impl_.bucket_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.bucket)
}
inline void StatsOpt::_internal_add_bucket(int64_t value) {
  _impl_.bucket_.Add(value);
}
inline void StatsOpt::add_bucket(int64_t value) {
  _internal_add_bucket(value);
  // @@protoc_insertion_point(field_add:proto.ad.StatsOpt.bucket)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
StatsOpt::_internal_bucket() const {
  return _impl_.bucket_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
StatsOpt::bucket() const {
  // @@protoc_insertion_point(field_list:proto.ad.StatsOpt.bucket)
  return _internal_bucket();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
StatsOpt::_internal_mutable_bucket() {
  return &_impl_.bucket_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
StatsOpt::mutable_bucket() {
  // @@protoc_insertion_point(field_mutable_list:proto.ad.StatsOpt.bucket)
  return _internal_mutable_bucket();
}

// repeated int64 hour_bucket = 12;
inline int StatsOpt::_internal_hour_bucket_size() const {
  return _impl_.hour_bucket_.size();
}
inline int StatsOpt::hour_bucket_size() const {
  return _internal_hour_bucket_size();
}
inline void StatsOpt::clear_hour_bucket() {
  _impl_.hour_bucket_.Clear();
}
inline int64_t StatsOpt::_internal_hour_bucket(int index) const {
  return _impl_.hour_bucket_.Get(index);
}
inline int64_t StatsOpt::hour_bucket(int index) const {
  // @@protoc_insertion_point(field_get:proto.ad.StatsOpt.hour_bucket)
  return _internal_hour_bucket(index);
}
inline void StatsOpt::set_hour_bucket(int index, int64_t value) {
  _impl_.hour_bucket_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.ad.StatsOpt.hour_bucket)
}
inline void StatsOpt::_internal_add_hour_bucket(int64_t value) {
  _impl_.hour_bucket_.Add(value);
}
inline void StatsOpt::add_hour_bucket(int64_t value) {
  _internal_add_hour_bucket(value);
  // @@protoc_insertion_point(field_add:proto.ad.StatsOpt.hour_bucket)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
StatsOpt::_internal_hour_bucket() const {
  return _impl_.hour_bucket_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
StatsOpt::hour_bucket() const {
  // @@protoc_insertion_point(field_list:proto.ad.StatsOpt.hour_bucket)
  return _internal_hour_bucket();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
StatsOpt::_internal_mutable_hour_bucket() {
  return &_impl_.hour_bucket_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
StatsOpt::mutable_hour_bucket() {
  // @@protoc_insertion_point(field_mutable_list:proto.ad.StatsOpt.hour_bucket)
  return _internal_mutable_hour_bucket();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ad
}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2fstats_2eproto
