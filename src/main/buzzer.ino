#include "buzzer.h"

#include "utils.h"

const unsigned int LOW_LEVEL_FREQUENCIES[] = { 440, 0, 440, 0, 0 };
const unsigned int LOW_LEVEL_REPEAT = 2;
const unsigned long LOW_LEVEL_DURATION = 250;

Level buzzerLevel = off;
int startBuzzer;

void setupBuzzer(void) {
  pinMode(BUZZER_PIN, OUTPUT);
}

void checkBuzzer(void) {
  // TODO: Complete
  int deltaTime = millis() - startBuzzer;

  switch (buzzerLevel) {
    case off:
      break;

    case low_level:
      break;

    case high_level:
      break;
  }
}

bool playLowTone(void) {
  for (int i = 0; i < LOW_LEVEL_REPEAT; i++) {
    for (unsigned int frequency : LOW_LEVEL_FREQUENCIES) {
      if (frequency) {
        tone(BUZZER_PIN, frequency);
      } else {
        noTone(BUZZER_PIN);
        digitalWrite(BUZZER_PIN, LOW);
      }
      delay(LOW_LEVEL_DURATION);
    }
  }
}

bool playHighTone(void) {
  
}

void stopBuzzer(void) {
  buzzerLevel = off;
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
}