import rclpy
from rclpy.node import Node

from .model_node import Model_node

from .PID_model import basic_PID_model
from sensor_msgs.msg import Imu
from std_msgs.msg import Float64
from tf_transformations import euler_from_quaternion

from ob_robotics_interface.msg import PerformanceData
#from ob_robotics_interface.msg import Robot_Model_Interface
#from ob_robotics_interface.msg import Optimization_data

import numpy as np

#import rospy
from itertools import product


class PID_Model_node(Model_node):
    """
    Input: sensors or product of sensor
        The topics for input should be already parsed in order for model node to use it succesfully
    Output: command to any actuator topic

    Processing:
        three modes:
            train:
                - communicates with objective node, sending model outputs
                - perform model update
            test:
                - communicates with objective node, sending model outputs
                - do not perform model update
            deploy:
                - do not communicate with objective node
                - do not perform model update
    """

    def __init__(self):
        super().__init__()

        self.declare_parameter('selection_size',3)
        self.declare_parameter('sample_size',25)
        self.declare_parameter('mutation_magnitude',10.)
        #self.declare_parameter('sample_size',3)

        #DEFINE  MODEL
        self.model=basic_PID_model(
            Kp=0.1,
            Ki=0.1,
            Kd=0.1,
            T=0.01,
        )

        self.interface_topic_subscription = self.create_subscription(
            Imu,'/imu', # This subscription has to be set for every type of problem
            self.get_sensor_input,1)
        
        self.mean_loss_publisher = self.create_publisher(
            Float64,
		    'optimization_result',
		    10)

        # OPTIMIZATION PROCEDURES
        
        
        self.generation_c=0
        self.samples_results=[]
        self.sample_size=25
        self.selection_size=3
        self.prototypes_iter=0
        

        self.parameters=np.random.uniform(0,1,(self.sample_size+2,3))

        Kp,Ki,Kd=tuple(self.parameters[self.prototypes_iter])
        
        self.model.update_parameters({"Kp":Kp,"Ki":Ki,"Kd":Kd})
        self.sensor_value=0
        self.best_losses=[]

        

    def get_sensor_input(self,msg):
        
        orientation=euler_from_quaternion([
		        msg.orientation.x,
		        msg.orientation.y,
		        msg.orientation.z,
		        msg.orientation.w
                ])
        self.sensor_value=float(orientation[1])
        
    def get_optimization_input(self,msg):
        """
        loss structure
        loss.timestamp -> int?
        loss.value -> float32
        """
        self.set_model_mode()
        self.loss_input=msg
        self.episode_end=self.loss_input.episode_end

        print("recieving episode condition: ",self.episode_end)
        if self.loss_input.episode_end:
            if self.model_mode!="deploy":
                # Send information related to performance
                # TODO ADD timestamp
                Performance=PerformanceData()
                Performance.model_values=self.data_batch
                Performance.robot_state=self.state_batch
                Performance.episode_end=True
                self.model_output_publisher.publish(Performance)
            self.data_batch=[0]
            self.state_batch=[self.sensor_value]
        else:
            # OPTIMIZATION PROCEDURES
            sampling_result=[
                self.model.parameters,
                self.loss_input.loss
                ]
            self.samples_results.append(sampling_result)
            print("parameters length")
            print(len(self.parameters))
            Kp,Ki,Kd=tuple(self.parameters[self.prototypes_iter])
            self.get_logger().info('individual score: '+str(self.loss_input.loss)+', setting new individual')
            self.model.update_parameters({"Kp":Kp,"Ki":Ki,"Kd":Kd})
            print("update function")
            self.update_function()
            self.prototypes_iter=self.prototypes_iter+1
        

    def set_optimization_params(self):
        self.selection_size=(self.get_parameter('selection_size').get_parameter_value().integer_value)
        self.sample_size=(self.get_parameter('sample_size').get_parameter_value().integer_value)
        self.mutation_magnitude=(self.get_parameter('mutation_magnitude').get_parameter_value().double_value)

    
    def update_function(self):
        self.set_optimization_params()
        # Optimization alg

        # genetic
        if len(self.samples_results)>self.sample_size:
            self.generation_c=self.generation_c+1
            self.get_logger().info('creating new generation number '+str(self.generation_c))
            self.prototypes_iter=0
            self.samples_results=np.array(self.samples_results)
            
            self.samples_results=self.samples_results[np.argsort(self.samples_results[:,1])[:(int(self.selection_size))]]

            loss_mean=np.mean(self.samples_results[:,1])

            self.get_logger().info('best past generation scores '+str(loss_mean))

            self.best_losses.append(loss_mean)

            d=Float64()
            d.data=loss_mean
            self.mean_loss_publisher.publish(d)
            
            print("best params")
            print(self.samples_results)
            #self.get_logger().info(self.samples_results)
            # create new NxNxN
            best_params=self.samples_results[:,0]
            best_params=np.array(list(map(lambda d: list(d.values()),best_params)))

            # combination
            self.parameters=np.array(list(product(*best_params.T)))
            # mutation
            self.parameters=abs(self.parameters+np.random.normal(0,loss_mean*self.mutation_magnitude,self.parameters.shape)) # TODO: reduce scale wrt loss

            self.prototypes_iter=0
            Kp,Ki,Kd=tuple(self.parameters[self.prototypes_iter])
        
            self.model.update_parameters({"Kp":Kp,"Ki":Ki,"Kd":Kd})

            self.samples_results=[]


def main(args=None):
    rclpy.init(args=args)

    TC = PID_Model_node()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
