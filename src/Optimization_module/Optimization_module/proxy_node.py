import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from geometry_msgs.msg import Twist,Pose2D,TwistStamped,PointStamped
from turtlesim.msg import Pose
from nav_msgs.msg import Odometry
from tf_transformations import euler_from_quaternion
import angles
import numpy as np
import math
import tf2_ros
import tf2_geometry_msgs

#from ob_robotics_interface.msg import Performance_data
from ob_robotics_interface.msg import RobotModelInterface
#from ob_robotics_interface.msg import Optimization_data

#import rospy


class robot_interface_node(Node):
    """
    Input: sensors
    Output: Parse and simplified input for robot
    process:
        parsing sensor data, and maybe process multiple inputs in time
    """

    def __init__(self):
        super().__init__('Proxy')

        self.declare_parameter('Mode',"train")
        # mode should be train, test, deploy
        # Assertion for defined modes

        #self.goal_pose=None
        self.model_command=None
        self.input=None

        # Environment interface
        self.input_publisher = self.create_publisher(
            RobotModelInterface,'/model_input',
            10)
        
        self.model_command_subscription = self.create_subscription(
            RobotModelInterface,'model_command', # This subscription has to be set for every type of problem
            self.get_model_command,1)
        
        # Optimization interface
        self.topic_subscription = self.create_subscription(
            RobotModelInterface,'topic', # This subscription has to be set for every type of problem
            self.get_input,10)
        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def get_model_command(self,msg):
        self.model_command=msg

    def get_input(self,msg):
        self.input=msg

    def timer_callback(self):
        """
        data parsing and other stuff
        """
        # Transform model output for ros format
        model_input=RobotModelInterface()
        model_input.timestamp=self.get_clock().now().to_msg()
        model_input.value=self.input
        

        self.input_publisher.publish(model_input)

def main(args=None):
    rclpy.init(args=args)

    TC = robot_interface_node()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
