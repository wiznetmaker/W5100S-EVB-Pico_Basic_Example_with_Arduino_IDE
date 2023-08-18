# UDP Receiver Example for W5100S-EVB-Pico

This example demonstrates how to create a simple UDP receiver using the W5100S-EVB-Pico board and the Arduino IDE. UDP (User Datagram Protocol) is a connectionless protocol that is used to send packets over the network without establishing a direct connection between the sender and receiver. It is faster and consumes fewer resources than TCP but does not guarantee the delivery of packets or their order.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE
-   WIZnet Ethernet library for W5100S-EVB-Pico
-   A device or application acting as a UDP sender, configured to send packets to the IP address and port of the W5100S-EVB-Pico board

## Setup

1.  Install the WIZnet Ethernet library for W5100S-EVB-Pico in the Arduino IDE.
2.  Connect the W5100S-EVB-Pico board to your computer.
3.  Open this example in the Arduino IDE.
4.  Configure the `localPort` variable with the port number you want to listen for incoming UDP packets on.
5.  Upload the sketch to the W5100S-EVB-Pico board.

## Usage

1.  Open the Serial Monitor in the Arduino IDE.
2.  The sketch will attempt to obtain an IP address using DHCP. If successful, the obtained IP address will be printed in the Serial Monitor.
3.  The sketch will listen for incoming UDP packets on the specified local port. When a packet is received, the packet size, sender's IP address, sender's port, and packet contents will be printed in the Serial Monitor.

## Example Output

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.100
Received packet of size 20
From 192.168.1.150, port 8888
Contents: Hello, UDP Receiver!
```

The output in the Serial Monitor will show the obtained IP address and information about the received UDP packets, including the packet size, sender's IP address and port, and the packet contents.

## Notes

-   Ensure that the remote device or application acting as a UDP sender is properly set up to send packets to the IP address and port of the W5100S-EVB-Pico board.
-   This example only demonstrates receiving UDP packets. To send packets to other devices or applications, you will need to implement a UDP sender.