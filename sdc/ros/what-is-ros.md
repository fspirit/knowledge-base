### ROS

**ROS** is a set of software components and tools, which can be used to design a software part of a robot.

Essentialy a running ROS is a set of unix processes (nodes), that communicate with each other by sending messages via
- Pubsub (send/subscribe to topics)
- Request/Response (1to1 communication)

There is a **master process** that spawns/controls all other running nodes and contains common settings.

ROS SDK includes build tools, ...