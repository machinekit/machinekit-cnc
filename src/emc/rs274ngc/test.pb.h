// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_machinetalk_2fprotobuf_2ftest_2eproto__INCLUDED
#define PROTOBUF_machinetalk_2fprotobuf_2ftest_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "emcclass.pb.h"
#include "nanopb.pb.h"
// @@protoc_insertion_point(includes)

namespace machinetalk {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_machinetalk_2fprotobuf_2ftest_2eproto();
void protobuf_AssignDesc_machinetalk_2fprotobuf_2ftest_2eproto();
void protobuf_ShutdownFile_machinetalk_2fprotobuf_2ftest_2eproto();

class Test1;
class Test2;
class Test3;

enum TestOpType {
  LINE = 10,
  CIRCLE = 20
};
bool TestOpType_IsValid(int value);
const TestOpType TestOpType_MIN = LINE;
const TestOpType TestOpType_MAX = CIRCLE;
const int TestOpType_ARRAYSIZE = TestOpType_MAX + 1;

const ::google::protobuf::EnumDescriptor* TestOpType_descriptor();
inline const ::std::string& TestOpType_Name(TestOpType value) {
  return ::google::protobuf::internal::NameOfEnum(
    TestOpType_descriptor(), value);
}
inline bool TestOpType_Parse(
    const ::std::string& name, TestOpType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TestOpType>(
    TestOpType_descriptor(), name, value);
}
// ===================================================================

class Test1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:machinetalk.Test1) */ {
 public:
  Test1();
  virtual ~Test1();

  Test1(const Test1& from);

  inline Test1& operator=(const Test1& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Test1& default_instance();

  void Swap(Test1* other);

  // implements Message ----------------------------------------------

  inline Test1* New() const { return New(NULL); }

  Test1* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Test1& from);
  void MergeFrom(const Test1& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Test1* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .machinetalk.TestOpType op = 10;
  bool has_op() const;
  void clear_op();
  static const int kOpFieldNumber = 10;
  ::machinetalk::TestOpType op() const;
  void set_op(::machinetalk::TestOpType value);

  // required .machinetalk.EmcPose end = 20;
  bool has_end() const;
  void clear_end();
  static const int kEndFieldNumber = 20;
  const ::machinetalk::EmcPose& end() const;
  ::machinetalk::EmcPose* mutable_end();
  ::machinetalk::EmcPose* release_end();
  void set_allocated_end(::machinetalk::EmcPose* end);

  // optional .machinetalk.PmCartesian center = 30;
  bool has_center() const;
  void clear_center();
  static const int kCenterFieldNumber = 30;
  const ::machinetalk::PmCartesian& center() const;
  ::machinetalk::PmCartesian* mutable_center();
  ::machinetalk::PmCartesian* release_center();
  void set_allocated_center(::machinetalk::PmCartesian* center);

  // optional .machinetalk.PmCartesian normal = 40;
  bool has_normal() const;
  void clear_normal();
  static const int kNormalFieldNumber = 40;
  const ::machinetalk::PmCartesian& normal() const;
  ::machinetalk::PmCartesian* mutable_normal();
  ::machinetalk::PmCartesian* release_normal();
  void set_allocated_normal(::machinetalk::PmCartesian* normal);

  // optional int32 turn = 50;
  bool has_turn() const;
  void clear_turn();
  static const int kTurnFieldNumber = 50;
  ::google::protobuf::int32 turn() const;
  void set_turn(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:machinetalk.Test1)
 private:
  inline void set_has_op();
  inline void clear_has_op();
  inline void set_has_end();
  inline void clear_has_end();
  inline void set_has_center();
  inline void clear_has_center();
  inline void set_has_normal();
  inline void clear_has_normal();
  inline void set_has_turn();
  inline void clear_has_turn();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::machinetalk::EmcPose* end_;
  ::machinetalk::PmCartesian* center_;
  int op_;
  ::google::protobuf::int32 turn_;
  ::machinetalk::PmCartesian* normal_;
  friend void  protobuf_AddDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_AssignDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_ShutdownFile_machinetalk_2fprotobuf_2ftest_2eproto();

  void InitAsDefaultInstance();
  static Test1* default_instance_;
};
// -------------------------------------------------------------------

class Test2 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:machinetalk.Test2) */ {
 public:
  Test2();
  virtual ~Test2();

  Test2(const Test2& from);

  inline Test2& operator=(const Test2& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Test2& default_instance();

  void Swap(Test2* other);

  // implements Message ----------------------------------------------

  inline Test2* New() const { return New(NULL); }

  Test2* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Test2& from);
  void MergeFrom(const Test2& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Test2* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:machinetalk.Test2)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_AssignDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_ShutdownFile_machinetalk_2fprotobuf_2ftest_2eproto();

  void InitAsDefaultInstance();
  static Test2* default_instance_;
};
// -------------------------------------------------------------------

class Test3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:machinetalk.Test3) */ {
 public:
  Test3();
  virtual ~Test3();

  Test3(const Test3& from);

  inline Test3& operator=(const Test3& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Test3& default_instance();

  void Swap(Test3* other);

  // implements Message ----------------------------------------------

  inline Test3* New() const { return New(NULL); }

  Test3* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Test3& from);
  void MergeFrom(const Test3& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Test3* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:machinetalk.Test3)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_AssignDesc_machinetalk_2fprotobuf_2ftest_2eproto();
  friend void protobuf_ShutdownFile_machinetalk_2fprotobuf_2ftest_2eproto();

