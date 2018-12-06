## Modern Vehicle Hardware Overview

Modern vehicle is packed with electronics. It contains tens of ECUs (Integrated Controller Units), which are connected which different kind of network technologies.
Usually there is a several main ECUs like head unit ECUs (Infortainment/Navigation system), basic routing ECU and lost of ECUs that a tightly couples to certain sensor/actuator  or provide some particular function (like watching for obstacle in front or behind the vehicle).

### Internal network technologies

Here is the list of most popular technologies, which are used to interconnect ECUs:

* LIN bus
* CAN/CAN-FD buses
* FlexRay bus
* Ethernet

#### LIN bus

LIN bus is the simplest and a cheapest option to connect several ECUs.
It has 2 wires ???. Bitrate is low.

Its a single master bus, which means that only one node can initialte communication on the bus (other nodes have slave roles). Also that means that there is no need for bus arbitration.

#### CAN/CAN-FD buses

CAN bus is standardized by a set of ISO standards. Physically it has 2 wires.
Its a multi-master bus with bus arbitration guided by message priority field. Only 1 bit can be read from/put to the bus during 1 time slice, 0 is high and 1 is low. 0 always overwrites 1. When no node is writing the bus contains 1.
Every time slice each node can just read current bus bit or it can write its bit (when the previos value was 1) to the bus and see what the value actually delivered to the bus.

**Arbitration**

Every new message from any node starts from 0 and then the message id follows. Message id which has lower binary value has a higher priority.
Thats is message with id 0000 has higher priority than message with id 0101. When two notes start writing in the same time, eventually node 2 will discover that it tried to wrote 1 but the bus contains 0. Which means that a message with higher priority is currently being written to the bus, so node 2 stops writing.