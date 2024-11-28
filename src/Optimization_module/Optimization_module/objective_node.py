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

from ob_robotics_interface.msg import PerformanceData
#from ob_robotics_interface.msg import Robot_Model_Interface
from ob_robotics_interface.msg import OptimizationData
#import rospy


class Objective_node(Node):
    """
    Input: Model data
    Output: Computed loss or losses
    """

    def __init__(self):
        super().__init__('Objective')

        #self.declare_parameter('Mode',"train")
        self.current_loss=None
        self.model_performance=None

        # Objective definitin
        self.objective_function=(lambda x,y:np.mean(x**2)+np.mean(y))
        
        # Optimization interface
        self.model_output_subscription = self.create_subscription(
            PerformanceData,'Performance_Data', # TODO: Check if this topic is remaped
            self.get_performance,10)
        
        self.loss_publisher = self.create_publisher(
            OptimizationData,
		    'optimization_input',
		    10)
        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)


    def get_performance(self,msg):
        """
        Performance structure
        Performance.timestamp -> int?
        Performance.model_values -> list of float32
        Performance.robot_state -> list of float32
        Processed_data.episode_end -> bool
        """
        self.model_performance=msg

#    def model_mode(self):
#        self.model_mode=str(self.get_parameter('mode').get_parameter_value().string)

    def end_condition(self):
        return False
    
    def timer_callback(self):
        """
        Optimization structure
        Processed_data.timestamp -> int?
        Processed_data.loss -> float32
        Processed_data.episode_end -> bool
        """
        Performance=OptimizationData()
        # Check end of the episode
        if self.model_performance != None:
            #print(len(self.model_performance.robot_state))
            #print(len(self.model_performance.model_values))

            # Add size before update
            self.model_performance.robot_state
            Performance.loss=float(self.objective_function(
                    self.model_performance.robot_state
                    ))
            
            Performance.episode_end=self.end_condition()
            
            self.loss_publisher.publish(Performance)
            self.model_performance = None


                


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
