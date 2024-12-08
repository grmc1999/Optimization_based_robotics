// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/optimization_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__BUILDER_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ob_robotics_interface/msg/detail/optimization_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ob_robotics_interface
{

namespace msg
{

namespace builder
{

class Init_OptimizationData_episode_end
{
public:
  explicit Init_OptimizationData_episode_end(::ob_robotics_interface::msg::OptimizationData & msg)
  : msg_(msg)
  {}
  ::ob_robotics_interface::msg::OptimizationData episode_end(::ob_robotics_interface::msg::OptimizationData::_episode_end_type arg)
  {
    msg_.episode_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ob_robotics_interface::msg::OptimizationData msg_;
};

class Init_OptimizationData_loss
{
public:
  explicit Init_OptimizationData_loss(::ob_robotics_interface::msg::OptimizationData & msg)
  : msg_(msg)
  {}
  Init_OptimizationData_episode_end loss(::ob_robotics_interface::msg::OptimizationData::_loss_type arg)
  {
    msg_.loss = std::move(arg);
    return Init_OptimizationData_episode_end(msg_);
  }

private:
  ::ob_robotics_interface::msg::OptimizationData msg_;
};

class Init_OptimizationData_timestamp
{
public:
  Init_OptimizationData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OptimizationData_loss timestamp(::ob_robotics_interface::msg::OptimizationData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_OptimizationData_loss(msg_);
  }

private:
  ::ob_robotics_interface::msg::OptimizationData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ob_robotics_interface::msg::OptimizationData>()
{
  return ob_robotics_interface::msg::builder::Init_OptimizationData_timestamp();
}

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__BUILDER_HPP_
