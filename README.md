# Optimization_based_robotics

# Messages

Performance structure
    builtin_interfaces/Time stamp
    Performance.model_values -> list of float32
    Performance.robot_state -> list of float32
    Processed_data.episode_end -> bool

Robot_Model_Interface structure
    builtin_interfaces/Time stamp
    Performance.data -> list of float32

Model_processed_data structure
    Processed_data.timestamp -> int?
    Processed_data.values -> list

Optimization structure
    Processed_data.timestamp -> int?
    Processed_data.loss -> float32
    Processed_data.episode_end -> bools

- [ ] Create optimization messages
    - define symbolic or data based
    - algorithm type

- [ ] For Optimization node
    -[ ] a service should be defined for model update


## Model node

### Description

Model node parameters:
- Mode: [train, test, deploy]
    - train: optimization algorithm with parameter updates will run
    - test: only output
    - deploy: just necessary computation to take the decisions that the model have to make
- batch: integer
    Also consider the posibility to use time optimized batch size

node methods
- model: should have forward, train, test and deploy methods
- timer_callback



### Code

### Directions

- [ ] communitation with Objective node?
    - simbolic or impirically?

- [ ] Should multiple models be manage with remap?

node methods


## Sensor processing node

### Code

### Directions

- [ ] Should sensor processing take model output?

## Objective node

### Description

Objective node is isolated, so that multiple Objective nodes might be create for multiple models or combination of objectives

Node parameters:
- Mode: [train, test, deploy]
    - train: optimization algorithm with parameter updates will run
    - test: only output

### Code



### Directions

- [ ] Objective node might be implemented as a service



rmc1999@LAPTOP-E0H966EI:/mnt/d/Documentos/PUC-Rio/Maestrado/ELE2363/Optimization_based_robotics$ gz service -i -s world/empty/set_pose
Service providers [Address, Request Message Type, Response Message Type]:
  tcp://172.23.63.51:35871, gz.msgs.Pose, gz.msgs.Boolean
grmc1999@LAPTOP-E0H966EI:/mnt/d/Documentos/PUC-Rio/Maestrado/ELE2363/Optimization_based_robotics$ gz service -i -s world/empty/remove
Service providers [Address, Request Message Type, Response Message Type]:
  tcp://172.23.63.51:35871, gz.msgs.Entity, gz.msgs.Boolean
grmc1999@LAPTOP-E0H966EI:/mnt/d/Documentos/PUC-Rio/Maestrado/ELE2363/Optimization_based_robotics$ gz service -i -s world/empty/create
Service providers [Address, Request Message Type, Response Message Type]:
  tcp://172.23.63.51:35871, gz.msgs.EntityFactory, gz.msgs.Boolean