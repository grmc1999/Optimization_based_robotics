// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice
#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ob_robotics_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ob_robotics_interface/msg/detail/robot_model_interface__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
bool cdr_serialize_ob_robotics_interface__msg__RobotModelInterface(
  const ob_robotics_interface__msg__RobotModelInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
bool cdr_deserialize_ob_robotics_interface__msg__RobotModelInterface(
  eprosima::fastcdr::Cdr &,
  ob_robotics_interface__msg__RobotModelInterface * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
size_t get_serialized_size_ob_robotics_interface__msg__RobotModelInterface(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
size_t max_serialized_size_ob_robotics_interface__msg__RobotModelInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
bool cdr_serialize_key_ob_robotics_interface__msg__RobotModelInterface(
  const ob_robotics_interface__msg__RobotModelInterface * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
size_t get_serialized_size_key_ob_robotics_interface__msg__RobotModelInterface(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
size_t max_serialized_size_key_ob_robotics_interface__msg__RobotModelInterface(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ob_robotics_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ob_robotics_interface, msg, RobotModelInterface)();

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
