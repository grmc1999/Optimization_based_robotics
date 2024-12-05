import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from sensor_msgs.msg import Imu
from geometry_msgs.msg import TwistStamped
import numpy as np
from tf_transformations import euler_from_quaternion

#from ob_robotics_interface.msg import Performance_data
from ob_robotics_interface.msg import RobotModelInterface
#from ob_robotics_interface.msg import Optimization_data

from .proxy_node import robot_interface_node

#import rospy


class IMU_proxy_node(robot_interface_node):
    """
    Input: sensors
    Output: Parse and simplified input for robot
    process:
        parsing sensor data, and maybe process multiple inputs in time
    """

    def __init__(self):
        super().__init__()

        self.interface_topic_subscription = self.create_subscription(
            Imu,'/imu', # This subscription has to be set for every type of problem
            self.get_input,10)
        
        self.command_publisher = self.create_publisher(
            TwistStamped,
		'diff_drive_controller/cmd_vel',
		1)

    def get_input(self,msg):
        self.input=msg

        if self.input!=None:
            model_input=RobotModelInterface()

            model_input.timestamp=self.get_clock().now().to_msg()
            orientation=euler_from_quaternion([
		            self.input.orientation.x,
		            self.input.orientation.y,
		            self.input.orientation.z,
		            self.input.orientation.w
                    ])
            print(orientation)
            model_input.value=float(orientation[1])

            self.input_publisher.publish(model_input)

    def timer_callback(self):
        """
        data parsing
        """
        # Transform model output for ros format

        if self.input!=None:
            model_input=RobotModelInterface()

            model_input.timestamp=self.get_clock().now().to_msg()
            orientation=euler_from_quaternion([
		            self.input.orientation.x,
		            self.input.orientation.y,
		            self.input.orientation.z,
		            self.input.orientation.w
                    ])
            print(orientation)
            model_input.value=float(orientation[1])

            self.input_publisher.publish(model_input)

        #Interface publication
        if self.model_command!=None:
            v_u=TwistStamped()
            v_u.header.stamp=self.get_clock().now().to_msg()
            v_u.header.frame_id="base_link"
            v_u.twist.linear.x=self.model_command.value
            self.command_publisher.publish(v_u)


def main(args=None):
    rclpy.init(args=args)

    TC = IMU_proxy_node()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
