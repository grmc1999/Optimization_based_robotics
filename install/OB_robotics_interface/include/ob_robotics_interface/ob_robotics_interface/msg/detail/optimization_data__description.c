// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice

#include "ob_robotics_interface/msg/detail/optimization_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_type_hash_t *
ob_robotics_interface__msg__OptimizationData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0xe4, 0x83, 0x64, 0x92, 0xff, 0x10, 0xbf,
      0xfb, 0xa7, 0x72, 0xab, 0xd5, 0x06, 0xbb, 0x6d,
      0x36, 0x82, 0xc4, 0x0b, 0xf4, 0xee, 0xfb, 0x9b,
      0x48, 0x85, 0x9b, 0x25, 0xf9, 0xff, 0xec, 0x4e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
#endif

static char ob_robotics_interface__msg__OptimizationData__TYPE_NAME[] = "ob_robotics_interface/msg/OptimizationData";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";

// Define type names, field names, and default values
static char ob_robotics_interface__msg__OptimizationData__FIELD_NAME__timestamp[] = "timestamp";
static char ob_robotics_interface__msg__OptimizationData__FIELD_NAME__loss[] = "loss";
static char ob_robotics_interface__msg__OptimizationData__FIELD_NAME__episode_end[] = "episode_end";

static rosidl_runtime_c__type_description__Field ob_robotics_interface__msg__OptimizationData__FIELDS[] = {
  {
    {ob_robotics_interface__msg__OptimizationData__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {ob_robotics_interface__msg__OptimizationData__FIELD_NAME__loss, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ob_robotics_interface__msg__OptimizationData__FIELD_NAME__episode_end, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ob_robotics_interface__msg__OptimizationData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ob_robotics_interface__msg__OptimizationData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ob_robotics_interface__msg__OptimizationData__TYPE_NAME, 42, 42},
      {ob_robotics_interface__msg__OptimizationData__FIELDS, 3, 3},
    },
    {ob_robotics_interface__msg__OptimizationData__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "builtin_interfaces/Time timestamp\n"
  "float32 loss\n"
  "bool episode_end";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ob_robotics_interface__msg__OptimizationData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ob_robotics_interface__msg__OptimizationData__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ob_robotics_interface__msg__OptimizationData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ob_robotics_interface__msg__OptimizationData__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}