#include <SoftwareSerial.h>

#define SIM_TX_PIN D1
#define SIM_RX_PIN D0
#define BUZZER_PIN D2
#define ELECTROMAGNET_PIN D3
#define BRIDGE_PIN D4
#define SIM_DTR_PIN D5

int i = 0;

SoftwareSerial simSerial(SIM_TX_PIN, SIM_RX_PIN);

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);

  Serial.begin(9600);
  simSerial.begin(9600);
  delay(100);
  while (!Serial) {}
  while (!simSerial) {}
  Serial.println("Started");
  pinMode(SIM_DTR_PIN, OUTPUT);
  digitalWrite(SIM_DTR_PIN, LOW);

  // Buzz to inform that the program has started
  pinMode(BUZZER_PIN, OUTPUT);
  delay(10);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);

  // Test the electromagnet
  pinMode(ELECTROMAGNET_PIN, OUTPUT);
  pinMode(BRIDGE_PIN, OUTPUT);
  delay(10);
  digitalWrite(ELECTROMAGNET_PIN, HIGH);
  digitalWrite(BRIDGE_PIN, HIGH);
  delay(1000);
  digitalWrite(BRIDGE_PIN, LOW);
  digitalWrite(ELECTROMAGNET_PIN, LOW);
  // With no surprise, the electromagnet did not activate
  // This is because the board is not powerful enough to power
  // the electromagnet directly (<2mA vs 500mA).
  // We must contact the client to confirm the need of a relay.
  
  Serial.println("Before messages");
  simSerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  simSerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  simSerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  simSerial.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
  Serial.println("End setup");
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
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    simSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(simSerial.available()) 
  {
    Serial.write(simSerial.read());//Forward what Software Serial received to Serial Port
  }
}