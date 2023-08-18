#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <TimeLib.h>
#include <Dns.h>

// Enter a MAC address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

const int csPin = 17; // Chip Select (CS) pin for W5100S on W5100S-EVB-Pico

unsigned int localPort = 8888; // Local port to listen for UDP packets

const char timeServer[] = "pool.ntp.org"; // NTP server
IPAddress timeServerIP; // IPAddress of the NTP server

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of the message
byte packetBuffer[NTP_PACKET_SIZE]; // Buffer to hold incoming and outgoing packets

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

  // Start the UDP instance
  Udp.begin(localPort);

  // Resolve the time server's IP address
  DNSClient dns;
  dns.begin(Ethernet.dnsServerIP());
  dns.getHostByName(timeServer, timeServerIP);

  Serial.print("Time server IP address: ");
  Serial.println(timeServerIP);
}

void loop() {
  sendNTPpacket(timeServerIP); // Send an NTP request
  delay(1000); // Wait a second for a response

  if (Udp.parsePacket()) {
    Udp.read(packetBuffer, NTP_PACKET_SIZE); // Read the packet into the buffer

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord; // Combine the high and low words

    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears; // Convert to UNIX timestamp

    // Print the UNIX timestamp
    Serial.print("UNIX timestamp: ");
    Serial.println(epoch);

    // Convert and print the time in a human-readable format
    setTime(epoch);
    Serial.print("The time is: ");
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(" ");
    Serial.print(day());
    Serial.print(" ");
    Serial.print(month());
    Serial.print(" ");
    Serial.print(year());
    Serial.println();

    delay(10000); // Wait for 10 seconds before sending the next request
  }
}

void sendNTPpacket(IPAddress& address) {
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011; // LI, Version, Mode
  packetBuffer[1] = 0; // Stratum, or type of clock
  packetBuffer[2] = 6; // Polling Interval
  packetBuffer[3] = 0xEC; // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;

  // Send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); // NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

void printDigits(int digits) {
  // Utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(':');
  if (digits < 10) {
    Serial.print('0');
  }
  Serial.print(digits);
}

 
