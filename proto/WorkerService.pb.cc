// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/WorkerService.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/WorkerService.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace fdis {

namespace {

const ::google::protobuf::Descriptor* WriteBuffer_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  WriteBuffer_reflection_ = NULL;
const ::google::protobuf::Descriptor* WriteResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  WriteResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* WorkerService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fWorkerService_2eproto() {
  protobuf_AddDesc_proto_2fWorkerService_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/WorkerService.proto");
  GOOGLE_CHECK(file != NULL);
  WriteBuffer_descriptor_ = file->message_type(0);
  static const int WriteBuffer_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteBuffer, len_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteBuffer, buffer_),
  };
  WriteBuffer_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      WriteBuffer_descriptor_,
      WriteBuffer::default_instance_,
      WriteBuffer_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteBuffer, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteBuffer, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(WriteBuffer));
  WriteResponse_descriptor_ = file->message_type(1);
  static const int WriteResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteResponse, len_),
  };
  WriteResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      WriteResponse_descriptor_,
      WriteResponse::default_instance_,
      WriteResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WriteResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(WriteResponse));
  WorkerService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fWorkerService_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    WriteBuffer_descriptor_, &WriteBuffer::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    WriteResponse_descriptor_, &WriteResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fWorkerService_2eproto() {
  delete WriteBuffer::default_instance_;
  delete WriteBuffer_reflection_;
  delete WriteResponse::default_instance_;
  delete WriteResponse_reflection_;
}

void protobuf_AddDesc_proto_2fWorkerService_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::fdis::protobuf_AddDesc_proto_2fheartbeat_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\031proto/WorkerService.proto\022\004fdis\032\025proto"
    "/heartbeat.proto\"*\n\013WriteBuffer\022\013\n\003len\030\001"
    " \002(\004\022\016\n\006buffer\030\002 \002(\014\"\034\n\rWriteResponse\022\013\n"
    "\003len\030\001 \002(\0042H\n\rWorkerService\0227\n\004echo\022\026.fd"
    "is.HeartbeatRequest\032\027.fdis.HeartbeatResp"
    "onseB\003\200\001\001", 209);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/WorkerService.proto", &protobuf_RegisterTypes);
  WriteBuffer::default_instance_ = new WriteBuffer();
  WriteResponse::default_instance_ = new WriteResponse();
  WriteBuffer::default_instance_->InitAsDefaultInstance();
  WriteResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fWorkerService_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fWorkerService_2eproto {
  StaticDescriptorInitializer_proto_2fWorkerService_2eproto() {
    protobuf_AddDesc_proto_2fWorkerService_2eproto();
  }
} static_descriptor_initializer_proto_2fWorkerService_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int WriteBuffer::kLenFieldNumber;
const int WriteBuffer::kBufferFieldNumber;
#endif  // !_MSC_VER

WriteBuffer::WriteBuffer()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:fdis.WriteBuffer)
}

void WriteBuffer::InitAsDefaultInstance() {
}

WriteBuffer::WriteBuffer(const WriteBuffer& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:fdis.WriteBuffer)
}

void WriteBuffer::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  len_ = GOOGLE_ULONGLONG(0);
  buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

WriteBuffer::~WriteBuffer() {
  // @@protoc_insertion_point(destructor:fdis.WriteBuffer)
  SharedDtor();
}

void WriteBuffer::SharedDtor() {
  if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete buffer_;
  }
  if (this != default_instance_) {
  }
}

void WriteBuffer::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* WriteBuffer::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return WriteBuffer_descriptor_;
}

const WriteBuffer& WriteBuffer::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fWorkerService_2eproto();
  return *default_instance_;
}

WriteBuffer* WriteBuffer::default_instance_ = NULL;

WriteBuffer* WriteBuffer::New() const {
  return new WriteBuffer;
}

void WriteBuffer::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    len_ = GOOGLE_ULONGLONG(0);
    if (has_buffer()) {
      if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        buffer_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool WriteBuffer::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:fdis.WriteBuffer)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 len = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &len_)));
          set_has_len();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_buffer;
        break;
      }

      // required bytes buffer = 2;
      case 2: {
        if (tag == 18) {
         parse_buffer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_buffer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:fdis.WriteBuffer)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:fdis.WriteBuffer)
  return false;
#undef DO_
}

void WriteBuffer::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:fdis.WriteBuffer)
  // required uint64 len = 1;
  if (has_len()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->len(), output);
  }

  // required bytes buffer = 2;
  if (has_buffer()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->buffer(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:fdis.WriteBuffer)
}

