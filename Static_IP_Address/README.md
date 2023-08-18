# W5100S-EVB-Pico Static IP Address Example with Arduino IDE

This repository contains a simple example demonstrating how to configure a static IP address for the W5100S-EVB-Pico board using the Arduino IDE. The example initializes the Ethernet connection using a provided MAC address and the chip select pin (17 for W5100S-EVB-Pico). The Ethernet connection is started using the static IP address specified in the `ip` variable. The static IP address is then printed to the Serial Monitor.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE with W5100S-EVB-Pico board support and the WIZnet Ethernet library installed

## Setup

1.  Connect the W5100S-EVB-Pico board to your computer using a USB cable.
2.  Open the Arduino IDE and select the "W5100S-EVB-Pico" board from the "Tools" > "Board" menu.
3.  Open the "Static_IP_Address" sketch provided in this repository.
4.  Edit the `ip` variable to set your desired static IP address.
5.  Upload the sketch to the W5100S-EVB-Pico board.

## Usage

1.  Open the Serial Monitor in the Arduino IDE by going to "Tools" > "Serial Monitor."
2.  Set the baud rate to 9600 in the Serial Monitor.
3.  The sketch will configure the Ethernet connection with the static IP address. The static IP address will be printed to the Serial Monitor.

## Example Output

The output on the Serial Monitor should look similar to the following:

```
Configuring Ethernet with a static IP address...
Static IP address: 192.168.1.177` 
```

The specific IP address will depend on the static IP address you have set in the `ip` variable.

## Notes

This example serves as a starting point for learning how to configure a static IP address with the W5100S-EVB-Pico board in the Arduino IDE. You can expand on this example by implementing additional Ethernet functionality, such as creating web servers or clients, and working with TCP/UDP sockets.