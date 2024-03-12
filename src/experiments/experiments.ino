#define BUZZER_PIN D2
#define ELECTROMAGNET_PIN D3

void setup() {
  Serial.begin(115200);
  // Buzz to inform that the program has started
  pinMode(BUZZER_PIN, OUTPUT);
  delay(10);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
  delay(2000);

  // Test the electromagnet
  pinMode(ELECTROMAGNET_PIN, OUTPUT);
  delay(10);
  digitalWrite(ELECTROMAGNET_PIN, HIGH);
  delay(1000);
  digitalWrite(ELECTROMAGNET_PIN, LOW);
  // With no surprise, the electromagnet did not activate
  // This is because the board is not powerful enough to power
  // the electromagnet directly (<2mA vs 500mA).
  // We must contact the client to confirm the need of a relay.
}

void loop_buzzer() {
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

void loop() {

}