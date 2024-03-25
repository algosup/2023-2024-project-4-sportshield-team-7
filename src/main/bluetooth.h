#ifndef SPORTSHIELD_BLUETOOTH
#define SPORTSHIELD_BLUETOOTH

#include <ArduinoBLE.h>

String username = "\n";
bool isActivated = false;
bool isAuthenticated = false;

const char* DEFAULT_NAME = "\n";

const uint8_t PIN_ELECTROMAGNET = D3;
const unsigned long DURATION_ELECTROMAGNET = 1000;

const char* DEVICE_NAME = "SportShield Team 7";

const char* PASSWORD_SERVICE_UUID = "19B10000-E8F2-537E-4F6C-D104768A1213";
const char* CONFIG_SERVICE_UUID = "19B10000-E8F2-537E-4F6C-D104768A1214";

const char* PASSWORD_CHARACTERISTIC_UUID = "19B10000-E8F2-537E-4F6C-D104768A1213";
const char* NAME_CHARACTERISTIC_UUID = "19B10001-E8F2-537E-4F6C-D104768A1214";
const char* ACTIVATION_CHARACTERISTIC_UUID = "19B10001-E8F2-537E-4F6C-D104768A1215";
const char* UNLOCK_CHARACTERISTIC_UUID = "19B10001-E8F2-537E-4F6C-D104768A1216";
const char* MAC_CHARACTERISTIC_UUID = "19B10001-E8F2-537E-4F6C-D104768A1217";

BLEDescriptor PasswordDescriptor("2901", "Password");
BLEDescriptor NameDescriptor("2901", "Name");
BLEDescriptor ActivationDescriptor("2901", "Activation");
BLEDescriptor UnlockDescriptor("2901", "Unlock");
BLEDescriptor MACDescriptor("2901", "MAC Address");

void setupBluetooth(void);
void runBluetooth(void);
void onConnect(BLEDevice central);
void onSetPassword(BLEDevice central, BLECharacteristic characteristic);
void onSetName(BLEDevice central, BLECharacteristic characteristic);
void onGetName(BLEDevice central, BLECharacteristic characteristic);
void onSetActivation(BLEDevice central, BLECharacteristic characteristic);
void onGetActivation(BLEDevice central, BLECharacteristic characteristic);
void onSetUnlock(BLEDevice central, BLECharacteristic characteristic);

#endif