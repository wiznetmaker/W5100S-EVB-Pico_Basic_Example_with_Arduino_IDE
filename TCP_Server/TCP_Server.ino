#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico
const int serverPort = 80; // The port number on which the server will listen for incoming connections

EthernetServer server(serverPort);

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
  Serial.print("Server started on port ");
  Serial.println(serverPort);
}

void loop() {
  // Listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    // Read the data from the client
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print("Received from client: ");
        Serial.println(c);

        // Send a response to the client
        client.println("Hello, Client!");
      }
    }
    // Close the connection:
    client.stop();
    Serial.println("Client disconnected");
  }
}
