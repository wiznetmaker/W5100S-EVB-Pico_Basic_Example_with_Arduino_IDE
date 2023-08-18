# Ethernet Initialization Example for W5100S-EVB-Pico

This example demonstrates how to initialize the W5100S Ethernet controller on the W5100S-EVB-Pico board using the Arduino IDE. The example also checks the status of the Ethernet controller and prints the network configuration to the Serial Monitor.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE with W5100S-EVB-Pico board support and the WIZnet Ethernet library installed

## Setup

1.  Connect the W5100S-EVB-Pico board to your computer using a USB cable.
2.  Open the Arduino IDE and select the "W5100S-EVB-Pico" board from the "Tools" > "Board" menu.
3.  Open the "Ethernet_Initialization" sketch provided in this folder.
4.  In the sketch, the line Ethernet.init(csPin); initializes the Ethernet library and configures the chip select (CS) pin for the W5100S Ethernet controller on the W5100S-EVB-Pico board. The csPin variable is set to 17, which is the appropriate chip select pin for the W5100S Ethernet controller on the W5100S-EVB-Pico board.
5.  Upload the sketch to the W5100S-EVB-Pico board.

## Usage

1.  Open the Serial Monitor in the Arduino IDE by going to "Tools" > "Serial Monitor."
2.  Set the baud rate to 9600 in the Serial Monitor.
3.  The sketch will initialize the Ethernet controller, check its status, and print the network configuration, including the MAC address, IP address, subnet mask, and gateway address.

## Example Output

The output on the Serial Monitor should look similar to the following:

```
Starting Ethernet connection...
Ethernet initialized
IP address: 192.168.0.8
Subnet mask: 255.255.255.0
Gateway IP: 192.168.0.1
DNS server IP: 8.8.8.8
```

The specific values for the IP address, subnet mask, and gateway address will depend on your network configuration.

## Notes

This example is a starting point for learning how to initialize the W5100S Ethernet controller and print network configuration details. You can expand on this example by implementing additional Ethernet functionality, such as DHCP IP address assignment, creating web servers or clients, and working with TCP/UDP sockets.