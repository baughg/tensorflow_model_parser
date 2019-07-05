// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: saved_model.proto

#include "saved_model.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace tensorflow {
class SavedModelDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SavedModel>
      _instance;
} _SavedModel_default_instance_;
}  // namespace tensorflow
namespace protobuf_saved_5fmodel_2eproto {
void InitDefaultsSavedModelImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_meta_5fgraph_2eproto::InitDefaultsMetaGraphDef();
  {
    void* ptr = &::tensorflow::_SavedModel_default_instance_;
    new (ptr) ::tensorflow::SavedModel();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::SavedModel::InitAsDefaultInstance();
}

void InitDefaultsSavedModel() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSavedModelImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::tensorflow::SavedModel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::tensorflow::SavedModel, saved_model_schema_version_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::tensorflow::SavedModel, meta_graphs_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::tensorflow::SavedModel)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::tensorflow::_SavedModel_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "saved_model.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\021saved_model.proto\022\ntensorflow\032\020meta_gr"
      "aph.proto\"_\n\nSavedModel\022\"\n\032saved_model_s"
      "chema_version\030\001 \001(\003\022-\n\013meta_graphs\030\002 \003(\013"
      "2\030.tensorflow.MetaGraphDefBo\n\030org.tensor"
      "flow.frameworkB\020SavedModelProtosP\001Z<gith"
      "ub.com/tensorflow/tensorflow/tensorflow/"
      "go/core/protobuf\370\001\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 267);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "saved_model.proto", &protobuf_RegisterTypes);
  ::protobuf_meta_5fgraph_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_saved_5fmodel_2eproto
namespace tensorflow {

// ===================================================================

void SavedModel::InitAsDefaultInstance() {
}
void SavedModel::clear_meta_graphs() {
  meta_graphs_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SavedModel::kSavedModelSchemaVersionFieldNumber;
const int SavedModel::kMetaGraphsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SavedModel::SavedModel()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_saved_5fmodel_2eproto::InitDefaultsSavedModel();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.SavedModel)
}
SavedModel::SavedModel(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena),
  meta_graphs_(arena) {
  ::protobuf_saved_5fmodel_2eproto::InitDefaultsSavedModel();
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.SavedModel)
}
SavedModel::SavedModel(const SavedModel& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      meta_graphs_(from.meta_graphs_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  saved_model_schema_version_ = from.saved_model_schema_version_;
  // @@protoc_insertion_point(copy_constructor:tensorflow.SavedModel)
}

void SavedModel::SharedCtor() {
  saved_model_schema_version_ = GOOGLE_LONGLONG(0);
  _cached_size_ = 0;
}

SavedModel::~SavedModel() {
  // @@protoc_insertion_point(destructor:tensorflow.SavedModel)
  SharedDtor();
}

void SavedModel::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == NULL);
}

void SavedModel::ArenaDtor(void* object) {
  SavedModel* _this = reinterpret_cast< SavedModel* >(object);
  (void)_this;
}
void SavedModel::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void SavedModel::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SavedModel::descriptor() {
  ::protobuf_saved_5fmodel_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_saved_5fmodel_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SavedModel& SavedModel::default_instance() {
  ::protobuf_saved_5fmodel_2eproto::InitDefaultsSavedModel();
  return *internal_default_instance();
}

SavedModel* SavedModel::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<SavedModel>(arena);
}

void SavedModel::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.SavedModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  meta_graphs_.Clear();
  saved_model_schema_version_ = GOOGLE_LONGLONG(0);
  _internal_metadata_.Clear();
}

bool SavedModel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.SavedModel)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int64 saved_model_schema_version = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &saved_model_schema_version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .tensorflow.MetaGraphDef meta_graphs = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_meta_graphs()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.SavedModel)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.SavedModel)
  return false;
#undef DO_
}

void SavedModel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.SavedModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 saved_model_schema_version = 1;
  if (this->saved_model_schema_version() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->saved_model_schema_version(), output);
  }

  // repeated .tensorflow.MetaGraphDef meta_graphs = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->meta_graphs_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->meta_graphs(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.SavedModel)
}

::google::protobuf::uint8* SavedModel::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.SavedModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 saved_model_schema_version = 1;
  if (this->saved_model_schema_version() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->saved_model_schema_version(), target);
  }

  // repeated .tensorflow.MetaGraphDef meta_graphs = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->meta_graphs_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->meta_graphs(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.SavedModel)
  return target;
}

size_t SavedModel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.SavedModel)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .tensorflow.MetaGraphDef meta_graphs = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->meta_graphs_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->meta_graphs(static_cast<int>(i)));
    }
  }

  // int64 saved_model_schema_version = 1;
  if (this->saved_model_schema_version() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->saved_model_schema_version());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SavedModel::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.SavedModel)
  GOOGLE_DCHECK_NE(&from, this);
  const SavedModel* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SavedModel>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.SavedModel)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.SavedModel)
    MergeFrom(*source);
  }
}

void SavedModel::MergeFrom(const SavedModel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.SavedModel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  meta_graphs_.MergeFrom(from.meta_graphs_);
  if (from.saved_model_schema_version() != 0) {
    set_saved_model_schema_version(from.saved_model_schema_version());
  }
}

void SavedModel::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.SavedModel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SavedModel::CopyFrom(const SavedModel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.SavedModel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SavedModel::IsInitialized() const {
  return true;
}

void SavedModel::Swap(SavedModel* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    SavedModel* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == NULL) {
      delete temp;
    }
  }
}
void SavedModel::UnsafeArenaSwap(SavedModel* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void SavedModel::InternalSwap(SavedModel* other) {
  using std::swap;
  meta_graphs_.InternalSwap(&other->meta_graphs_);
  swap(saved_model_schema_version_, other->saved_model_schema_version_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SavedModel::GetMetadata() const {
  protobuf_saved_5fmodel_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_saved_5fmodel_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)