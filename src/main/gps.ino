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
    if (!GPS.parse(GPS.lastNMEA()))
      return; // Failed to parse
  }

  // Serial.print("Fix: "); Serial.print(GPS.fix);
  // Serial.print(" quality: "); Serial.println(GPS.fixquality);
  // Serial.print("Location: ");
  // Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
  // Serial.print(", ");
  // Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
  // Serial.print("Speed (knots): "); Serial.println(GPS.speed);
}