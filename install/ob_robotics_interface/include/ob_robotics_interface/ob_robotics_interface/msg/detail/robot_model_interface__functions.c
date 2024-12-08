// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice
#include "ob_robotics_interface/msg/detail/robot_model_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
ob_robotics_interface__msg__RobotModelInterface__init(ob_robotics_interface__msg__RobotModelInterface * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    ob_robotics_interface__msg__RobotModelInterface__fini(msg);
    return false;
  }
  // value
  return true;
}

void
ob_robotics_interface__msg__RobotModelInterface__fini(ob_robotics_interface__msg__RobotModelInterface * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // value
}

bool
ob_robotics_interface__msg__RobotModelInterface__are_equal(const ob_robotics_interface__msg__RobotModelInterface * lhs, const ob_robotics_interface__msg__RobotModelInterface * rhs)
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
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
ob_robotics_interface__msg__RobotModelInterface__copy(
  const ob_robotics_interface__msg__RobotModelInterface * input,
  ob_robotics_interface__msg__RobotModelInterface * output)
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
  // value
  output->value = input->value;
  return true;
}

ob_robotics_interface__msg__RobotModelInterface *
ob_robotics_interface__msg__RobotModelInterface__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__RobotModelInterface * msg = (ob_robotics_interface__msg__RobotModelInterface *)allocator.allocate(sizeof(ob_robotics_interface__msg__RobotModelInterface), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ob_robotics_interface__msg__RobotModelInterface));
  bool success = ob_robotics_interface__msg__RobotModelInterface__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ob_robotics_interface__msg__RobotModelInterface__destroy(ob_robotics_interface__msg__RobotModelInterface * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ob_robotics_interface__msg__RobotModelInterface__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ob_robotics_interface__msg__RobotModelInterface__Sequence__init(ob_robotics_interface__msg__RobotModelInterface__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__RobotModelInterface * data = NULL;

  if (size) {
    data = (ob_robotics_interface__msg__RobotModelInterface *)allocator.zero_allocate(size, sizeof(ob_robotics_interface__msg__RobotModelInterface), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ob_robotics_interface__msg__RobotModelInterface__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ob_robotics_interface__msg__RobotModelInterface__fini(&data[i - 1]);
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
ob_robotics_interface__msg__RobotModelInterface__Sequence__fini(ob_robotics_interface__msg__RobotModelInterface__Sequence * array)
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
      ob_robotics_interface__msg__RobotModelInterface__fini(&array->data[i]);
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

ob_robotics_interface__msg__RobotModelInterface__Sequence *
ob_robotics_interface__msg__RobotModelInterface__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ob_robotics_interface__msg__RobotModelInterface__Sequence * array = (ob_robotics_interface__msg__RobotModelInterface__Sequence *)allocator.allocate(sizeof(ob_robotics_interface__msg__RobotModelInterface__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ob_robotics_interface__msg__RobotModelInterface__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ob_robotics_interface__msg__RobotModelInterface__Sequence__destroy(ob_robotics_interface__msg__RobotModelInterface__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ob_robotics_interface__msg__RobotModelInterface__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ob_robotics_interface__msg__RobotModelInterface__Sequence__are_equal(const ob_robotics_interface__msg__RobotModelInterface__Sequence * lhs, const ob_robotics_interface__msg__RobotModelInterface__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ob_robotics_interface__msg__RobotModelInterface__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ob_robotics_interface__msg__RobotModelInterface__Sequence__copy(
  const ob_robotics_interface__msg__RobotModelInterface__Sequence * input,
  ob_robotics_interface__msg__RobotModelInterface__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ob_robotics_interface__msg__RobotModelInterface);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ob_robotics_interface__msg__RobotModelInterface * data =
      (ob_robotics_interface__msg__RobotModelInterface *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ob_robotics_interface__msg__RobotModelInterface__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ob_robotics_interface__msg__RobotModelInterface__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ob_robotics_interface__msg__RobotModelInterface__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
