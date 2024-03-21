#include "buzzer.h"

#include "utils.h"

Level buzzerLevel = off;
int startBuzzer;

void setupBuzzer(void) {
  pinMode(BUZZER_PIN, OUTPUT);
}

void checkBuzzer(void) {

}

bool playLowTone(void) {
  
}

bool playHighTone(void) {

}

void stopBuzzer(void) {
  buzzerLevel = off;
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
}