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


class Model_node(Node):
    """
    Input: sensors or product of sensor
        The topics for input should be already parsed in order for model node to use it succesfully
    Output: command to any actuator topic
    """

    def __init__(self):
        super().__init__('Model')

        self.declare_parameter('Mode',"train")
        # mode should be train, test, deploy
        # Assertion for defined modes

        #self.goal_pose=None

        # Environment interface
        self.input_subscription = self.create_subscription(
            Processed_data,'model_input', # TODO: Check if this topic is remaped
            self.get_input,10)
        
        self.command_publisher = self.create_publisher(
            Processed_data,
		    'model_command',
		    10)
        
        # Optimization interface
        self.loss_subscription = self.create_subscription(
            optimization_data,'optimization_input', # TODO: Check if this topic is remaped
            self.get_input,10)
        
        self.model_output_publisher = self.create_publisher(
            Performance_data,
		    'performance_data',
		    10)

        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        # Model definition
        #self.model=

    def get_input(self,msg):
        self.input=msg

    def model_mode(self):
        self.model_mode=str(self.get_parameter('mode').get_parameter_value().string)

    def timer_callback(self):
        self.model_mode()
        model_output=Processed_data()
        Performance=Performance_data()

        model_output=getattr(self.model,self.model_mode)(self.input)
        model_output.output_data
        #if self.model_mode=="train":
        #elif self.model_mode=="test":
        #self.model_mode=="deply":
        self.model()
        
        if self.goal_pose!=None:
            #pd=self.pose_distance(self.current_pose,self.goal_pose)
            #v_u.twist.linear.x,v_u.twist.angular.z=min(self.K_x*pd.x,0.1),self.K_z*pd.theta
            #self.velocity_publisher.publish(v_u)
            print("original")
            print(self.goal_pose)
            pd=self.buffer.transform(self.goal_pose,"base_link")
            print("transformed")
            print(pd)
            distance=(pd.point.x**2+pd.point.x**2)**0.5
            theta=math.atan2(pd.point.y,pd.point.x)
            v_u.twist.linear.x,v_u.twist.angular.z=min(self.K_x*distance,0.1),self.K_z*theta
            self.velocity_publisher.publish(v_u)


    def pose_distance(self,cp,gp):
        dp=Pose()
        dp.x,dp.y=gp.x-cp.x,gp.y-cp.y
        theta=math.atan2(dp.y,dp.x)
        dp.x=math.sqrt(dp.x**2+dp.y**2)
        dp.theta=angles.shortest_angular_distance(cp.theta,theta)
        return dp
    
    def set_gains(self):
        self.K_x=float(self.get_parameter('K_x').get_parameter_value().double_value)
        self.K_y=float(self.get_parameter('K_y').get_parameter_value().double_value)
        self.K_z=float(self.get_parameter('K_z').get_parameter_value().double_value)

def main(args=None):
    rclpy.init(args=args)

    TC = Turtle_Controller()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
