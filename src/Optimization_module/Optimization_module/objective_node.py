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

from ros_gz_interfaces.srv import SetEntityPose
import time


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

        self.cli = self.create_client(SetEntityPose, 'world/empty/set_pose')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = SetEntityPose.Request()
        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        #self.episode_end=False
        self.end_condition_val=False


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

    def check_end_condition(self):
        

        #self.req.

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
        Performance.episode_end=self.check_end_condition()
        if self.model_performance != None:
            print("recieved model performance")

            # Add size before update
            self.model_performance.robot_state
            Performance.timestamp=self.get_clock().now().to_msg()
            Performance.loss=float(self.objective_function(
                    self.model_performance.robot_state
                    ))
            
            #self.episode_end=self.model_performance.episode_end
            print("setting end condition by model performance msg value ",self.model_performance.episode_end)
            self.end_condition_val=self.model_performance.episode_end
            #Performance.episode_end=self.model_performance.episode_end
            Performance.episode_end=False
            self.loss_publisher.publish(Performance)
            self.model_performance = None
        # Case of end of the episode with fake performance (might be service)
        elif (Performance.episode_end):
            print("end by physical conditions")
            
            Performance.timestamp=self.get_clock().now().to_msg()
            Performance.loss=float(1e5) # Artificially setting high error
            
            #self.episode_end=self.model_performance.episode_end
            print("setting end condition by physical bounds value ",Performance.episode_end)
            #self.end_condition_val=Performance.episode_end
            Performance.episode_end=Performance.episode_end
            self.loss_publisher.publish(Performance)

            #self.end_condition_val=False
            self.model_performance = None
        

        
        

        if self.end_condition_val:
            
            self.req.entity.name="my_gpg" #TODO: add flexibility for parallel simulation
            self.req.entity.id=0
            self.req.entity.type=0
            self.req.pose.position.z=0.1
            self.req.pose.position.x=0.
            self.req.pose.position.y=0.
            self.req.pose.orientation.z=0.
            self.req.pose.orientation.x=0.
            self.req.pose.orientation.y=0.
            self.req.pose.orientation.w=1.
    
            self.future = self.cli.call_async(self.req)
            #self.future = self.cli.call(self.req)
            #rclpy.spin_until_future_complete(self, self.future)
            self.end_condition_val=False
            time.sleep(0.2)


                


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
