void setupLEDs(void) {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  clearLEDs();
}

void setLEDs(bool red, bool green, bool blue) {
  // Built-in LEDs are active-low
  digitalWrite(LED_RED, red ? LOW : HIGH);
  digitalWrite(LED_GREEN, green ? LOW : HIGH);
  digitalWrite(LED_BLUE, blue ? LOW : HIGH);
}

void clearLEDs(void) {
  setLEDs(false, false, false);
}

void setupPower(void) {
  pinMode(PIN_ELECTROMAGNET, OUTPUT);

  // Power bridge
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

  // Battery
  pinMode(D9, OUTPUT);
  digitalWrite(D9, HIGH);

  // Battery charging mode
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void openElectromagnet(void) {
  // TODO: Non-blocking
  digitalWrite(PIN_ELECTROMAGNET, HIGH);
  delay(DURATION_ELECTROMAGNET);
  digitalWrite(PIN_ELECTROMAGNET, LOW);
}

unsigned int readBattery(void) {
  digitalWrite(VBAT_ENABLE, LOW);
  unsigned int vBat = analogRead(PIN_VBAT); //floor(100 * analogRead(PIN_VBAT) / 1023);
  digitalWrite(VBAT_ENABLE, HIGH);
  return vBat;
}

String convertDMMtoDD(String dmmCoordinates) {
  int degrees;
  float minutes;
  // Separate coordinates in degrees and decimal minutes
  if (dmmCoordinates.length() == 9) {
    degrees = dmmCoordinates.substring(0, 2).toInt();
    minutes = dmmCoordinates.substring(2).toFloat();
  } else {
    degrees = dmmCoordinates.substring(0, 1).toInt();
    minutes = dmmCoordinates.substring(1).toFloat();
  }
  // Convert decimal minutes to decimal degrees
  float decimalDegrees = degrees + (minutes / 60.0);

  // Convert to string and format coordinates to decimal degrees
  String ddCoordinates = String(decimalDegrees, 10);  // You can adjust the number of decimals here

  return ddCoordinates;
}