# W5100S-EVB-Pico DHCP IP Address Example with Arduino IDE

This repository contains a simple example demonstrating how to obtain an IP address using the Dynamic Host Configuration Protocol (DHCP) with the W5100S-EVB-Pico board and the Arduino IDE. The example initializes the Ethernet connection using a provided MAC address and the chip select pin (17 for W5100S-EVB-Pico). If the DHCP process is successful, the obtained IP address is printed to the Serial Monitor.

**Note: The W5100S-EVB-Pico board must be connected to a DHCP server or router to use this example.**

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE with W5100S-EVB-Pico board support and the WIZnet Ethernet library installed
-   A DHCP server or router for IP address assignment

## Setup

1.  Connect the W5100S-EVB-Pico board to your computer using a USB cable.
2.  Open the Arduino IDE and select the "W5100S-EVB-Pico" board from the "Tools" > "Board" menu.
3.  Open the "DHCP_IP_Address" sketch provided in this repository.
4.  In the sketch, the line `Ethernet.init(csPin);` initializes the Ethernet library and configures the chip select (CS) pin for the W5100S Ethernet controller on the W5100S-EVB-Pico board. The `csPin` variable is set to 17, which is the appropriate chip select pin for the W5100S Ethernet controller on the W5100S-EVB-Pico board.
5.  Upload the sketch to the W5100S-EVB-Pico board.

## Usage

1.  Open the Serial Monitor in the Arduino IDE by going to "Tools" > "Serial Monitor."
2.  Set the baud rate to 9600 in the Serial Monitor.
3.  The sketch will attempt to obtain an IP address using DHCP. If successful, the IP address will be printed to the Serial Monitor.

## Example Output

The output on the Serial Monitor should look similar to the following:

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.177` 
```

The specific IP address will depend on your network configuration.

## Notes

This example serves as a starting point for learning how to use DHCP with the W5100S-EVB-Pico board in the Arduino IDE. You can expand on this example by implementing additional Ethernet functionality, such as creating web servers or clients, and working with TCP/UDP sockets.