// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ob_robotics_interface/msg/detail/robot_model_interface__functions.h"
#include "ob_robotics_interface/msg/detail/robot_model_interface__struct.hpp"
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

void RobotModelInterface_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ob_robotics_interface::msg::RobotModelInterface(_init);
}

void RobotModelInterface_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ob_robotics_interface::msg::RobotModelInterface *>(message_memory);
  typed_message->~RobotModelInterface();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotModelInterface_message_member_array[2] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::RobotModelInterface, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::RobotModelInterface, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotModelInterface_message_members = {
  "ob_robotics_interface::msg",  // message namespace
  "RobotModelInterface",  // message name
  2,  // number of fields
  sizeof(ob_robotics_interface::msg::RobotModelInterface),
  false,  // has_any_key_member_
  RobotModelInterface_message_member_array,  // message members
  RobotModelInterface_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotModelInterface_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotModelInterface_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotModelInterface_message_members,
  get_message_typesupport_handle_function,
  &ob_robotics_interface__msg__RobotModelInterface__get_type_hash,
  &ob_robotics_interface__msg__RobotModelInterface__get_type_description,
  &ob_robotics_interface__msg__RobotModelInterface__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ob_robotics_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ob_robotics_interface::msg::RobotModelInterface>()
{
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::RobotModelInterface_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ob_robotics_interface, msg, RobotModelInterface)() {
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::RobotModelInterface_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif