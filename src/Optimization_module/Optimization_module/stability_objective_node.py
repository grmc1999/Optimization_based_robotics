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
#from ob_robotics_interface.msg import Robot_Model_Interface
#from ob_robotics_interface.msg import Optimization_data
#import rospy

from .objective_node import Objective_node

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
        self.objective_function=(lambda x:np.mean((np.array(x)-self.ref)**2)) # Consider weight with time

    def end_condition(self):
        is_end=False
        print(len(self.model_performance.model_values))
        if len(self.model_performance.model_values)>10:
            is_end=True
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
