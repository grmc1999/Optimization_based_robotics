// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ob_robotics_interface:msg/PerformanceData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/performance_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__TRAITS_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ob_robotics_interface/msg/detail/performance_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace ob_robotics_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const PerformanceData & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: model_values
  {
    if (msg.model_values.size() == 0) {
      out << "model_values: []";
    } else {
      out << "model_values: [";
      size_t pending_items = msg.model_values.size();
      for (auto item : msg.model_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: robot_state
  {
    if (msg.robot_state.size() == 0) {
      out << "robot_state: []";
    } else {
      out << "robot_state: [";
      size_t pending_items = msg.robot_state.size();
      for (auto item : msg.robot_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
  const PerformanceData & msg,
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

  // member: model_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.model_values.size() == 0) {
      out << "model_values: []\n";
    } else {
      out << "model_values:\n";
      for (auto item : msg.model_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: robot_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_state.size() == 0) {
      out << "robot_state: []\n";
    } else {
      out << "robot_state:\n";
      for (auto item : msg.robot_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

inline std::string to_yaml(const PerformanceData & msg, bool use_flow_style = false)
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
  const ob_robotics_interface::msg::PerformanceData & msg,
  std::ostream & out, size_t indentation = 0)
{
  ob_robotics_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ob_robotics_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const ob_robotics_interface::msg::PerformanceData & msg)
{
  return ob_robotics_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ob_robotics_interface::msg::PerformanceData>()
{
  return "ob_robotics_interface::msg::PerformanceData";
}

template<>
inline const char * name<ob_robotics_interface::msg::PerformanceData>()
{
  return "ob_robotics_interface/msg/PerformanceData";
}

template<>
struct has_fixed_size<ob_robotics_interface::msg::PerformanceData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ob_robotics_interface::msg::PerformanceData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ob_robotics_interface::msg::PerformanceData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__PERFORMANCE_DATA__TRAITS_HPP_
