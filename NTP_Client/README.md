# NTP Client Example for W5100S-EVB-Pico

This example demonstrates how to use the W5100S-EVB-Pico as an NTP (Network Time Protocol) client. The NTP client retrieves the current date and time from an NTP server and prints it to the serial monitor. The NTP client is essential when you need accurate timekeeping for your IoT or networked projects.

## Requirements

-   W5100S-EVB-Pico
-   Arduino IDE
-   A working internet connection to access an NTP server

## Setup

1.  Connect the W5100S-EVB-Pico to your computer.
2.  Open the Arduino IDE.
3.  Install the required libraries: Ethernet, SPI, and Time.
4.  Load the NTP Client example sketch.
5.  Choose the correct board (W5100S-EVB-Pico) and port in the `Tools` menu.
6.  Compile and upload the sketch to your W5100S-EVB-Pico board.

## Usage

1.  After uploading the sketch, open the Serial Monitor in the Arduino IDE (`Tools` > `Serial Monitor`).
2.  Set the baud rate to 9600 in the Serial Monitor.
3.  The NTP client will request the current date and time from the NTP server and print it to the Serial Monitor.
4.  The NTP client will update the date and time every 10 seconds.

## Example Output

```
Obtaining time from NTP server...
Current UTC time: 12:34:56
Current local time: 05:34:56
```

## Notes

-   Ensure that your W5100S-EVB-Pico is connected to the internet and can reach the NTP server. You may need to adjust the NTP server address in the sketch to match the address of a working NTP server.
-   The example code assumes a UTC-7 timezone for local time calculations. You may need to adjust the `timeZone` variable in the sketch to match your local timezone.
-   The Time library must be installed for this example to work correctly. Follow the instructions provided in a previous response to install the Time library.