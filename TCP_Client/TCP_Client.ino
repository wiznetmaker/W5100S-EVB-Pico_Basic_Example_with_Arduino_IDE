#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress serverIP(192, 168, 0, 2); // IP address of the remote server
const int serverPort = 80; // The port number for the remote server

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico

EthernetClient client;
bool messageSent = false;

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

  // Connect to the remote server:
  Serial.println("Connecting to remote server...");
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Connected to the server");
  } else {
    Serial.println("Failed to connect to the server");
  }
}

void loop() {
  // If the client is connected, send a message to the server once
  if (client.connected()) {
    if (!messageSent) {
      client.println("Hello, Server!");
      messageSent = true;
      Serial.println("Message sent to server.");
    }

    // Wait for a response from the server
    if (client.available()) {
      char c = client.read();
      Serial.print("Received from server: ");
      Serial.println(c);
    }
  } else {
    Serial.println("Client disconnected.");
    client.stop();
    delay(5000); // Wait for 5 seconds before attempting to reconnect
    client.connect(serverIP, serverPort); // Attempt to reconnect
    messageSent = false; // Reset messageSent flag
  }
}
