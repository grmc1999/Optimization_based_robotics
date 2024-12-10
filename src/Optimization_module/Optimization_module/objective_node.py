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
        self.declare_parameter('batch_size',1000)

        self.data_batch=[]
        self.state_batch=[]
        self.set_params()

    def set_params(self):
        #self.model_mode=str(self.get_parameter('mode').get_parameter_value().string_value)
        #self.model_topic=str(self.get_parameter('model_topic').get_parameter_value().string_value)
        self.batch_size=int(self.get_parameter('batch_size').get_parameter_value().integer_value)
    
    def get_performance(self,msg):
        """
        Performance structure
        Performance.timestamp -> int?
        Performance.model_values -> list of float32
        Performance.robot_state -> list of float32
        Processed_data.episode_end -> bool
        """
        self.model_performance=msg

        if len(self.data_batch)<self.batch_size:
            print("observing model values")
            print(self.model_performance.model_values)
            #self.get_logger().info(self.model_performance.model_values)
            self.data_batch.append(self.model_performance.model_values[0])
            self.state_batch.append(self.model_performance.robot_state[0])
        else:
            #if self.model_mode!="deploy":
                # Send information related to performance
                # TODO ADD timestamp
                #Performance=PerformanceData()
                #Performance.model_values=self.data_batch
                #Performance.robot_state=self.state_batch
                #Performance.episode_end=True
                #self.model_output_publisher.publish(Performance)
            self.model_performance.robot_state
            Performance=OptimizationData()
            Performance.timestamp=self.get_clock().now().to_msg()
            Performance.loss=float(self.objective_function(self.state_batch))
            Performance.episode_end=True
            self.loss_publisher.publish(Performance)
            self.end_condition_val=True

            self.data_batch=[0]
            self.state_batch=[0]

        
        # Add size before update
        #self.model_performance.robot_state
        #Performance.timestamp=self.get_clock().now().to_msg()
        #Performance.loss=float(self.objective_function(
        #        self.model_performance.robot_state
        #        ))
        #
        #self.end_condition_val=self.model_performance.episode_end
        #Performance.episode_end=False
        #self.loss_publisher.publish(Performance)
        #self.cond_pose=self.position.pose.pose.position.x

    def check_end_condition(self):

        return False
    
    def timer_callback(self):
        """
        Optimization structure
        Processed_data.timestamp -> int?
        Processed_data.loss -> float32
        Processed_data.episode_end -> bool
        """
        
        # Check end of the episode
        #Performance.episode_end=
        self.set_params()
        
        # Case of end of the episode with fake performance (might be service)
        if self.check_end_condition():
            Performance=OptimizationData()
            Performance.timestamp=self.get_clock().now().to_msg()
            Performance.loss=float(self.objective_function(self.state_batch))
            Performance.episode_end=True
            self.loss_publisher.publish(Performance)
            self.end_condition_val=True

            self.data_batch=[0]
            self.state_batch=[0]

            #self.end_condition_val=False
            #self.model_performance = None
        

        
        

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
            #time.sleep(1.)


                


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
