#ifndef SPORTSHIELD_BUZZER
#define SPORTSHIELD_BUZZER

const uint8_t BUZZER_PIN = D2;

void setupBuzzer(void);
void checkBuzzer(void);
bool playLowTone(void);
bool playHighTone(void);
void stopBuzzer(void);

#endif