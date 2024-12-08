// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/optimization_data.h"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__FUNCTIONS_H_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "ob_robotics_interface/msg/rosidl_generator_c__visibility_control.h"

#include "ob_robotics_interface/msg/detail/optimization_data__struct.h"

/// Initialize msg/OptimizationData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ob_robotics_interface__msg__OptimizationData
 * )) before or use
 * ob_robotics_interface__msg__OptimizationData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__init(ob_robotics_interface__msg__OptimizationData * msg);

/// Finalize msg/OptimizationData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__OptimizationData__fini(ob_robotics_interface__msg__OptimizationData * msg);

/// Create msg/OptimizationData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ob_robotics_interface__msg__OptimizationData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
ob_robotics_interface__msg__OptimizationData *
ob_robotics_interface__msg__OptimizationData__create(void);

/// Destroy msg/OptimizationData message.
/**
 * It calls
 * ob_robotics_interface__msg__OptimizationData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__OptimizationData__destroy(ob_robotics_interface__msg__OptimizationData * msg);

/// Check for msg/OptimizationData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__are_equal(const ob_robotics_interface__msg__OptimizationData * lhs, const ob_robotics_interface__msg__OptimizationData * rhs);

/// Copy a msg/OptimizationData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__copy(
  const ob_robotics_interface__msg__OptimizationData * input,
  ob_robotics_interface__msg__OptimizationData * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_type_hash_t *
ob_robotics_interface__msg__OptimizationData__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeDescription *
ob_robotics_interface__msg__OptimizationData__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeSource *
ob_robotics_interface__msg__OptimizationData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeSource__Sequence *
ob_robotics_interface__msg__OptimizationData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/OptimizationData messages.
/**
 * It allocates the memory for the number of elements and calls
 * ob_robotics_interface__msg__OptimizationData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__Sequence__init(ob_robotics_interface__msg__OptimizationData__Sequence * array, size_t size);

/// Finalize array of msg/OptimizationData messages.
/**
 * It calls
 * ob_robotics_interface__msg__OptimizationData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__OptimizationData__Sequence__fini(ob_robotics_interface__msg__OptimizationData__Sequence * array);

/// Create array of msg/OptimizationData messages.
/**
 * It allocates the memory for the array and calls
 * ob_robotics_interface__msg__OptimizationData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
ob_robotics_interface__msg__OptimizationData__Sequence *
ob_robotics_interface__msg__OptimizationData__Sequence__create(size_t size);

/// Destroy array of msg/OptimizationData messages.
/**
 * It calls
 * ob_robotics_interface__msg__OptimizationData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__OptimizationData__Sequence__destroy(ob_robotics_interface__msg__OptimizationData__Sequence * array);

/// Check for msg/OptimizationData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__Sequence__are_equal(const ob_robotics_interface__msg__OptimizationData__Sequence * lhs, const ob_robotics_interface__msg__OptimizationData__Sequence * rhs);

/// Copy an array of msg/OptimizationData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__OptimizationData__Sequence__copy(
  const ob_robotics_interface__msg__OptimizationData__Sequence * input,
  ob_robotics_interface__msg__OptimizationData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__FUNCTIONS_H_
