# TCP Server Example for W5100S-EVB-Pico

This example demonstrates how to create a simple TCP server using the W5100S-EVB-Pico in the Arduino IDE. The server listens for incoming connections on a specified port, reads the received messages from clients, and sends a "Hello, Client!" response back to the connected clients.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE installed on your computer
-   Ethernet cable

## Setup

1.  Set up your Arduino IDE with the W5100S-EVB-Pico board and necessary libraries, as explained in the main repository's README.
2.  Open the TCP Server example code in the Arduino IDE.

## Usage

1.  Connect your W5100S-EVB-Pico board to your local network using an Ethernet cable.
2.  Compile and upload the code to your W5100S-EVB-Pico board.
3.  Open the Serial Monitor in the Arduino IDE and set the baud rate to 9600.

## Example Output

Observe the output in the Serial Monitor as the W5100S-EVB-Pico starts the server and listens for incoming connections:

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.123
Server started on port 80
New client connected
Received from client: H
Received from client: e
Received from client: l
Received from client: l
Received from client: o
Client disconnected
```

## Notes

-   Make sure your W5100S-EVB-Pico is connected to your local network.
-   This example assumes that your network allows incoming connections on the specified port.
-   You can test the server by connecting to it using a TCP client, such as the one created in the TCP Client example.