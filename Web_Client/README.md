# Web Client Example for W5100S-EVB-Pico

This example demonstrates how to use a W5100S-EVB-Pico board to create a simple web client that connects to a web server, sends an HTTP GET request for a specific webpage, and prints the server's response.

## Requirements

-   W5100S-EVB-Pico board
-   Arduino IDE
-   Ethernet library for W5100S-EVB-Pico ([https://github.com/WIZnet-ArduinoEthernet/Ethernet](https://github.com/WIZnet-ArduinoEthernet/Ethernet))
-   A web server running at the specified IP address with a valid webpage to request

## Setup

1.  Connect the W5100S-EVB-Pico board to your computer using a USB cable.
2.  Install the required libraries and configure the Arduino IDE as described in the main repository's README.
3.  Open the web client example code in the Arduino IDE.
4.  Modify the `serverIP` variable in the code to match the IP address of your web server.
5.  Modify the requested webpage in the `client.println("GET /example_page.html HTTP/1.1");` line to match the name of the webpage you want to request from the server.

## Usage

1.  Upload the sketch to the W5100S-EVB-Pico board.
2.  Open the Arduino IDE's Serial Monitor.
3.  Observe the output as the web client connects to the server, sends the HTTP GET request, and prints the server's response.

## Example Output

```
Attempting to obtain IP address using DHCP...
Successfully obtained IP address: 192.168.1.110
Connecting to the web server...
Connected to the web server.
HTTP/1.1 200 OK
Date: Mon, 01 Jan 2023 00:00:00 GMT
Server: MyWebServer/1.0
Content-Type: text/html
Content-Length: 100

<html>
<head><title>Example Page</title></head>
<body><h1>Hello, Web Client!</h1></body>
</html>
Disconnected from the server.
```

## Notes

-   Make sure your web server is running and accessible from the W5100S-EVB-Pico board's network.
-   The example assumes the web server is using port 80. Modify the port number in the `client.connect(serverIP, 80)` line if your web server uses a different port.
-   The example assumes the requested webpage is named "example_page.html". Change the name in the `client.println("GET /example_page.html HTTP/1.1");` line if you want to request a different webpage.