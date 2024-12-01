import rclpy
from rclpy.node import Node

from .model_node import Model_node

from .PID_model import basic_PID_model
from sensor_msgs.msg import Imu
from tf_transformations import euler_from_quaternion

#from ob_robotics_interface.msg import Performance_data
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
        self.declare_parameter('sample_size',3)
        #self.declare_parameter('sample_size',3)

        #DEFINE  MODEL
        self.model=basic_PID_model(
            Kp=0.1,
            Ki=0.1,
            Kd=0.1,
            T=0.1,
        )

        self.interface_topic_subscription = self.create_subscription(
            Imu,'/imu', # This subscription has to be set for every type of problem
            self.get_sensor_input,1)

        # OPTIMIZATION PROCEDURES
        
        self.parameters=np.random.uniform(0,2,(27,3))
        self.samples_results=[]
        self.sample_size=26
        self.selection_size=3
        self.prototypes_iter=0
        Kp,Ki,Kd=tuple(self.parameters[self.prototypes_iter])
        
        self.model.update_parameters({"Kp":Kp,"Ki":Ki,"Kd":Kd})
        self.sensor_value=0

        

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

        # OPTIMIZATION PROCEDURES
        sampling_result=[
                self.model.parameters,
                self.loss_input.loss
                ]
        
        self.samples_results.append(sampling_result)
        
        # set new params
        
        Kp,Ki,Kd=tuple(self.parameters[self.prototypes_iter])
        self.model.update_parameters({"Kp":Kp,"Ki":Ki,"Kd":Kd})
        print("update function")
        self.update_function()
        self.prototypes_iter=self.prototypes_iter+1
        

    
    def update_function(self):
        # Optimization alg

        # genetic
        if len(self.samples_results)>self.sample_size:
            self.prototypes_iter=0
            self.samples_results=np.array(self.samples_results)
            loss_mean=np.mean(self.samples_results[:,1])
            print(np.argsort(self.samples_results[:,1])[:-2])
            self.samples_results=self.samples_results[np.argsort(self.samples_results[:,1])[-(int(self.selection_size)):]]
            print(self.samples_results)
            print(self.samples_results.shape)

            # create new NxNxN
            best_params=self.samples_results[:,0]
            print(best_params)
            best_params=np.array(list(map(lambda d: list(d.values()),best_params)))
            print(best_params)
            print(best_params.shape)

            # combination
            self.parameters=np.array(list(product(*best_params)))
            # mutation
            self.parameters=abs(self.parameters+np.random.normal(0,loss_mean*0.1,self.parameters.shape)) # TODO: reduce scale wrt loss

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
