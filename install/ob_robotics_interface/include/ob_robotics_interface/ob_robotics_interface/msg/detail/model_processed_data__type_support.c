// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ob_robotics_interface:msg/ModelProcessedData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ob_robotics_interface/msg/detail/model_processed_data__rosidl_typesupport_introspection_c.h"
#include "ob_robotics_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ob_robotics_interface/msg/detail/model_processed_data__functions.h"
#include "ob_robotics_interface/msg/detail/model_processed_data__struct.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `values`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ob_robotics_interface__msg__ModelProcessedData__init(message_memory);
}

void ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_fini_function(void * message_memory)
{
  ob_robotics_interface__msg__ModelProcessedData__fini(message_memory);
}

size_t ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__size_function__ModelProcessedData__values(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_const_function__ModelProcessedData__values(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_function__ModelProcessedData__values(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__fetch_function__ModelProcessedData__values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_const_function__ModelProcessedData__values(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__assign_function__ModelProcessedData__values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_function__ModelProcessedData__values(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__resize_function__ModelProcessedData__values(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_member_array[2] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface__msg__ModelProcessedData, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "values",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface__msg__ModelProcessedData, values),  // bytes offset in struct
    NULL,  // default value
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__size_function__ModelProcessedData__values,  // size() function pointer
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_const_function__ModelProcessedData__values,  // get_const(index) function pointer
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__get_function__ModelProcessedData__values,  // get(index) function pointer
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__fetch_function__ModelProcessedData__values,  // fetch(index, &value) function pointer
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__assign_function__ModelProcessedData__values,  // assign(index, value) function pointer
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__resize_function__ModelProcessedData__values  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_members = {
  "ob_robotics_interface__msg",  // message namespace
  "ModelProcessedData",  // message name
  2,  // number of fields
  sizeof(ob_robotics_interface__msg__ModelProcessedData),
  false,  // has_any_key_member_
  ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_member_array,  // message members
  ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_init_function,  // function to initialize message memory (memory has to be allocated)
  ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_type_support_handle = {
  0,
  &ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_members,
  get_message_typesupport_handle_function,
  &ob_robotics_interface__msg__ModelProcessedData__get_type_hash,
  &ob_robotics_interface__msg__ModelProcessedData__get_type_description,
  &ob_robotics_interface__msg__ModelProcessedData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ob_robotics_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ob_robotics_interface, msg, ModelProcessedData)() {
  ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_type_support_handle.typesupport_identifier) {
    ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ob_robotics_interface__msg__ModelProcessedData__rosidl_typesupport_introspection_c__ModelProcessedData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
