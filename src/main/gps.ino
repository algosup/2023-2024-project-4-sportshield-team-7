// https://github.com/adafruit/Adafruit_GPS/blob/master/examples/GPS_HardwareSerial_Parsing/GPS_HardwareSerial_Parsing.ino
#include "gps.h"

#include <Adafruit_GPS.h>

Adafruit_GPS GPS(&Serial1);

void setupGPS() {
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY); // Minimal data, probably saves energy
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ); // Update every 10s (slowest possible)
  delay(1000);
}

void updateGPS() {
  GPS.read();
  if (GPS.newNMEAreceived()) {
    // Attempt to parse the received line to update the values
    GPS.parse(GPS.lastNMEA());
  }
}

bool getGPSStatus() {
  return GPS.fix;
}

float getGPSLongitude() {
  return GPS.longitudeDegrees;
}

float getGPSLatitude() {
  return GPS.latitudeDegrees;
}