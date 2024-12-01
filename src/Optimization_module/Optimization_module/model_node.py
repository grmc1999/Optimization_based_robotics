import rclpy
from rclpy.node import Node


from ob_robotics_interface.msg import PerformanceData
from ob_robotics_interface.msg import RobotModelInterface
from ob_robotics_interface.msg import OptimizationData


#import rospy
import numpy as np


class Model_node(Node):
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
        super().__init__('Model')


        # Environment interface
        self.input_subscription = self.create_subscription(
            RobotModelInterface,'/model_input', # TODO: Check if this topic is remaped
            self.get_env_input,10)
        
        self.command_publisher = self.create_publisher(
            RobotModelInterface,
		    'model_command', 
		    10)
        
        # Optimization interface
        self.loss_subscription = self.create_subscription(
            OptimizationData,'optimization_input', # TODO: Check if this topic is remaped
            self.get_optimization_input,10)
        
        self.model_output_publisher = self.create_publisher(
            PerformanceData,
		    'Performance_Data',
		    10)

        
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.declare_parameter('mode',"train")
        self.declare_parameter('batch_size',100)
        self.declare_parameter('model_topic',"opt_debug")
        # mode should be train, test, deploy
        # Assertion for defined modes

        # Model definition
        #self.model=

        self.data_batch=[]
        self.state_batch=[]
        #self.loss_input=None
        self.loss_input=None
        #self.loss_input.
        self.episode_end=False
        self.input=None



        

    def get_env_input(self,msg):
        """
        loss structure
        loss.timestamp -> int?
        loss.value -> float32
        """
        self.set_model_mode()
        self.input=msg
        if len(self.data_batch)<self.batch_size:
            self.data_batch.append(self.input.value)
            self.state_batch.append(self.sensor_value)
        else:
            if self.model_mode!="deploy":
                # Send information related to performance
                # TODO ADD timestamp
                Performance=PerformanceData()
                Performance.model_values=self.data_batch
                Performance.robot_state=self.state_batch
                Performance.episode_end=True
                self.model_output_publisher.publish(Performance)
            self.data_batch=[self.input.value]
            self.state_batch=[self.sensor_value]
    
    def get_optimization_input(self,msg):
        """
        loss structure
        loss.timestamp -> int?
        loss.value -> float32
        """
        self.set_model_mode()
        self.loss_input=msg
        self.episode_end=self.loss_input.episode_end
        print("update function")
        self.update_function()

    def set_model_mode(self):
        self.model_mode=str(self.get_parameter('mode').get_parameter_value().string_value)
        self.model_topic=str(self.get_parameter('model_topic').get_parameter_value().string_value)
        self.batch_size=int(self.get_parameter('batch_size').get_parameter_value().integer_value)

    def update_function(self,model):
        return model

    def in_episode_routine(self):
        #self.get_optimization_input()
        self.set_model_mode()

        if self.input!=None:
            model_out=getattr(self.model,self.model_mode)(self.data_batch)

            model_output=RobotModelInterface()
            model_output.timestamp=self.get_clock().now().to_msg()
            model_output.value=model_out
            self.command_publisher.publish(model_output)

        # consider updating the model in an individual process
        #if len(self.data_batch)<self.batch_size: # TODO add or end of episode

        # UPDATE SHOULD RUN IF THERE IS NEW LOSS ON BATCH SIZE
        #if self.loss_input!=None:
            
            #run model update
            
        
        

    def episode_end_routine(self):
        model_output=RobotModelInterface()
        model_output.timestamp=self.get_clock().now().to_msg()
        model_output.value=np.random.uniform(0,1)

        # consider updating the model in an individual process
        #if len(self.data_batch)<self.batch_size: # TODO add or end of episode
        if self.loss_input!=None:
            #run model update
            self.update_function()
        
        self.command_publisher.publish(model_output)
        self.episode_end=False

    def timer_callback(self):
        """
        Performance structure
        Performance.timestamp -> int?
        Performance.model_values -> list of float32
        Performance.robot_state -> list of float32
        Processed_data.episode_end -> bool

        Model_processed_data structure
        Processed_data.timestamp -> 
        Processed_data.values -> list
        """
        if self.episode_end:
            self.episode_end_routine()
        elif not(self.episode_end):
            self.in_episode_routine()
        


def main(args=None):
    rclpy.init(args=args)

    TC = Model_node()

    rclpy.spin(TC)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    TC.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
