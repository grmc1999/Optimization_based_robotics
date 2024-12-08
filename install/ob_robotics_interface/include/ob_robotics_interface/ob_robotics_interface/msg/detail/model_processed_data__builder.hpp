// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ob_robotics_interface:msg/ModelProcessedData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/model_processed_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__BUILDER_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ob_robotics_interface/msg/detail/model_processed_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ob_robotics_interface
{

namespace msg
{

namespace builder
{

class Init_ModelProcessedData_values
{
public:
  explicit Init_ModelProcessedData_values(::ob_robotics_interface::msg::ModelProcessedData & msg)
  : msg_(msg)
  {}
  ::ob_robotics_interface::msg::ModelProcessedData values(::ob_robotics_interface::msg::ModelProcessedData::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ob_robotics_interface::msg::ModelProcessedData msg_;
};

class Init_ModelProcessedData_timestamp
{
public:
  Init_ModelProcessedData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModelProcessedData_values timestamp(::ob_robotics_interface::msg::ModelProcessedData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ModelProcessedData_values(msg_);
  }

private:
  ::ob_robotics_interface::msg::ModelProcessedData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ob_robotics_interface::msg::ModelProcessedData>()
{
  return ob_robotics_interface::msg::builder::Init_ModelProcessedData_timestamp();
}

}  // namespace ob_robotics_interface

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__BUILDER_HPP_
