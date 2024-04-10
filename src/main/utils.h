#ifndef SPORTSHIELD_UTILS
#define SPORTSHIELD_UTILS

const uint8_t PIN_ELECTROMAGNET = D3;
const unsigned long DURATION_ELECTROMAGNET = 1000;

enum Level { off, low_level, high_level };

void setupLEDs(void);
void setLEDs(bool red, bool green, bool blue);
void clearLEDs(void);
void setupPower(void);
void openElectromagnet(void);
unsigned int readBattery(void);
String convertDMMtoDD(String dmmCoordinates);

#endif