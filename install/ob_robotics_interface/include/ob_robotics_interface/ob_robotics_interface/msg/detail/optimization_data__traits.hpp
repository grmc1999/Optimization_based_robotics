// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ob_robotics_interface:msg/OptimizationData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/optimization_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__TRAITS_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ob_robotics_interface/msg/detail/optimization_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace ob_robotics_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const OptimizationData & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: loss
  {
    out << "loss: ";
    rosidl_generator_traits::value_to_yaml(msg.loss, out);
    out << ", ";
  }

  // member: episode_end
  {
    out << "episode_end: ";
    rosidl_generator_traits::value_to_yaml(msg.episode_end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OptimizationData & msg,
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

  // member: loss
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loss: ";
    rosidl_generator_traits::value_to_yaml(msg.loss, out);
    out << "\n";
  }

  // member: episode_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "episode_end: ";
    rosidl_generator_traits::value_to_yaml(msg.episode_end, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OptimizationData & msg, bool use_flow_style = false)
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
  const ob_robotics_interface::msg::OptimizationData & msg,
  std::ostream & out, size_t indentation = 0)
{
  ob_robotics_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ob_robotics_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const ob_robotics_interface::msg::OptimizationData & msg)
{
  return ob_robotics_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ob_robotics_interface::msg::OptimizationData>()
{
  return "ob_robotics_interface::msg::OptimizationData";
}

template<>
inline const char * name<ob_robotics_interface::msg::OptimizationData>()
{
  return "ob_robotics_interface/msg/OptimizationData";
}

template<>
struct has_fixed_size<ob_robotics_interface::msg::OptimizationData>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<ob_robotics_interface::msg::OptimizationData>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<ob_robotics_interface::msg::OptimizationData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__OPTIMIZATION_DATA__TRAITS_HPP_
