// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ob_robotics_interface:msg/RobotModelInterface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/robot_model_interface.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__TRAITS_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ob_robotics_interface/msg/detail/robot_model_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace ob_robotics_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotModelInterface & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotModelInterface & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotModelInterface & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ob_robotics_interface

namespace rosidl_generator_traits
{

[[deprecated("use ob_robotics_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ob_robotics_interface::msg::RobotModelInterface & msg,
  std::ostream & out, size_t indentation = 0)
{
  ob_robotics_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ob_robotics_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const ob_robotics_interface::msg::RobotModelInterface & msg)
{
  return ob_robotics_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ob_robotics_interface::msg::RobotModelInterface>()
{
  return "ob_robotics_interface::msg::RobotModelInterface";
}

template<>
inline const char * name<ob_robotics_interface::msg::RobotModelInterface>()
{
  return "ob_robotics_interface/msg/RobotModelInterface";
}

template<>
struct has_fixed_size<ob_robotics_interface::msg::RobotModelInterface>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<ob_robotics_interface::msg::RobotModelInterface>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<ob_robotics_interface::msg::RobotModelInterface>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__ROBOT_MODEL_INTERFACE__TRAITS_HPP_
