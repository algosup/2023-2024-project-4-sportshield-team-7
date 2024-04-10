// Adapted from
// https://github.com/ostaquet/Arduino-SIM800L-driver/blob/master/examples/HTTPS_POST_SoftSerial/HTTPS_POST_SoftSerial.ino

#include "sim.h"

#include "gps.h"
#include "SIM800L.h"
#include <SoftwareSerial.h>
#include "utils.h"



const char APN[] = "iot.1nce.net";
const char BASE_URL[] = "http://141.94.244.11:2000/";
const char CONTENT_TYPE[] = "application/json";

#define SIM800_DTR_PIN A5
#define SIM800_RST_PIN A5
SIM800L* sim800l = NULL;

void enableSIM(void) {
  digitalWrite(SIM800_DTR_PIN, LOW); // normal mode
  delay(100);
  sim800l->setPowerMode(NORMAL);
}

void disableSIM(void) {
  sim800l->setPowerMode(MINIMUM);
  digitalWrite(SIM800_DTR_PIN, HIGH); // sleep mode
}

void simSetup(void) {
  // Instantiation
  if (sim800l == NULL) {
    SoftwareSerial* serial = new SoftwareSerial(D0, D1);
    delay(1000);
    sim800l = new SIM800L((Stream *)serial, SIM800_RST_PIN, 200, 512);
  }

  // Wait until the module is ready to accept AT commands
  while (!sim800l->isReady()) {
    Serial.println(F("Problem to initialize AT command, retry in 1 sec"));
    // digitalWrite(LEDR, !digitalRead(LEDR));
    delay(1000);
  }

  // Wait for the GSM signal
  uint8_t signal = sim800l->getSignal();
  while (signal <= 0) {
    delay(1000);
    signal = sim800l->getSignal();
  }

  // Wait for operator network registration (national or roaming network)
  NetworkRegistration network = sim800l->getRegistrationStatus();
  while (network != REGISTERED_HOME && network != REGISTERED_ROAMING) {
    Serial.println(F("Problem to register, retry in 1 sec"));
    // digitalWrite(LEDG, !digitalRead(LEDG));
    delay(1000);
    network = sim800l->getRegistrationStatus();
  }

  // Setup APN for GPRS configuration
  bool success = sim800l->setupGPRS(APN);
  while(!success) {
    Serial.println(F("Problem to configure GPRS, retry in 1 sec"));
    // digitalWrite(LEDG, !digitalRead(LEDG));
    success = sim800l->setupGPRS(APN);
    delay(5000);
  }
  Serial.println(F("GPRS config OK"));

  delay(50);
  sim800l->setPowerMode(MINIMUM);      // set minimum functionnality mode
  digitalWrite(SIM800_DTR_PIN, HIGH);  // put in sleep mode
}

void simLoop(Level level) {
  // Establish GPRS connectivity (5 trials)
  bool connected = false;
  for(uint8_t i = 0; i < 5 && !connected; i++) {
    delay(1000);
    connected = sim800l->connectGPRS();
  }

  // Check if connected, if not reset the module and setup the config again
  if(connected) {
    Serial.print(F("GPRS connected with IP "));
    Serial.println(sim800l->getIP());
  } else {
    Serial.println(F("GPRS not connected !"));
    Serial.println(F("Reset the module."));
    sim800l->reset();
    simSetup(); // TODO: Non-blocking
    return;
  }

  // TODO: Add BLE address to url

  // Format the payload
  char payload[200];
  float lat = getGPSLatitude();
  float lon = getGPSLongitude();
  float bat = readBattery();
  sprintf(payload, "{\"lat\":%f,\"long\":%f,\"bat\":%f,\"level\":%d}", lat, lon, bat, level);

  // Send and disconnect
  sim800l->doPost(BASE_URL, "application/json", payload, 10000, 10000);
  sim800l->disconnectGPRS();
}