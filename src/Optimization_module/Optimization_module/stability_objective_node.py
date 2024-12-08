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

from functools import reduce


#from ob_robotics_interface.msg import Performance_data
#from ob_robotics_interface.msg import Robot_Model_Interface
#from ob_robotics_interface.msg import Optimization_data
#import rospy

from .objective_node import Objective_node

from ros_gz_interfaces.srv import SetEntityPose

from sensor_msgs.msg import Imu

class Objective_node(Objective_node):
    """
    Input: Model data
    Output: Computed loss or losses
    """

    def __init__(self):
        super().__init__()

        self.ref=0
        # Objective definitin
        #self.objective_function=(lambda x,y:np.mean((np.array(x)-np.array(y))**2)) # Consider weight with time
        self.objective_function=(lambda x:np.sum((np.array(x)-self.ref)**2)) # Consider weight with time

        self.interface_topic_subscription = self.create_subscription(
            Odometry,'/diff_drive_controller/odom', # This subscription has to be set for every type of problem
            self.get_condition_sensor,10)
        
        self.interface_topic_subscription = self.create_subscription(
            Imu,'/imu', # This subscription has to be set for every type of problem
            self.get_angle_condition,10)
        
        self.end_condition_val=False
        self.position=None
        self.cond_pose=0
        self.sensor_value=0

    def get_condition_sensor(self,msg):
        self.position=msg
        #self.cond_pose=self.position.pose.pose.position.x
    
    def get_angle_condition(self,msg):
        
        orientation=euler_from_quaternion([
		        msg.orientation.x,
		        msg.orientation.y,
		        msg.orientation.z,
		        msg.orientation.w
                ])
        self.sensor_value=float(orientation[1])
        

    def check_end_condition(self):
        is_end=False
        #if self.position!=None:
        #    print("end condif")
        #    print(len(self.model_performance.model_values))
        #    print(self.position.pose.pose.position.x)
        #if (self.position.pose.pose.position.x-self.cond_pose>5. or self.position.pose.pose.position.x-self.cond_pose<-5.):
        if self.position!=None:
            cond_array = [
                self.position.pose.pose.position.x-self.cond_pose>5,
                self.position.pose.pose.position.x-self.cond_pose<-5.,
                self.sensor_value>0.7,
                self.sensor_value<-0.7
            ]
            if reduce(lambda a,b:a or b,cond_array):
                    print(self.sensor_value)
            #if (self.position.pose.pose.position.x>5. or self.position.pose.pose.position.x<-5.):
                    print("Condition satis")
                    self.cond_pose=self.position.pose.pose.position.x
                    print("episode end")
                    is_end=True
            
        self.end_condition_val=is_end

            
        return is_end

def main(args=None):
    rclpy.init(args=args)

    TC = Objective_node()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
