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

char passwordConversion(unsigned short int data) {
  char passwordHex[5];
  sprintf(passwordHex, "%04X", data);

  for (int i = 0; i < 2; ++i) {
    char temp = passwordHex[i];
    passwordHex[i] = passwordHex[2 + i];
    passwordHex[2 + i] = temp;
  }
  Serial.println(passwordHex);
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