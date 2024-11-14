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


class Objective_node(Node):
    """
    Input: Model data
    Output: Computed loss or losses
    """

    def __init__(self):
        super().__init__('Model')

        #self.declare_parameter('Mode',"train")
        self.current_loss=None
        self.model_performance=None

        # Objective definitin
        self.objective_function=(lambda x,y:np.mean(x**2)+np.mean(y))
        
        # Optimization interface
        self.model_output_subscription = self.create_subscription(
            Performance_data,'performance_data', # TODO: Check if this topic is remaped
            self.get_performance,10)
        
        self.loss_publisher = self.create_publisher(
            Optimization_data,
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
        """
        self.model_performance=msg

    def model_mode(self):
        self.model_mode=str(self.get_parameter('mode').get_parameter_value().string)

    def end_condition(self,state):
        return not(state<0.5)
    
    def timer_callback(self):
        """
        Processed_data structure
        Processed_data.timestamp -> int?
        Processed_data.topic -> string
        Processed_data.values -> float32
        Processed_data.episode_end -> bool
        """
        Performance=Performance_data()
        # Check end of the episode
        if self.model_performance != None:
            self.model_performance.robot_state
            if self.end_condition(self.model_performance.robot_state):
                Performance.topic="opt_debug"
                Performance.values=self.loss_function(
                    self.model_performance.model_values,
                    self.model_performance.robot_state
                    )
                Performance.episode_end=False
            else:
                Performance.topic="opt_debug"
                Performance.values=self.loss_function(
                    self.model_performance.model_values,
                    self.model_performance.robot_state
                    )
                Performance.episode_end=True
            
            self.loss_publisher.publish(Performance)


                


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
