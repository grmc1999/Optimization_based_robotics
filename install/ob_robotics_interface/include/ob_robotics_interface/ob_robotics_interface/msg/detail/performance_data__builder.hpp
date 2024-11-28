// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/performance_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__BUILDER_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ob_robotics_interface/msg/detail/performance_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ob_robotics_interface
{

namespace msg
{

namespace builder
{

class Init_PerformanceData_episode_end
{
public:
  explicit Init_PerformanceData_episode_end(::ob_robotics_interface::msg::PerformanceData & msg)
  : msg_(msg)
  {}
  ::ob_robotics_interface::msg::PerformanceData episode_end(::ob_robotics_interface::msg::PerformanceData::_episode_end_type arg)
  {
    msg_.episode_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ob_robotics_interface::msg::PerformanceData msg_;
};

class Init_PerformanceData_robot_state
{
public:
  explicit Init_PerformanceData_robot_state(::ob_robotics_interface::msg::PerformanceData & msg)
  : msg_(msg)
  {}
  Init_PerformanceData_episode_end robot_state(::ob_robotics_interface::msg::PerformanceData::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_PerformanceData_episode_end(msg_);
  }

private:
  ::ob_robotics_interface::msg::PerformanceData msg_;
};

class Init_PerformanceData_model_values
{
public:
  explicit Init_PerformanceData_model_values(::ob_robotics_interface::msg::PerformanceData & msg)
  : msg_(msg)
  {}
  Init_PerformanceData_robot_state model_values(::ob_robotics_interface::msg::PerformanceData::_model_values_type arg)
  {
    msg_.model_values = std::move(arg);
    return Init_PerformanceData_robot_state(msg_);
  }

private:
  ::ob_robotics_interface::msg::PerformanceData msg_;
};

class Init_PerformanceData_timestamp
{
public:
  Init_PerformanceData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PerformanceData_model_values timestamp(::ob_robotics_interface::msg::PerformanceData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_PerformanceData_model_values(msg_);
  }

private:
  ::ob_robotics_interface::msg::PerformanceData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ob_robotics_interface::msg::PerformanceData>()
{
  return ob_robotics_interface::msg::builder::Init_PerformanceData_timestamp();
}

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__BUILDER_HPP_
