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
    #robot_desc = xacro.process_file(os.path.join(get_package_share_directory('gpg_urdf'), 'gpg.urdf.xml')).toxml()
    #robot_urdf_model = os.path.join(get_package_share_directory('gpg_remote'), 'gpg.urdf.xml')

    robot_desc = Command(
        [
            PathJoinSubstitution([FindExecutable(name='xacro')]),
            ' ',
            PathJoinSubstitution(
                [FindPackageShare('gpg_urdf'),
                 'gpg_unstable.urdf.xml']
            ),
        ]
    )#/home/ros2_ws/install/gpg_urdf/share/gpg_urdf/controllers.yaml

    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    #with open(robot_urdf_model, 'r') as infp:
    #    robot_desc = infp.read()

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("gpg_urdf"),
            "controllers.yaml",
        ]
    )
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("gpg_urdf"), "gpg_urdf.rviz"]
    )
    
    #robot_publisher = ExecuteProcess(cmd=['ros2', 'topic', 'pub', '-1', '--keep-alive', '86400', '--qos-durability', 'transient_local', '/robot_description', 'std_msgs/String', 'data: \'' + robot_description_content + '\''])
    robot_publisher = Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='both',
            #arguments=[robot_urdf_model],
            parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}],
            #parameters=[{ 'robot_description': robot_desc}],
            )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_controllers],
        output="both",
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
    )

    gpg_remote_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["gpg_remote_broadcaster", "--controller-manager", "/controller_manager"],
    )

    servo_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["servo_controller", "--controller-manager", "/controller_manager"],
    )

    robot_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_drive_controller", "-c", "/controller_manager"],
    )

    # Delay rviz start after `joint_state_broadcaster`
    delay_rviz_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[rviz_node],
        )
    )

    # Delay start of robot_controller after `joint_state_broadcaster`
    delay_robot_controller_spawner_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[
                robot_controller_spawner,
                servo_controller_spawner,
                #gpg_remote_broadcaster_spawner
                ],
        )
    )


    gz_launch=LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    FindPackageShare('ros_gz_sim'),
                    'launch',
                    'gz_sim.launch.py'
                ])
            ]),
            launch_arguments={
               'gz_args':['-r ',FindPackageShare("gpg_urdf"), "/world_1.sdf"],
                }.items()
        )
    ])

    robot_spawner = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=["-topic", "robot_description","-z","1"],
    )

    time_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=["/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock"],
        output="both"
    )

    camera_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=["/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo"],
        output="both"
    )

    imu_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=["/imu@sensor_msgs/msg/Imu[gz.msgs.IMU"],
        output="both"
    )

    set_pose_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=["/world/empty/set_pose@ros_gz_interfaces/srv/SetEntityPose@gz.msgs.Pose@gz.msgs.Boolean"],
        output="both"
    )

    image_bridge = Node(
        package="ros_gz_image",
        executable="image_bridge",
        arguments=["/image"],)
    
    delay_control_after__spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=robot_spawner,
            on_exit=[control_node],
        )
    )
    delay_spawn_after_robot_publisher = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=robot_publisher,
            on_start=[robot_spawner],
        )
    )


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
        time_bridge,
        camera_bridge,
        image_bridge,
        imu_bridge,
        set_pose_bridge,
        robot_publisher,
        gz_launch,
        delay_spawn_after_robot_publisher,
        joint_state_broadcaster_spawner,
        delay_rviz_after_joint_state_broadcaster_spawner,
        delay_robot_controller_spawner_after_joint_state_broadcaster_spawner,
        loss_node,
        proxy_node,
        model_node
    ]

    return LaunchDescription(nodes)