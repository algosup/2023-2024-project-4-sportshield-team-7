#ifndef SPORTSHIELD_SIM
#define SPORTSHIELD_SIM

#include "utils.h"

const char APN[] = "iot.1nce.net";
const char BASE_URL[] = "http://141.94.244.11:2000/";
const char CONTENT_TYPE[] = "application/json";

const uint8_t SIM800_DTR_PIN = A5;
const uint8_t SIM800_RST_PIN = A5;

void enableSIM(void);
void disableSIM(void);
void simSetup(void);
void simLoop(Level level);

#endif