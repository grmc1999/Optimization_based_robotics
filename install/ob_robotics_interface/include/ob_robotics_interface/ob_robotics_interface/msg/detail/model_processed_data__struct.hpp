// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ob_robotics_interface:msg/ModelProcessedData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/model_processed_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__STRUCT_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__STRUCT_HPP_

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
# define DEPRECATED__ob_robotics_interface__msg__ModelProcessedData __attribute__((deprecated))
#else
# define DEPRECATED__ob_robotics_interface__msg__ModelProcessedData __declspec(deprecated)
#endif

namespace ob_robotics_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModelProcessedData_
{
  using Type = ModelProcessedData_<ContainerAllocator>;

  explicit ModelProcessedData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    (void)_init;
  }

  explicit ModelProcessedData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _values_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _values_type values;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__values(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->values = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> *;
  using ConstRawPtr =
    const ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ob_robotics_interface__msg__ModelProcessedData
    std::shared_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ob_robotics_interface__msg__ModelProcessedData
    std::shared_ptr<ob_robotics_interface::msg::ModelProcessedData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelProcessedData_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->values != other.values) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelProcessedData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelProcessedData_

// alias to use template instance with default allocator
using ModelProcessedData =
  ob_robotics_interface::msg::ModelProcessedData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__STRUCT_HPP_
