// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice
#include "ob_robotics_interface/msg/detail/optimization_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
ob_robotics_interface__msg__OptimizationData__init(ob_robotics_interface__msg__OptimizationData * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    ob_robotics_interface__msg__OptimizationData__fini(msg);
    return false;
  }
  // loss
  // episode_end
  return true;
}

void
ob_robotics_interface__msg__OptimizationData__fini(ob_robotics_interface__msg__OptimizationData * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // loss
  // episode_end
}

bool
ob_robotics_interface__msg__OptimizationData__are_equal(const ob_robotics_interface__msg__OptimizationData * lhs, const ob_robotics_interface__msg__OptimizationData * rhs)
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
  // loss
  if (lhs->loss != rhs->loss) {
    return false;
  }
  // episode_end
  if (lhs->episode_end != rhs->episode_end) {
    return false;
  }
  return true;
}

bool
ob_robotics_interface__msg__OptimizationData__copy(
  const ob_robotics_interface__msg__OptimizationData * input,
  ob_robotics_interface__msg__OptimizationData * output)
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
  // loss
  output->loss = input->loss;
  // episode_end
  output->episode_end = input->episode_end;
  return true;
}

ob_robotics_interface__msg__OptimizationData *
ob_robotics_interface__msg__OptimizationData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__OptimizationData * msg = (ob_robotics_interface__msg__OptimizationData *)allocator.allocate(sizeof(ob_robotics_interface__msg__OptimizationData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ob_robotics_interface__msg__OptimizationData));
  bool success = ob_robotics_interface__msg__OptimizationData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ob_robotics_interface__msg__OptimizationData__destroy(ob_robotics_interface__msg__OptimizationData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ob_robotics_interface__msg__OptimizationData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ob_robotics_interface__msg__OptimizationData__Sequence__init(ob_robotics_interface__msg__OptimizationData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__OptimizationData * data = NULL;

  if (size) {
    data = (ob_robotics_interface__msg__OptimizationData *)allocator.zero_allocate(size, sizeof(ob_robotics_interface__msg__OptimizationData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ob_robotics_interface__msg__OptimizationData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ob_robotics_interface__msg__OptimizationData__fini(&data[i - 1]);
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
ob_robotics_interface__msg__OptimizationData__Sequence__fini(ob_robotics_interface__msg__OptimizationData__Sequence * array)
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
      ob_robotics_interface__msg__OptimizationData__fini(&array->data[i]);
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

ob_robotics_interface__msg__OptimizationData__Sequence *
ob_robotics_interface__msg__OptimizationData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__OptimizationData__Sequence * array = (ob_robotics_interface__msg__OptimizationData__Sequence *)allocator.allocate(sizeof(ob_robotics_interface__msg__OptimizationData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ob_robotics_interface__msg__OptimizationData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ob_robotics_interface__msg__OptimizationData__Sequence__destroy(ob_robotics_interface__msg__OptimizationData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ob_robotics_interface__msg__OptimizationData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ob_robotics_interface__msg__OptimizationData__Sequence__are_equal(const ob_robotics_interface__msg__OptimizationData__Sequence * lhs, const ob_robotics_interface__msg__OptimizationData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ob_robotics_interface__msg__OptimizationData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ob_robotics_interface__msg__OptimizationData__Sequence__copy(
  const ob_robotics_interface__msg__OptimizationData__Sequence * input,
  ob_robotics_interface__msg__OptimizationData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ob_robotics_interface__msg__OptimizationData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ob_robotics_interface__msg__OptimizationData * data =
      (ob_robotics_interface__msg__OptimizationData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ob_robotics_interface__msg__OptimizationData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ob_robotics_interface__msg__OptimizationData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ob_robotics_interface__msg__OptimizationData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
