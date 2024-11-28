// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/performance_data.h"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_H_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_H_

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
// Member 'model_values'
// Member 'robot_state'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PerformanceData in the package ob_robotics_interface.
typedef struct ob_robotics_interface__msg__PerformanceData
{
  builtin_interfaces__msg__Time timestamp;
  rosidl_runtime_c__float__Sequence model_values;
  rosidl_runtime_c__float__Sequence robot_state;
  bool episode_end;
} ob_robotics_interface__msg__PerformanceData;

// Struct for a sequence of ob_robotics_interface__msg__PerformanceData.
typedef struct ob_robotics_interface__msg__PerformanceData__Sequence
{
  ob_robotics_interface__msg__PerformanceData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ob_robotics_interface__msg__PerformanceData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_H_
