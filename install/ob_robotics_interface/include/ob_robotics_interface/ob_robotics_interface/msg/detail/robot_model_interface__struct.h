// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/robot_model_interface.h"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_H_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/RobotModelInterface in the package ob_robotics_interface.
typedef struct ob_robotics_interface__msg__RobotModelInterface
{
  builtin_interfaces__msg__Time timestamp;
  float value;
} ob_robotics_interface__msg__RobotModelInterface;

// Struct for a sequence of ob_robotics_interface__msg__RobotModelInterface.
typedef struct ob_robotics_interface__msg__RobotModelInterface__Sequence
{
  ob_robotics_interface__msg__RobotModelInterface * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ob_robotics_interface__msg__RobotModelInterface__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_H_
