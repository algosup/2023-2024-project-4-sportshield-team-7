#include "bluetooth.h"

#include <ArduinoBLE.h>
#include "sim.h"

const int EXPECTED_PASSWORD = 13330;

BLEDevice central;

BLEService PasswordService(PASSWORD_SERVICE_UUID);
BLEService ConfigService(CONFIG_SERVICE_UUID);

BLEShortCharacteristic PasswordCharacteristic(PASSWORD_CHARACTERISTIC_UUID, BLEWrite);
BLEStringCharacteristic NameCharacteristic(NAME_CHARACTERISTIC_UUID, BLERead | BLEWrite, 20);
BLEStringCharacteristic MACCharacteristic(MAC_CHARACTERISTIC_UUID, BLERead, 20);
BLEBooleanCharacteristic ActivationCharacteristic(ACTIVATION_CHARACTERISTIC_UUID, BLERead | BLEWrite);
BLEBooleanCharacteristic UnlockCharacteristic(UNLOCK_CHARACTERISTIC_UUID, BLEWrite);

void setupBluetooth(void) {
  if (!BLE.begin()) {
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  // Device
  BLE.setLocalName(DEVICE_NAME);
  BLE.setDeviceName(DEVICE_NAME);
  BLE.setAdvertisedService(PasswordService);

  // Descriptors
  PasswordCharacteristic.addDescriptor(PasswordDescriptor);
  NameCharacteristic.addDescriptor(NameDescriptor);
  ActivationCharacteristic.addDescriptor(ActivationDescriptor);
  UnlockCharacteristic.addDescriptor(UnlockDescriptor);
  MACCharacteristic.addDescriptor(MACDescriptor);
  
  // Characteristics
  PasswordService.addCharacteristic(PasswordCharacteristic);
  ConfigService.addCharacteristic(NameCharacteristic);
  ConfigService.addCharacteristic(ActivationCharacteristic);
  ConfigService.addCharacteristic(UnlockCharacteristic);
  ConfigService.addCharacteristic(MACCharacteristic);

  // Service
  BLE.addService(PasswordService);
  BLE.addService(ConfigService);

  // Initial values
  PasswordCharacteristic.writeValue(0);
  NameCharacteristic.writeValue("\n");
  ActivationCharacteristic.writeValue(false);
  UnlockCharacteristic.writeValue(false);
  MACCharacteristic.writeValue(BLE.address());

  // Event handler
  PasswordCharacteristic.setEventHandler(BLEWritten, onSetPassword);
  NameCharacteristic.setEventHandler(BLEWritten, onSetName);
  NameCharacteristic.setEventHandler(BLERead, onGetName);
  ActivationCharacteristic.setEventHandler(BLEWritten, onSetActivation);
  ActivationCharacteristic.setEventHandler(BLERead, onGetActivation);
  UnlockCharacteristic.setEventHandler(BLEWritten, onSetUnlock);

  // Start advertising
  BLE.advertise();
}

void runBluetooth(void) {
  if (central) {
    central.poll();
  } else {
    central = BLE.central();
  }
}

void onConnect(BLEDevice central) {}

void onDisconnect(BLEDevice central) {
  isAuthenticated = false;
}

void onSetPassword(BLEDevice central, BLECharacteristic characteristic) {
  isAuthenticated = isAuthenticated || PasswordCharacteristic.value() == EXPECTED_PASSWORD;
}

void onSetName(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    username = NameCharacteristic.value();
  }
}

void onGetName(BLEDevice central, BLECharacteristic characteristic) {
  NameCharacteristic.writeValue(isAuthenticated ? username : DEFAULT_NAME);
}

void onSetActivation(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    if (isActivated) {
      enableSIM();
    } else {
      disableSIM();
    }
  }
}

void onGetActivation(BLEDevice central, BLECharacteristic characteristic) {
  ActivationCharacteristic.writeValue(isActivated);
}

void onSetUnlock(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    // Activate electromagnet
    openElectromagnet();
  }
}