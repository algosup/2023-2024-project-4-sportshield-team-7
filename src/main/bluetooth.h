#ifndef SPORTSHIELD_BLUETOOTH
#define SPORTSHIELD_BLUETOOTH

#include <ArduinoBLE.h>

const char* DEVICE_NAME = "SportShield Team 7";

void setupBluetooth(void);
void runBluetooth(void);
void onConnect(BLEDevice central);
void onWritePassword(BLEDevice central, BLECharacteristic characteristic);
void onWriteName(BLEDevice central, BLECharacteristic characteristic);
void onReadName(BLEDevice central, BLECharacteristic characteristic);
void onWriteActivation(BLEDevice central, BLECharacteristic characteristic);
void onReadActivation(BLEDevice central, BLECharacteristic characteristic);
void onWriteUnlock(BLEDevice central, BLECharacteristic characteristic);

#endif