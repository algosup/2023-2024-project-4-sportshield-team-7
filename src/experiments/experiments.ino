#define BUZZER_PIN D2

void setup() {
  // Buzz to inform that the program has started
  pinMode(BUZZER_PIN, OUTPUT);
  delay(10);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
  delay(5000);
}

void loop() {
  // Hard-stop, really sounds like a burst
  for (size_t i = 0; i < 16; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(25);
    digitalWrite(BUZZER_PIN, LOW);
    delay(75);
  }
  delay(1000);

  // More smoothed-out
  for (size_t i = 0; i < 16; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(75);
    digitalWrite(BUZZER_PIN, LOW);
    delay(25);
  }
  delay(1000);
}