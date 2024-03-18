#define BUZZER_PIN D2

#define BPM 114

#define DOTTED_QUARTER 90 * 1000 / BPM
#define QUARTER 60 * 1000 / BPM
#define DOTTED_EIGHTH 45 * 1000 / BPM
#define EIGHTH 30 * 1000 / BPM
#define SIXTEENTH 15 * 1000 / BPM

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440



void playNote(unsigned long duration, unsigned int frequency) {
  unsigned long release = max(duration * 0.2, 100);
  unsigned long sustain = duration - release;
  tone(BUZZER_PIN, frequency);
  delay(sustain);
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
  delay(release);
}

void setup_music() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, HIGH);

  music();

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, LOW);
}

void loop_music() {
    // No loop
}

void music() {
  playNote(SIXTEENTH, NOTE_C4);
  playNote(SIXTEENTH, NOTE_D4);
  playNote(SIXTEENTH, NOTE_F4);
  playNote(SIXTEENTH, NOTE_D4);
  playNote(DOTTED_EIGHTH, NOTE_A4);
  playNote(DOTTED_EIGHTH, NOTE_A4);
  playNote(DOTTED_QUARTER, NOTE_G4);
  playNote(SIXTEENTH, NOTE_C4);
  playNote(SIXTEENTH, NOTE_D4);
  playNote(SIXTEENTH, NOTE_F4);
  playNote(SIXTEENTH, NOTE_F4);
  playNote(DOTTED_EIGHTH, NOTE_G4);
  playNote(DOTTED_EIGHTH, NOTE_G4);
  playNote(DOTTED_EIGHTH, NOTE_F4);
  playNote(SIXTEENTH, NOTE_E4);
  playNote(EIGHTH, NOTE_D4);
}