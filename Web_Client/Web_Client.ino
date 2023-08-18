#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico

// Enter the IP address of the server you want to connect to
IPAddress serverIP(192, 168, 0, 2); 

// Initialize the Ethernet client library
EthernetClient client;

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

  // Connect to the server
  Serial.println("Connecting to the web server...");
  if (client.connect(serverIP, 80)) {
    Serial.println("Connected to the web server.");

    // Send the HTTP GET request
    client.println("GET /example_page.html HTTP/1.1");
    client.print("Host: ");
    client.println(serverIP);
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection to the web server failed.");
  }
}

void loop() {
  // If there are incoming bytes available from the server, read and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // If the server is disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnected from the server.");
    client.stop();

    // Do nothing forever after the client is disconnected:
    while (true);
  }
}