::google::protobuf::uint8* WriteBuffer::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:fdis.WriteBuffer)
  // required uint64 len = 1;
  if (has_len()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->len(), target);
  }

  // required bytes buffer = 2;
  if (has_buffer()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->buffer(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fdis.WriteBuffer)
  return target;
}

int WriteBuffer::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 len = 1;
    if (has_len()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->len());
    }

    // required bytes buffer = 2;
    if (has_buffer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->buffer());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void WriteBuffer::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const WriteBuffer* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const WriteBuffer*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void WriteBuffer::MergeFrom(const WriteBuffer& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_len()) {
      set_len(from.len());
    }
    if (from.has_buffer()) {
      set_buffer(from.buffer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void WriteBuffer::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WriteBuffer::CopyFrom(const WriteBuffer& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WriteBuffer::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void WriteBuffer::Swap(WriteBuffer* other) {
  if (other != this) {
    std::swap(len_, other->len_);
    std::swap(buffer_, other->buffer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata WriteBuffer::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = WriteBuffer_descriptor_;
  metadata.reflection = WriteBuffer_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int WriteResponse::kLenFieldNumber;
#endif  // !_MSC_VER

WriteResponse::WriteResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:fdis.WriteResponse)
}

void WriteResponse::InitAsDefaultInstance() {
}

WriteResponse::WriteResponse(const WriteResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:fdis.WriteResponse)
}

void WriteResponse::SharedCtor() {
  _cached_size_ = 0;
  len_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

WriteResponse::~WriteResponse() {
  // @@protoc_insertion_point(destructor:fdis.WriteResponse)
  SharedDtor();
}

void WriteResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void WriteResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* WriteResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return WriteResponse_descriptor_;
}

const WriteResponse& WriteResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fWorkerService_2eproto();
  return *default_instance_;
}

WriteResponse* WriteResponse::default_instance_ = NULL;

WriteResponse* WriteResponse::New() const {
  return new WriteResponse;
}

void WriteResponse::Clear() {
  len_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool WriteResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:fdis.WriteResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 len = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &len_)));
          set_has_len();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:fdis.WriteResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:fdis.WriteResponse)
  return false;
#undef DO_
}

void WriteResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:fdis.WriteResponse)
  // required uint64 len = 1;
  if (has_len()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->len(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:fdis.WriteResponse)
}

::google::protobuf::uint8* WriteResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:fdis.WriteResponse)
  // required uint64 len = 1;
  if (has_len()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->len(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fdis.WriteResponse)
  return target;
}

int WriteResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 len = 1;
    if (has_len()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->len());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void WriteResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const WriteResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const WriteResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void WriteResponse::MergeFrom(const WriteResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_len()) {
      set_len(from.len());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void WriteResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WriteResponse::CopyFrom(const WriteResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WriteResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void WriteResponse::Swap(WriteResponse* other) {
  if (other != this) {
    std::swap(len_, other->len_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata WriteResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = WriteResponse_descriptor_;
  metadata.reflection = WriteResponse_reflection_;
  return metadata;
}


// ===================================================================

WorkerService::~WorkerService() {}

const ::google::protobuf::ServiceDescriptor* WorkerService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return WorkerService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* WorkerService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return WorkerService_descriptor_;
}

void WorkerService::echo(::google::protobuf::RpcController* controller,
                         const ::fdis::HeartbeatRequest*,
                         ::fdis::HeartbeatResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method echo() not implemented.");
  done->Run();
}

void WorkerService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), WorkerService_descriptor_);
  switch(method->index()) {
    case 0:
      echo(controller,
             ::google::protobuf::down_cast<const ::fdis::HeartbeatRequest*>(request),
             ::google::protobuf::down_cast< ::fdis::HeartbeatResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& WorkerService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fdis::HeartbeatRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& WorkerService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fdis::HeartbeatResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

WorkerService_Stub::WorkerService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
WorkerService_Stub::WorkerService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
WorkerService_Stub::~WorkerService_Stub() {
  if (owns_channel_) delete channel_;
}

void WorkerService_Stub::echo(::google::protobuf::RpcController* controller,
                              const ::fdis::HeartbeatRequest* request,
                              ::fdis::HeartbeatResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace fdis

// @@protoc_insertion_point(global_scope)