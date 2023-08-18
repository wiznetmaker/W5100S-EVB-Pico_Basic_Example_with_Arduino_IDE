# W5100S-EVB-Pico Ethernet Communication Basics with Arduino IDE Part 1

This repository contains 10 simple example projects for practicing Ethernet communication using the W5100S-EVB-Pico with the Arduino IDE. These examples cover various aspects of Ethernet communication and can serve as a starting point for developing more complex projects.

## Purpose and Explanation

The purpose of this repository is to provide beginners with a comprehensive set of basic examples to learn and understand Ethernet communication using the W5100S-EVB-Pico in the Arduino IDE. Each example demonstrates a different aspect of Ethernet communication, from initializing the Ethernet connection to creating web servers and clients.

## Library Installation and Arduino IDE Setup

Before using the example projects, you'll need to install the necessary libraries and set up the Arduino IDE for the W5100S-EVB-Pico.

1. Install the Arduino IDE: Download and install the latest version of the Arduino IDE from the official Arduino website.
2. Add the Arduino core for RP2040: Open the Arduino IDE, go to "File" > "Preferences," and add the following URL to the "Additional Boards Manager URLs" field: [https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json](https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json) Click "OK" to save the changes.
3. Install the RP2040 board support: Go to "Tools" > "Board" > "Boards Manager," search for "RP2040" in the search bar, and install the "Raspberry Pi Pico/RP2040" package.
4. Select the board: Once the board support package is installed, go to "Tools" > "Board" and select "W5100S-EVB-Pico" from the list of available boards.
5. Install the WIZnet Ethernet library for W5100S-EVB-Pico: a. Download the library from the GitHub repository: [https://github.com/WIZnet-ArduinoEthernet/Ethernet](https://github.com/WIZnet-ArduinoEthernet/Ethernet). Click on the "Code" button and then "Download ZIP" to download the library as a ZIP file. b. Open the Arduino IDE. c. Go to "Sketch" > "Include Library" > "Add .ZIP Library." d. In the file dialog that appears, navigate to the location where you downloaded the WIZnet Ethernet library ZIP file in step 5a. e. Select the ZIP file and click "Open." The Arduino IDE will automatically install the library. f. Restart the Arduino IDE to ensure the library is loaded correctly.

## Examples

The following examples are included in this repository:

1.  **Ethernet Initialization**: Initialize the W5100S Ethernet controller, check its status, and print the network configuration.
2.  **DHCP IP Address**: Request an IP address from a DHCP server on your local network and print the assigned IP address.
3.  **Static IP Address**: Set a static IP address for the W5100S-EVB-Pico and print the network configuration.
4.  **TCP Client**: Create a simple TCP client that connects to a remote server, sends a message, and receives a response.
5.  **TCP Server**: Implement a basic TCP server that listens for incoming connections, receives messages, and sends a response.
6.  **UDP Sender**: Send UDP packets to a remote IP address and port.
7.  **UDP Receiver**: Listen for incoming UDP packets and print their content.
8.  **Web Client**: Connect to a web server, request a webpage, and print the HTTP response.
9.  **Web Server**: Create a simple web server that serves a basic HTML page when accessed from a web browser.
10. **DNS Resolution**: Resolve a domain name to its IP address using the Domain Name System (DNS) and print the result.
11. **NTP Client**: Synchronize the system time with a remote Network Time Protocol (NTP) server and print the current date and time.

Each example folder contains a sketch demonstrating a specific aspect of Ethernet communication. Consult the README file in each folder for a detailed explanation of the example and instructions on how to use it.

## Contributing

Contributions to this repository are welcome! Please feel free to submit pull requests for new examples or improvements to existing ones. If you encounter any issues or have questions, please open an issue on GitHub.

## License

These example projects are released under the MIT License.
By following the steps outlined in the Library Installation and Arduino IDE Setup section, you can set up your development environment to work with the W5100S-EVB-Pico board and start exploring the examples provided in this repository. Each example is designed to be easy to understand and modify, allowing you to create your own Ethernet-based projects. Happy coding!