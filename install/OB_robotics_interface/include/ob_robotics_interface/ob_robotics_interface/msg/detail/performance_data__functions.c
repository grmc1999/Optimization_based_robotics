// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice
#include "ob_robotics_interface/msg/detail/performance_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `model_values`
// Member `robot_state`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ob_robotics_interface__msg__PerformanceData__init(ob_robotics_interface__msg__PerformanceData * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    ob_robotics_interface__msg__PerformanceData__fini(msg);
    return false;
  }
  // model_values
  if (!rosidl_runtime_c__float__Sequence__init(&msg->model_values, 0)) {
    ob_robotics_interface__msg__PerformanceData__fini(msg);
    return false;
  }
  // robot_state
  if (!rosidl_runtime_c__float__Sequence__init(&msg->robot_state, 0)) {
    ob_robotics_interface__msg__PerformanceData__fini(msg);
    return false;
  }
  // episode_end
  return true;
}

void
ob_robotics_interface__msg__PerformanceData__fini(ob_robotics_interface__msg__PerformanceData * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // model_values
  rosidl_runtime_c__float__Sequence__fini(&msg->model_values);
  // robot_state
  rosidl_runtime_c__float__Sequence__fini(&msg->robot_state);
  // episode_end
}

bool
ob_robotics_interface__msg__PerformanceData__are_equal(const ob_robotics_interface__msg__PerformanceData * lhs, const ob_robotics_interface__msg__PerformanceData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // model_values
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->model_values), &(rhs->model_values)))
  {
    return false;
  }
  // robot_state
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->robot_state), &(rhs->robot_state)))
  {
    return false;
  }
  // episode_end
  if (lhs->episode_end != rhs->episode_end) {
    return false;
  }
  return true;
}

bool
ob_robotics_interface__msg__PerformanceData__copy(
  const ob_robotics_interface__msg__PerformanceData * input,
  ob_robotics_interface__msg__PerformanceData * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // model_values
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->model_values), &(output->model_values)))
  {
    return false;
  }
  // robot_state
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->robot_state), &(output->robot_state)))
  {
    return false;
  }
  // episode_end
  output->episode_end = input->episode_end;
  return true;
}

ob_robotics_interface__msg__PerformanceData *
ob_robotics_interface__msg__PerformanceData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__PerformanceData * msg = (ob_robotics_interface__msg__PerformanceData *)allocator.allocate(sizeof(ob_robotics_interface__msg__PerformanceData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ob_robotics_interface__msg__PerformanceData));
  bool success = ob_robotics_interface__msg__PerformanceData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ob_robotics_interface__msg__PerformanceData__destroy(ob_robotics_interface__msg__PerformanceData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ob_robotics_interface__msg__PerformanceData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ob_robotics_interface__msg__PerformanceData__Sequence__init(ob_robotics_interface__msg__PerformanceData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__PerformanceData * data = NULL;

  if (size) {
    data = (ob_robotics_interface__msg__PerformanceData *)allocator.zero_allocate(size, sizeof(ob_robotics_interface__msg__PerformanceData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ob_robotics_interface__msg__PerformanceData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ob_robotics_interface__msg__PerformanceData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ob_robotics_interface__msg__PerformanceData__Sequence__fini(ob_robotics_interface__msg__PerformanceData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ob_robotics_interface__msg__PerformanceData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ob_robotics_interface__msg__PerformanceData__Sequence *
ob_robotics_interface__msg__PerformanceData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__PerformanceData__Sequence * array = (ob_robotics_interface__msg__PerformanceData__Sequence *)allocator.allocate(sizeof(ob_robotics_interface__msg__PerformanceData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ob_robotics_interface__msg__PerformanceData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ob_robotics_interface__msg__PerformanceData__Sequence__destroy(ob_robotics_interface__msg__PerformanceData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ob_robotics_interface__msg__PerformanceData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ob_robotics_interface__msg__PerformanceData__Sequence__are_equal(const ob_robotics_interface__msg__PerformanceData__Sequence * lhs, const ob_robotics_interface__msg__PerformanceData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ob_robotics_interface__msg__PerformanceData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ob_robotics_interface__msg__PerformanceData__Sequence__copy(
  const ob_robotics_interface__msg__PerformanceData__Sequence * input,
  ob_robotics_interface__msg__PerformanceData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ob_robotics_interface__msg__PerformanceData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ob_robotics_interface__msg__PerformanceData * data =
      (ob_robotics_interface__msg__PerformanceData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ob_robotics_interface__msg__PerformanceData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ob_robotics_interface__msg__PerformanceData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ob_robotics_interface__msg__PerformanceData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
