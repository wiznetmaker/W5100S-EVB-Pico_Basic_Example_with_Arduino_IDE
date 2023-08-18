# UDP Sender Example for W5100S-EVB-Pico

This example demonstrates how to create a simple UDP sender using the W5100S-EVB-Pico board and the Arduino IDE. UDP (User Datagram Protocol) is a connectionless protocol that is used to send packets over the network without establishing a direct connection between the sender and receiver. It is faster and consumes fewer resources than TCP but does not guarantee the delivery of packets or their order.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE
-   WIZnet Ethernet library for W5100S-EVB-Pico
-   A device or application acting as a UDP receiver, configured to listen on the specified remote IP address and port

## Setup

1.  Install the WIZnet Ethernet library for W5100S-EVB-Pico in the Arduino IDE.
2.  Connect the W5100S-EVB-Pico board to your computer.
3.  Open this example in the Arduino IDE.
4.  Configure the `remoteIP` variable with the IP address of the UDP receiver you want to send messages to.
5.  Configure the `remotePort` variable with the port number of the UDP receiver you want to send messages to.
6.  Upload the sketch to the W5100S-EVB-Pico board.

## Usage

1.  Open the Serial Monitor in the Arduino IDE.
2.  The sketch will attempt to obtain an IP address using DHCP. If successful, the obtained IP address will be printed in the Serial Monitor.
3.  The sketch will send a "Hello, UDP Receiver!" message to the specified remote IP address and port every 2 seconds.

## Example Output

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.100
```

The output in the Serial Monitor will show the obtained IP address. The "Hello, UDP Receiver!" message will be sent to the specified remote IP and port every 2 seconds, but this will not be displayed in the Serial Monitor.

## Notes

-   Ensure that the remote device or application acting as a UDP receiver is properly set up to listen for incoming packets on the specified IP address and port.
-   This example only demonstrates sending UDP packets. To receive and process incoming packets, you will need to implement a UDP receiver.