# Copyright 2020 ros2_control Development Team
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription
from launch.actions import RegisterEventHandler
from launch.actions import ExecuteProcess
from launch.event_handlers import OnProcessExit,OnProcessStart
from launch.substitutions import PathJoinSubstitution
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, TextSubstitution,Command,FindExecutable


from ament_index_python.packages import get_package_share_directory
import os
import xacro

def generate_launch_description():
    # Get URDF


    loss_node = Node(
        package="Optimization_module",
        executable="time_enforced_objective_node",
    )

    proxy_node = Node(
        package="Optimization_module",
        executable="IMU_proxy_node",
    )

    model_node = Node(
        package="Optimization_module",
        executable="PID_model_node",
    )



    nodes = [
        loss_node,
        proxy_node,
        model_node
    ]

    return LaunchDescription(nodes)
