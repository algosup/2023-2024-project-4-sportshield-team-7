#include "buzzer.h"

#include "utils.h"

const unsigned int LOW_LEVEL_FREQUENCIES[] = {440, 0, 440, 0, 0}; // 0 is no sound
const unsigned int LOW_LEVEL_REPEAT = 2; // How many times to repeat the sequence
const unsigned long LOW_LEVEL_DURATION = 250; // The duration of each note in mn

const unsigned int HIGH_LEVEL_REPEAT = 5; // How many times to repeat the sequence
const unsigned long HIGH_LEVEL_DURATION = 500; // Half a bip in ms (bips twice as long as silences)

Level buzzerLevel = off;
int startBuzzer;

void setupBuzzer(void) {
  pinMode(BUZZER_PIN, OUTPUT);
}

void checkBuzzer(void) {
  int deltaTime = millis() - startBuzzer;
  int index, length;
  unsigned int frequency;

  switch (buzzerLevel) {
    case off:
      break;

    case low_level:
      index = deltaTime / LOW_LEVEL_DURATION;
      length = sizeof(LOW_LEVEL_FREQUENCIES) / sizeof(unsigned int);
      if (index >= length * LOW_LEVEL_REPEAT) {
        stopBuzzer();
        break;
      }
      Serial.println("LOW"); // TEMP
      frequency = LOW_LEVEL_FREQUENCIES[index % length];
      if (frequency) {
        tone(BUZZER_PIN, frequency);
      } else {
        noTone(BUZZER_PIN);
        digitalWrite(BUZZER_PIN, LOW);
      }
      break;

    case high_level:
      index = deltaTime / HIGH_LEVEL_DURATION;
      if (index >= 3 * HIGH_LEVEL_REPEAT) {
        stopBuzzer();
        break;
      }
      Serial.println("HIGH"); // TEMP
      digitalWrite(BUZZER_PIN, index % 3 == 2 ? LOW : HIGH);
      break;
  }
}

bool playLowTone(void) {
  if (buzzerLevel != off) {
    return false;
  }
  stopBuzzer();
  buzzerLevel = low_level;
  startBuzzer = millis();
  checkBuzzer();
  return true;
}

bool playHighTone(void) {
  if (buzzerLevel == high_level) {
    return false;
  }
  stopBuzzer();
  buzzerLevel = high_level;
  startBuzzer = millis();
  checkBuzzer();
  return true;
}

void stopBuzzer(void) {
  buzzerLevel = off;
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
}