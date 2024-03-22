#include "buzzer.h"
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

  // playLowTone();
  // playHighTone();

  Serial.println("Setup done");
  setLEDs(false, true, false);
}

void loop(void) {
  checkBuzzer();
  delay(50);
}