# Optimization_based_robotics

# Messages

- [ ] Create optimization messages
    - define symbolic or data based
    - algorithm type


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

- [ ] optimization losses might be computed in this node