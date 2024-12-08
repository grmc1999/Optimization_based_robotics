// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/performance_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_HPP_

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
# define DEPRECATED__ob_robotics_interface__msg__PerformanceData __attribute__((deprecated))
#else
# define DEPRECATED__ob_robotics_interface__msg__PerformanceData __declspec(deprecated)
#endif

namespace ob_robotics_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PerformanceData_
{
  using Type = PerformanceData_<ContainerAllocator>;

  explicit PerformanceData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->episode_end = false;
    }
  }

  explicit PerformanceData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->episode_end = false;
    }
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _model_values_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _model_values_type model_values;
  using _robot_state_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _robot_state_type robot_state;
  using _episode_end_type =
    bool;
  _episode_end_type episode_end;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__model_values(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->model_values = _arg;
    return *this;
  }
  Type & set__robot_state(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->robot_state = _arg;
    return *this;
  }
  Type & set__episode_end(
    const bool & _arg)
  {
    this->episode_end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> *;
  using ConstRawPtr =
    const ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ob_robotics_interface__msg__PerformanceData
    std::shared_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ob_robotics_interface__msg__PerformanceData
    std::shared_ptr<ob_robotics_interface::msg::PerformanceData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PerformanceData_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->model_values != other.model_values) {
      return false;
    }
    if (this->robot_state != other.robot_state) {
      return false;
    }
    if (this->episode_end != other.episode_end) {
      return false;
    }
    return true;
  }
  bool operator!=(const PerformanceData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PerformanceData_

// alias to use template instance with default allocator
using PerformanceData =
  ob_robotics_interface::msg::PerformanceData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__STRUCT_HPP_
