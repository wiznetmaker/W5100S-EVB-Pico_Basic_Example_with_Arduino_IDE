# DNS Resolution Example with W5100S-EVB-Pico

This example demonstrates how to perform DNS resolution using the W5100S-EVB-Pico board with the Arduino IDE. The code resolves a domain name to an IP address and prints the resolved IP address to the Serial Monitor.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE
-   WIZnet Ethernet library for W5100S-EVB-Pico
-   Raspberry Pi Pico/RP2040 board support package
-   USB cable for programming and power

## Setup

1.  Install the WIZnet Ethernet library for W5100S-EVB-Pico by following the instructions in the main repository README.
2.  Install the Raspberry Pi Pico/RP2040 board support package for Arduino IDE.
3.  Open the provided example code in Arduino IDE.
4.  Change the `serverName` variable to the domain name you want to resolve.
5.  Connect the W5100S-EVB-Pico board to your computer using a USB cable.
6.  Select the appropriate board (W5100S-EVB-Pico) and port from the Arduino IDE.
7.  Upload the code to the board.

## Usage

1.  Open the Serial Monitor in Arduino IDE.
2.  The code will attempt to obtain an IP address using DHCP.
3.  Once an IP address is obtained, the code will perform DNS resolution for the specified domain name.
4.  The resolved IP address for the domain name will be printed in the Serial Monitor.

## Example Output

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.123
IP address for example.com: 93.184.216.34
```

In this example, the code successfully obtained an IP address using DHCP, resolved the domain name "example.com" to the IP address 93.184.216.34, and printed the result to the Serial Monitor.

## Notes

-   This example requires that the W5100S-EVB-Pico board is connected to a network with a DHCP server and internet access.
-   Make sure to change the `serverName` variable to the domain name you want to resolve.