#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico
const int localPort = 9999; // Local port to listen on

char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; // Buffer to hold incoming packets

EthernetUDP Udp;

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

  // Initialize the UDP instance and start listening on the local port
  Udp.begin(localPort);
}

void loop() {
  // Check if there are any incoming UDP packets
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIP = Udp.remoteIP();
    Serial.print(remoteIP);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // Read the packet into the buffer
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);

    // Print the received message
    Serial.print("Contents: ");
    Serial.println(packetBuffer);

    // Clear the packet buffer
    memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
  }
}
