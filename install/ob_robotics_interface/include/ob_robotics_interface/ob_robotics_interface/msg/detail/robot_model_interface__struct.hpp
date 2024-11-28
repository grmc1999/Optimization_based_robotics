// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/robot_model_interface.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ob_robotics_interface__msg__RobotModelInterface __attribute__((deprecated))
#else
# define DEPRECATED__ob_robotics_interface__msg__RobotModelInterface __declspec(deprecated)
#endif

namespace ob_robotics_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotModelInterface_
{
  using Type = RobotModelInterface_<ContainerAllocator>;

  explicit RobotModelInterface_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  explicit RobotModelInterface_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _value_type =
    float;
  _value_type value;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__value(
    const float & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> *;
  using ConstRawPtr =
    const ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ob_robotics_interface__msg__RobotModelInterface
    std::shared_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ob_robotics_interface__msg__RobotModelInterface
    std::shared_ptr<ob_robotics_interface::msg::RobotModelInterface_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotModelInterface_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotModelInterface_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotModelInterface_

// alias to use template instance with default allocator
using RobotModelInterface =
  ob_robotics_interface::msg::RobotModelInterface_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__STRUCT_HPP_
