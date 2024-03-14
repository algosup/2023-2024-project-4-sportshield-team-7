#define BUZZER_PIN D2
#define ELECTROMAGNET_PIN D3

int i = 0;

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);

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
  const int limit = 1 << 8;
  for (int i = 0; i < limit; i++) {
    digitalWrite(LED_RED, i & 1 ? HIGH : LOW);
    digitalWrite(LED_BLUE, i & 2 ? HIGH : LOW);
    digitalWrite(LED_GREEN, i & 4 ? HIGH : LOW);
    digitalWrite(BUZZER_PIN, i & 1 ? HIGH : LOW);
    delay(100);
  }
}