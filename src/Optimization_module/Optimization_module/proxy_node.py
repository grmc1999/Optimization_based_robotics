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

from OB_robotics_interface.msg import Performance_data
from OB_robotics_interface.msg import Robot_Model_Interface
from OB_robotics_interface.msg import Optimization_data

#import rospy


class robot_interface_node(Node):
    """
    Input: sensors
    Output: Parse and simplified input for robot
    process:
        parsing sensor data, and maybe process multiple inputs in time
    """

    def __init__(self):
        super().__init__('Model')

        self.declare_parameter('Mode',"train")
        # mode should be train, test, deploy
        # Assertion for defined modes

        #self.goal_pose=None

        # Environment interface
        self.input_publisher = self.create_publisher(
            Robot_Model_Interface,'model_input',
            10)
        
        # Optimization interface
        self.topic_subscription = self.create_subscription(
            Robot_Model_Interface,'topic', # This subscription has to be set for every type of problem
            self.get_input,10)
        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def get_input(self,msg):
        self.input=msg

    def timer_callback(self):
        """
        data parsing and other stuff
        """
        # Transform model output for ros format
        model_input=Robot_Model_Interface()
        model_input.timestamp="model_debug"
        model_input.values=self.input

        #model_out=getattr(self.model,self.model_mode)(self.input)
        #model_output.output_data=model_out
        #if self.model_mode!="deploy":
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
