#include "bluetooth.h"
#include "buzzer.h"
#include "gps.h"
#include "motion.h"
#include "utils.h"

void setup(void) {
  setupLEDs();
  setLEDs(true, false, false);

  // TEMP: Serial connection, remember to remove for production
  Serial.begin(9600);
  while (!Serial);
  
  Serial.println("Setup");
  setupMotion();
  setupBuzzer();
  setupBluetooth();
  setupPower();
  setupGPS();

  Serial.println("Setup done");
  setLEDs(false, true, false);
}

void loop(void) {
  Level motionLevel = getMotionLevel();

  // Buzzer
  if (motionLevel == low_level) {
    playLowTone();
  } else if (motionLevel == high_level) {
    playHighTone();
  } else {
    checkBuzzer();
  }

  if (!bluetoothReady && motionLevel != off) {
    setupBluetooth();
  }
  runBluetooth();

  updateGPS();
  if (getGPSStatus()) {
    Serial.print(getGPSLongitude());
    Serial.print(" ");
    Serial.println(getGPSLatitude());
  }

  delay(50);
}