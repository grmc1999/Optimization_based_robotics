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
            Processed_data,'model_input',
            10)
        
        # Optimization interface
        self.topic_subscription = self.create_subscription(
            topic_type,'topic', # This subscription has to be set for every type of problem
            self.get_input,10)
        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def get_input(self,msg):
        self.input=msg

    def timer_callback(self):
        """
        data parsing and other stuff
        """
        model_output=Processed_data()



        model_out=getattr(self.model,self.model_mode)(self.input)
        model_output.output_data=model_out
        if self.model_mode!="deploy":
            # Send information related to performance
            self.model_output_publisher.publish(Performance)

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
