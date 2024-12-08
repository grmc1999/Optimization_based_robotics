// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ob_robotics_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ob_robotics_interface/msg/detail/robot_model_interface__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ob_robotics_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
cdr_serialize(
  const ob_robotics_interface::msg::RobotModelInterface & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ob_robotics_interface::msg::RobotModelInterface & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
get_serialized_size(
  const ob_robotics_interface::msg::RobotModelInterface & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
max_serialized_size_RobotModelInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
cdr_serialize_key(
  const ob_robotics_interface::msg::RobotModelInterface & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
get_serialized_size_key(
  const ob_robotics_interface::msg::RobotModelInterface & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
max_serialized_size_key_RobotModelInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ob_robotics_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ob_robotics_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ob_robotics_interface, msg, RobotModelInterface)();

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
