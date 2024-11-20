import rclpy
from rclpy.node import Node


from OB_robotics_interface.msg import Performance_data
from OB_robotics_interface.msg import Robot_Model_Interface
from OB_robotics_interface.msg import Optimization_data

#import rospy


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

        self.declare_parameter('Mode',"train")
        self.declare_parameter('batch_size',1)
        self.declare_parameter('model_topic',"opt_debug")
        # mode should be train, test, deploy
        # Assertion for defined modes

        # Model definition
        #self.model=

        self.data_batch=[]


        # Environment interface
        self.input_subscription = self.create_subscription(
            Robot_Model_Interface,'model_input', # TODO: Check if this topic is remaped
            self.get_env_input,10)
        
        self.command_publisher = self.create_publisher(
            Robot_Model_Interface,
		    'model_command', 
		    10)
        
        # Optimization interface
        self.loss_subscription = self.create_subscription(
            Optimization_data,'optimization_input', # TODO: Check if this topic is remaped
            self.get_optimization_input,10)
        
        self.model_output_publisher = self.create_publisher(
            Performance_data,
		    'performance_data',
		    10)

        
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        

    def get_optimization_input(self,msg):
        """
        loss structure
        loss.timestamp -> int?
        loss.value -> float32
        """
        self.model_mode()
        self.input=msg
        if len(self.data_batch)<self.batch_size:
            self.data_batch.append(self.input.value)
    
    def get_env_input(self,msg):
        """
        loss structure
        loss.timestamp -> int?
        loss.value -> float32
        """
        self.model_mode()
        self.env_input=msg

    def model_mode(self):
        self.model_mode=str(self.get_parameter('mode').get_parameter_value().string)
        self.model_topic=str(self.get_parameter('topic').get_parameter_value().string)
        self.batch_size=str(self.get_parameter('batch_size').get_parameter_value().integer)

    def update_function(self,model,data_batch):
        return model

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
        self.model_mode()

        model_out=getattr(self.model,self.model_mode)(self.input)

        model_output=Robot_Model_Interface()
        model_output.timestamp="model_debug"
        model_output.values=model_out

        Performance=Performance_data()

        Performance.model_values=model_out
        Performance.robot_state=self.model_topic

        if self.model_mode!="deploy":
            # Send information related to performance
            self.model_output_publisher.publish(Performance)

        # consider updating the model in an individual process
        if len(self.data_batch)<self.batch_size: # TODO add or end of episode
            #run model update
            self.update_function(self.model,self.data_batch)
        
        self.command_publisher.publish(model_output)


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
