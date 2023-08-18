#include <SPI.h> // Include the SPI library (used for communication between the microcontroller and the W5100S chip)
#include <Ethernet.h> // Include the Ethernet library

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico

// Enter a static IP address for your controller below.
IPAddress ip(192, 168, 1, 177); // Example static IP address

void setup() {
  // Open the serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Initialize Ethernet with the CS pin:
  Ethernet.init(csPin);

  // Start the Ethernet connection using a static IP address:
  Serial.println("Configuring Ethernet with a static IP address...");
  Ethernet.begin(mac, ip);

  // Print the static IP address:
  Serial.print("Static IP address: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // Nothing to do here. This is just a Static IP Address example.
}
