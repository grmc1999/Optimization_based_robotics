// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ob_robotics_interface:msg/ModelProcessedData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/model_processed_data.h"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__FUNCTIONS_H_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__FUNCTIONS_H_

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

#include "ob_robotics_interface/msg/detail/model_processed_data__struct.h"

/// Initialize msg/ModelProcessedData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ob_robotics_interface__msg__ModelProcessedData
 * )) before or use
 * ob_robotics_interface__msg__ModelProcessedData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__ModelProcessedData__init(ob_robotics_interface__msg__ModelProcessedData * msg);

/// Finalize msg/ModelProcessedData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__ModelProcessedData__fini(ob_robotics_interface__msg__ModelProcessedData * msg);

/// Create msg/ModelProcessedData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ob_robotics_interface__msg__ModelProcessedData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
ob_robotics_interface__msg__ModelProcessedData *
ob_robotics_interface__msg__ModelProcessedData__create(void);

/// Destroy msg/ModelProcessedData message.
/**
 * It calls
 * ob_robotics_interface__msg__ModelProcessedData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__ModelProcessedData__destroy(ob_robotics_interface__msg__ModelProcessedData * msg);

/// Check for msg/ModelProcessedData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__ModelProcessedData__are_equal(const ob_robotics_interface__msg__ModelProcessedData * lhs, const ob_robotics_interface__msg__ModelProcessedData * rhs);

/// Copy a msg/ModelProcessedData message.
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
ob_robotics_interface__msg__ModelProcessedData__copy(
  const ob_robotics_interface__msg__ModelProcessedData * input,
  ob_robotics_interface__msg__ModelProcessedData * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_type_hash_t *
ob_robotics_interface__msg__ModelProcessedData__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeDescription *
ob_robotics_interface__msg__ModelProcessedData__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeSource *
ob_robotics_interface__msg__ModelProcessedData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
const rosidl_runtime_c__type_description__TypeSource__Sequence *
ob_robotics_interface__msg__ModelProcessedData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ModelProcessedData messages.
/**
 * It allocates the memory for the number of elements and calls
 * ob_robotics_interface__msg__ModelProcessedData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__ModelProcessedData__Sequence__init(ob_robotics_interface__msg__ModelProcessedData__Sequence * array, size_t size);

/// Finalize array of msg/ModelProcessedData messages.
/**
 * It calls
 * ob_robotics_interface__msg__ModelProcessedData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__ModelProcessedData__Sequence__fini(ob_robotics_interface__msg__ModelProcessedData__Sequence * array);

/// Create array of msg/ModelProcessedData messages.
/**
 * It allocates the memory for the array and calls
 * ob_robotics_interface__msg__ModelProcessedData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
ob_robotics_interface__msg__ModelProcessedData__Sequence *
ob_robotics_interface__msg__ModelProcessedData__Sequence__create(size_t size);

/// Destroy array of msg/ModelProcessedData messages.
/**
 * It calls
 * ob_robotics_interface__msg__ModelProcessedData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
void
ob_robotics_interface__msg__ModelProcessedData__Sequence__destroy(ob_robotics_interface__msg__ModelProcessedData__Sequence * array);

/// Check for msg/ModelProcessedData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ob_robotics_interface
bool
ob_robotics_interface__msg__ModelProcessedData__Sequence__are_equal(const ob_robotics_interface__msg__ModelProcessedData__Sequence * lhs, const ob_robotics_interface__msg__ModelProcessedData__Sequence * rhs);

/// Copy an array of msg/ModelProcessedData messages.
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
ob_robotics_interface__msg__ModelProcessedData__Sequence__copy(
  const ob_robotics_interface__msg__ModelProcessedData__Sequence * input,
  ob_robotics_interface__msg__ModelProcessedData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__FUNCTIONS_H_
