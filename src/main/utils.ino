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