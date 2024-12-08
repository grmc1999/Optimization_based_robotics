// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ob_robotics_interface/msg/detail/performance_data__functions.h"
#include "ob_robotics_interface/msg/detail/performance_data__struct.hpp"
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

void PerformanceData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ob_robotics_interface::msg::PerformanceData(_init);
}

void PerformanceData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ob_robotics_interface::msg::PerformanceData *>(message_memory);
  typed_message->~PerformanceData();
}

size_t size_function__PerformanceData__model_values(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PerformanceData__model_values(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PerformanceData__model_values(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PerformanceData__model_values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PerformanceData__model_values(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PerformanceData__model_values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PerformanceData__model_values(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PerformanceData__model_values(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PerformanceData__robot_state(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PerformanceData__robot_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PerformanceData__robot_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PerformanceData__robot_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PerformanceData__robot_state(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PerformanceData__robot_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PerformanceData__robot_state(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PerformanceData__robot_state(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PerformanceData_message_member_array[4] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::PerformanceData, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "model_values",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::PerformanceData, model_values),  // bytes offset in struct
    nullptr,  // default value
    size_function__PerformanceData__model_values,  // size() function pointer
    get_const_function__PerformanceData__model_values,  // get_const(index) function pointer
    get_function__PerformanceData__model_values,  // get(index) function pointer
    fetch_function__PerformanceData__model_values,  // fetch(index, &value) function pointer
    assign_function__PerformanceData__model_values,  // assign(index, value) function pointer
    resize_function__PerformanceData__model_values  // resize(index) function pointer
  },
  {
    "robot_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ob_robotics_interface::msg::PerformanceData, robot_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__PerformanceData__robot_state,  // size() function pointer
    get_const_function__PerformanceData__robot_state,  // get_const(index) function pointer
    get_function__PerformanceData__robot_state,  // get(index) function pointer
    fetch_function__PerformanceData__robot_state,  // fetch(index, &value) function pointer
    assign_function__PerformanceData__robot_state,  // assign(index, value) function pointer
    resize_function__PerformanceData__robot_state  // resize(index) function pointer
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
    offsetof(ob_robotics_interface::msg::PerformanceData, episode_end),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PerformanceData_message_members = {
  "ob_robotics_interface::msg",  // message namespace
  "PerformanceData",  // message name
  4,  // number of fields
  sizeof(ob_robotics_interface::msg::PerformanceData),
  false,  // has_any_key_member_
  PerformanceData_message_member_array,  // message members
  PerformanceData_init_function,  // function to initialize message memory (memory has to be allocated)
  PerformanceData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PerformanceData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PerformanceData_message_members,
  get_message_typesupport_handle_function,
  &ob_robotics_interface__msg__PerformanceData__get_type_hash,
  &ob_robotics_interface__msg__PerformanceData__get_type_description,
  &ob_robotics_interface__msg__PerformanceData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ob_robotics_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ob_robotics_interface::msg::PerformanceData>()
{
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::PerformanceData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ob_robotics_interface, msg, PerformanceData)() {
  return &::ob_robotics_interface::msg::rosidl_typesupport_introspection_cpp::PerformanceData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
