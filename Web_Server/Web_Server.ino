#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico

EthernetServer server(80); // Create an instance of the server on port 80 (HTTP)

void setup() {
  // Open the serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Initialize Ethernet with the CS pin:
  Ethernet.init(csPin);

  // Start the Ethernet connection using DHCP:
  Serial.println("Attempting to obtain IP address using DHCP...");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to obtain IP address using DHCP");
  } else {
    // Print the obtained IP address:
    Serial.print("Successfully obtained IP address: ");
    Serial.println(Ethernet.localIP());
  }

  // Start the server:
  server.begin();
  Serial.println("Web server started. Listening for incoming connections...");
}

void loop() {
  // Listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("New client connected");

    // An HTTP request ends with a blank line
    bool currentLineIsBlank = true;

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        // If you've gotten to the end of the line (received a newline character) and the line is blank, the HTTP request has ended
        if (c == '\n' && currentLineIsBlank) {
          // Send a standard HTTP response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          // Send the HTML page
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<head><title>W5100S-EVB-Pico Web Server</title></head>");
          client.println("<body><h1>Hello from the W5100S-EVB-Pico Web Server!</h1></body>");
          client.println("</html>");

          break;
        }

        if (c == '\n') {
          // You're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // You've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }

    // Give the web browser time to receive the data
    delay(1);

    // Close the connection:
    client.stop();
    Serial.println("Client disconnected");
  }
}
