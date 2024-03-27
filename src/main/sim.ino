#include "sim.h"

void enableSIM(void) {
    // TODO
}

void disableSIM(void) {
    // TODO
}



#define TIMER_INTERRUPT_DEBUG 0
#define _TIMERINTERRUPT_LOGLEVEL_ 0
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"
#include <Arduino.h>

//SIM
#include "SIM800L.h"

// SIM800L GSM 2G Module
UART Serial2(D0, D1, NC, NC);
#define SIM800_RST_PIN A5
#define SIM800_DTR_PIN A5
SIM800L* sim800l;
bool send_position = false;
bool send_move = false;

void loop() {
  if (send_move) {  //sending of positions via SIM module
    Serial.println("Envoi detection mouvement");
    sim800l->setupGPRS("iot.1nce.net");
    sim800l->connectGPRS();
    String Route = "http://141.94.244.11:2000/sendNotfication/" + BLE.address();
    String RouteCoord = "http://141.94.244.11:2000/updateCoordinate/" + BLE.address();
    String str = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\"}";
    String bat = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\", \"batterie\":\"" + String(getBatteryVoltage()) + "\"}";
    char position[200];
    char posbat[200];
    str.toCharArray(position, str.length() + 1);
    //Serial.println(str);
    bat.toCharArray(posbat, bat.length() + 1);
    Serial.println(posbat);
    char direction[200];
    char directionCoord[200];
    Route.toCharArray(direction, Route.length() + 1);
    RouteCoord.toCharArray(directionCoord, RouteCoord.length() + 1);
    sim800l->doPost(direction, "application/json", position, 10000, 10000);
    sim800l->doPost(directionCoord, "application/json", posbat, 10000, 10000);
    sim800l->disconnectGPRS();
    send_move = false;
  }

  if (send_position) {  //regular sending of positions via SIM module
    Serial.println("Envoi regulier position");
    sim800l->setupGPRS("iot.1nce.net");
    sim800l->connectGPRS();
    String RouteCoord = "http://141.94.244.11:2000/updateCoordinate/" + BLE.address();
    String bat = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\", \"batterie\":\"" + String(getBatteryVoltage()) + "\"}";
    char posbat[200];
    bat.toCharArray(posbat, bat.length() + 1);
    Serial.println(posbat);
    Serial.println(RouteCoord);
    char directionCoord[200];
    RouteCoord.toCharArray(directionCoord, RouteCoord.length() + 1);
    sim800l->doPost(directionCoord, "application/json", posbat, 10000, 10000);
    sim800l->disconnectGPRS();
    send_position = false;
  }
}

void sim_setup(void) {
  while (!sim800l->isReady()) {
    Serial.println(F("Problem to initialize AT command, retry in 1 sec"));
    digitalWrite(LEDR, !digitalRead(LEDR));
    delay(1000);
  }
  sim800l->enableEchoMode();
  sim800l->setupGPRS("iot.1nce.net");

  uint8_t signal = sim800l->getSignal();
  while (signal <= 0) {
    delay(1000);
    signal = sim800l->getSignal();
  }
  Serial.println(String(signal));
  NetworkRegistration network = sim800l->getRegistrationStatus();
  while (network != REGISTERED_HOME && network != REGISTERED_ROAMING) {
    delay(1000);
    network = sim800l->getRegistrationStatus();
    Serial.print(network + " ");
    Serial.println(F("Problem to register, retry in 1 sec"));
    digitalWrite(LEDG, !digitalRead(LEDG));
  }
  delay(50);
  sim800l->setPowerMode(MINIMUM);      // set minimum functionnality mode
  digitalWrite(SIM800_DTR_PIN, HIGH);  // put in sleep mode
}