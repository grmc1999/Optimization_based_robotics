// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/robot_model_interface.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__BUILDER_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ob_robotics_interface/msg/detail/robot_model_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ob_robotics_interface
{

namespace msg
{

namespace builder
{

class Init_RobotModelInterface_value
{
public:
  explicit Init_RobotModelInterface_value(::ob_robotics_interface::msg::RobotModelInterface & msg)
  : msg_(msg)
  {}
  ::ob_robotics_interface::msg::RobotModelInterface value(::ob_robotics_interface::msg::RobotModelInterface::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ob_robotics_interface::msg::RobotModelInterface msg_;
};

class Init_RobotModelInterface_timestamp
{
public:
  Init_RobotModelInterface_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotModelInterface_value timestamp(::ob_robotics_interface::msg::RobotModelInterface::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_RobotModelInterface_value(msg_);
  }

private:
  ::ob_robotics_interface::msg::RobotModelInterface msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ob_robotics_interface::msg::RobotModelInterface>()
{
  return ob_robotics_interface::msg::builder::Init_RobotModelInterface_timestamp();
}

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__BUILDER_HPP_
