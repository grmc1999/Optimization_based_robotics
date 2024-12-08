// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ob_robotics_interface/msg/detail/optimization_data__functions.h"
#include "ob_robotics_interface/msg/detail/optimization_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ob_robotics_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void OptimizationData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ob_robotics_interface::msg::OptimizationData(_init);
}

void OptimizationData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ob_robotics_interface::msg::OptimizationData *>(message_memory);
  typed_message->~OptimizationData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OptimizationData_message_member_array[3] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::OptimizationData, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "loss",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::OptimizationData, loss),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "episode_end",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::OptimizationData, episode_end),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OptimizationData_message_members = {
  "ob_robotics_interface::msg",  // message namespace
  "OptimizationData",  // message name
  3,  // number of fields
  sizeof(ob_robotics_interface::msg::OptimizationData),
  false,  // has_any_key_member_
  OptimizationData_message_member_array,  // message members
  OptimizationData_init_function,  // function to initialize message memory (memory has to be allocated)
  OptimizationData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OptimizationData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OptimizationData_message_members,
  get_message_typesupport_handle_function,
  &ob_robotics_interface__msg__OptimizationData__get_type_hash,
  &ob_robotics_interface__msg__OptimizationData__get_type_description,
  &ob_robotics_interface__msg__OptimizationData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ob_robotics_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ob_robotics_interface::msg::OptimizationData>()
{
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::OptimizationData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ob_robotics_interface, msg, OptimizationData)() {
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::OptimizationData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
