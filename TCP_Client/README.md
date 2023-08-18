# TCP Client Example for W5100S-EVB-Pico

This example demonstrates how to create a simple TCP client using the W5100S-EVB-Pico in the Arduino IDE. The client connects to a remote server, sends a "Hello, Server!" message once when connecting for the first time, and prints any received response from the server.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE installed on your computer
-   Ethernet cable
-   A remote server to connect to

## Setup

1.  Set up your Arduino IDE with the W5100S-EVB-Pico board and necessary libraries, as explained in the main repository's README.
2.  Open the TCP Client example code in the Arduino IDE.
3.  Update the `serverIP` and `serverPort` variables in the code with the IP address and port number of the remote server you want to connect to.

## Usage

1.  Connect your W5100S-EVB-Pico board to your local network using an Ethernet cable.
2.  Compile and upload the code to your W5100S-EVB-Pico board.
3.  Open the Serial Monitor in the Arduino IDE and set the baud rate to 9600.

## Example Output

Observe the output in the Serial Monitor as the W5100S-EVB-Pico connects to the server, sends the "Hello, Server!" message, and receives any responses:

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.123
Connecting to remote server...
Connected to the server
Message sent to server.
Received from server: H
Received from server: e
Received from server: l
Received from server: l
Received from server: o
```

## Notes

-   Make sure your W5100S-EVB-Pico is connected to your local network, and the remote server is running and accessible.
-   The example assumes that your remote server is set up to accept incoming TCP connections and responds to the received messages.