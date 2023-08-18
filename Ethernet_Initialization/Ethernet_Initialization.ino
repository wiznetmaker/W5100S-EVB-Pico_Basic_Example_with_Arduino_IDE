// Include the required libraries for Ethernet communication:
#include <SPI.h>
#include <Ethernet.h>

// Define a unique MAC address for your device. This is a 6-byte identifier:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Define a static IP address for your device:
IPAddress ip(192, 168, 1, 177);

// Define the Chip Select (CS) pin for W5100S on W5100S-EVB-Pico:
const int csPin = 17;

void setup() {
  // Initialize serial communication at 9600 baud rate and wait for the port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only.
  }

  // Initialize Ethernet communication with the specified CS pin:
  Ethernet.init(csPin);

  // Start the Ethernet connection using DHCP:
  Serial.println("Starting Ethernet connection...");
  if (Ethernet.begin(mac) == 0) {
    // If DHCP configuration fails, print an error message:
    Serial.println("Failed to configure Ethernet using DHCP");

    // Try to configure Ethernet with the static IP address:
    Ethernet.begin(mac, ip);
  }
  // Wait for a second to allow the Ethernet shield to initialize properly:
  delay(1000);
  // Print a message to indicate that Ethernet initialization is complete:
  Serial.println("Ethernet initialized");

  // Print the network configuration obtained during Ethernet initialization:
  Serial.print("IP address: ");
  Serial.println(Ethernet.localIP()); // Print the device's IP address.
  Serial.print("Subnet mask: ");
  Serial.println(Ethernet.subnetMask()); // Print the device's subnet mask.
  Serial.print("Gateway IP: ");
  Serial.println(Ethernet.gatewayIP()); // Print the gateway IP address.
  Serial.print("DNS server IP: ");
  Serial.println(Ethernet.dnsServerIP()); // Print the DNS server IP address.
}

void loop() {
  // There is nothing to do in the loop for this example. 
  // The purpose of this sketch is to initialize the Ethernet connection and display network configuration.
}
