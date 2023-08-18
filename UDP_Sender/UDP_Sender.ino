#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico
const int localPort = 8888; // Local port to listen on
const int remotePort = 9999; // Remote port to send to

char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; // Buffer to hold incoming packets

IPAddress remoteIP(192, 168, 0, 2); // Remote IP address to send UDP packets to

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
  // Send a UDP packet to the remote IP and port
  Udp.beginPacket(remoteIP, remotePort);
  Udp.write("Hello, UDP Receiver!");
  Udp.endPacket();

  // Wait for a while before sending the next packet
  delay(2000);
}
