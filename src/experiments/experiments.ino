#include <SoftwareSerial.h>

#define SIM_TX_PIN D1
#define SIM_RX_PIN D0
#define SIM_DTR_PIN D5

SoftwareSerial g_simSerial(SIM_TX_PIN, SIM_RX_PIN);

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);

  Serial.begin(9600);
}

void loop() {
}