  void InitAsDefaultInstance();
  static Test3* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Test1

// required .machinetalk.TestOpType op = 10;
inline bool Test1::has_op() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Test1::set_has_op() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Test1::clear_has_op() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Test1::clear_op() {
  op_ = 10;
  clear_has_op();
}
inline ::machinetalk::TestOpType Test1::op() const {
  // @@protoc_insertion_point(field_get:machinetalk.Test1.op)
  return static_cast< ::machinetalk::TestOpType >(op_);
}
inline void Test1::set_op(::machinetalk::TestOpType value) {
  assert(::machinetalk::TestOpType_IsValid(value));
  set_has_op();
  op_ = value;
  // @@protoc_insertion_point(field_set:machinetalk.Test1.op)
}

// required .machinetalk.EmcPose end = 20;
inline bool Test1::has_end() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Test1::set_has_end() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Test1::clear_has_end() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Test1::clear_end() {
  if (end_ != NULL) end_->::machinetalk::EmcPose::Clear();
  clear_has_end();
}
inline const ::machinetalk::EmcPose& Test1::end() const {
  // @@protoc_insertion_point(field_get:machinetalk.Test1.end)
  return end_ != NULL ? *end_ : *default_instance_->end_;
}
inline ::machinetalk::EmcPose* Test1::mutable_end() {
  set_has_end();
  if (end_ == NULL) {
    end_ = new ::machinetalk::EmcPose;
  }
  // @@protoc_insertion_point(field_mutable:machinetalk.Test1.end)
  return end_;
}
inline ::machinetalk::EmcPose* Test1::release_end() {
  // @@protoc_insertion_point(field_release:machinetalk.Test1.end)
  clear_has_end();
  ::machinetalk::EmcPose* temp = end_;
  end_ = NULL;
  return temp;
}
inline void Test1::set_allocated_end(::machinetalk::EmcPose* end) {
  delete end_;
  end_ = end;
  if (end) {
    set_has_end();
  } else {
    clear_has_end();
  }
  // @@protoc_insertion_point(field_set_allocated:machinetalk.Test1.end)
}

// optional .machinetalk.PmCartesian center = 30;
inline bool Test1::has_center() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Test1::set_has_center() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Test1::clear_has_center() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Test1::clear_center() {
  if (center_ != NULL) center_->::machinetalk::PmCartesian::Clear();
  clear_has_center();
}
inline const ::machinetalk::PmCartesian& Test1::center() const {
  // @@protoc_insertion_point(field_get:machinetalk.Test1.center)
  return center_ != NULL ? *center_ : *default_instance_->center_;
}
inline ::machinetalk::PmCartesian* Test1::mutable_center() {
  set_has_center();
  if (center_ == NULL) {
    center_ = new ::machinetalk::PmCartesian;
  }
  // @@protoc_insertion_point(field_mutable:machinetalk.Test1.center)
  return center_;
}
inline ::machinetalk::PmCartesian* Test1::release_center() {
  // @@protoc_insertion_point(field_release:machinetalk.Test1.center)
  clear_has_center();
  ::machinetalk::PmCartesian* temp = center_;
  center_ = NULL;
  return temp;
}
inline void Test1::set_allocated_center(::machinetalk::PmCartesian* center) {
  delete center_;
  center_ = center;
  if (center) {
    set_has_center();
  } else {
    clear_has_center();
  }
  // @@protoc_insertion_point(field_set_allocated:machinetalk.Test1.center)
}

// optional .machinetalk.PmCartesian normal = 40;
inline bool Test1::has_normal() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Test1::set_has_normal() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Test1::clear_has_normal() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Test1::clear_normal() {
  if (normal_ != NULL) normal_->::machinetalk::PmCartesian::Clear();
  clear_has_normal();
}
inline const ::machinetalk::PmCartesian& Test1::normal() const {
  // @@protoc_insertion_point(field_get:machinetalk.Test1.normal)
  return normal_ != NULL ? *normal_ : *default_instance_->normal_;
}
inline ::machinetalk::PmCartesian* Test1::mutable_normal() {
  set_has_normal();
  if (normal_ == NULL) {
    normal_ = new ::machinetalk::PmCartesian;
  }
  // @@protoc_insertion_point(field_mutable:machinetalk.Test1.normal)
  return normal_;
}
inline ::machinetalk::PmCartesian* Test1::release_normal() {
  // @@protoc_insertion_point(field_release:machinetalk.Test1.normal)
  clear_has_normal();
  ::machinetalk::PmCartesian* temp = normal_;
  normal_ = NULL;
  return temp;
}
inline void Test1::set_allocated_normal(::machinetalk::PmCartesian* normal) {
  delete normal_;
  normal_ = normal;
  if (normal) {
    set_has_normal();
  } else {
    clear_has_normal();
  }
  // @@protoc_insertion_point(field_set_allocated:machinetalk.Test1.normal)
}

// optional int32 turn = 50;
inline bool Test1::has_turn() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Test1::set_has_turn() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Test1::clear_has_turn() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Test1::clear_turn() {
  turn_ = 0;
  clear_has_turn();
}
inline ::google::protobuf::int32 Test1::turn() const {
  // @@protoc_insertion_point(field_get:machinetalk.Test1.turn)
  return turn_;
}
inline void Test1::set_turn(::google::protobuf::int32 value) {
  set_has_turn();
  turn_ = value;
  // @@protoc_insertion_point(field_set:machinetalk.Test1.turn)
}

// -------------------------------------------------------------------

// Test2

// -------------------------------------------------------------------

// Test3

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace machinetalk

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::machinetalk::TestOpType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::machinetalk::TestOpType>() {
  return ::machinetalk::TestOpType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_machinetalk_2fprotobuf_2ftest_2eproto__INCLUDED