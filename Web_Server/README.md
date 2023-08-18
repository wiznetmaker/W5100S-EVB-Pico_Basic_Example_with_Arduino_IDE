# Web Server Example using W5100S-EVB-Pico

This example demonstrates how to create a simple web server using the W5100S-EVB-Pico board. The web server serves a basic HTML page when accessed from a web browser.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE
-   WIZnet Ethernet Library for W5100S-EVB-Pico (installed)
-   Raspberry Pi Pico/RP2040 Board Support Package (installed)

## Setup

1.  Connect your W5100S-EVB-Pico board to your computer.
2.  Open the Arduino IDE and set the board to "Raspberry Pi Pico/RP2040".
3.  Set the correct port for your board.

## Usage

1.  Upload the provided example code to your W5100S-EVB-Pico board.
2.  Open the Serial Monitor in the Arduino IDE (Tools > Serial Monitor).
3.  The Serial Monitor should display the obtained IP address using DHCP.
4.  Open a web browser on a device connected to the same network as the W5100S-EVB-Pico board.
5.  Enter the IP address displayed in the Serial Monitor into the web browser's address bar.
6.  You should see the basic HTML page served by the web server on your W5100S-EVB-Pico board.

## Example Output

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.100
Web server started. Listening for incoming connections...
```

## Notes

-   Make sure your W5100S-EVB-Pico board is connected to the same network as your computer or other device that you will use to access the web server.
-   If the board fails to obtain an IP address using DHCP, check your network connection and ensure your router is set up to provide IP addresses via DHCP.
-   The example code provided serves a very basic HTML page. You can modify the code to serve more complex pages or dynamic content if needed.