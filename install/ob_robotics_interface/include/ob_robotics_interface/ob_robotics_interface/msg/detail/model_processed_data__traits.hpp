// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ob_robotics_interface:msg/ModelProcessedData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ob_robotics_interface/msg/model_processed_data.hpp"


#ifndef OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__TRAITS_HPP_
#define OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ob_robotics_interface/msg/detail/model_processed_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace ob_robotics_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModelProcessedData & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: values
  {
    if (msg.values.size() == 0) {
      out << "values: []";
    } else {
      out << "values: [";
      size_t pending_items = msg.values.size();
      for (auto item : msg.values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModelProcessedData & msg,
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

  // member: values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.values.size() == 0) {
      out << "values: []\n";
    } else {
      out << "values:\n";
      for (auto item : msg.values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModelProcessedData & msg, bool use_flow_style = false)
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
  const ob_robotics_interface::msg::ModelProcessedData & msg,
  std::ostream & out, size_t indentation = 0)
{
  ob_robotics_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ob_robotics_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const ob_robotics_interface::msg::ModelProcessedData & msg)
{
  return ob_robotics_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ob_robotics_interface::msg::ModelProcessedData>()
{
  return "ob_robotics_interface::msg::ModelProcessedData";
}

template<>
inline const char * name<ob_robotics_interface::msg::ModelProcessedData>()
{
  return "ob_robotics_interface/msg/ModelProcessedData";
}

template<>
struct has_fixed_size<ob_robotics_interface::msg::ModelProcessedData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ob_robotics_interface::msg::ModelProcessedData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ob_robotics_interface::msg::ModelProcessedData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OB_ROBOTICS_INTERFACE__MSG__DETAIL__MODEL_PROCESSED_DATA__TRAITS_HPP_
