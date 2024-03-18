// Refences:
// https://forum.seeedstudio.com/t/studio-xiao-nrf52840-sense-battery-pins-number/272533/4

// #include <Arduino.h>
#include <ArduinoBLE.h>
// #include <AnalogIn.h>
// #include <pinDefinitions.h>

#define BLE_NAME "Test Team 7"

// const float V_MAX = 3.7f;

BLEService BatteryService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLEUnsignedIntCharacteristic BatteryCharacteristics("2A19", BLERead);
// BLEDescriptor BatteryDescriptor("2901", "Battery");

void setup() {
  // Set LEDs to red
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);

  // Activate power bridge
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  pinMode(D9, OUTPUT);
  digitalWrite(D9, HIGH);
  pinMode(D9, OUTPUT);

  // Setting up BLE
  while (!BLE.begin()) {}
  BLE.setLocalName(BLE_NAME);
  BLE.setDeviceName(BLE_NAME);
  BLE.setAdvertisedService(BatteryService);
  // BatteryCharacteristics.addDescriptor(BatteryDescriptor);
  BatteryService.addCharacteristic(BatteryCharacteristics);
  BLE.addService(BatteryService);
  BatteryCharacteristics.writeValue(0);
  // BatteryLevelCharacteristics.setEventHandler(BLERead, onBatteryRead);
  BLE.advertise();
  
  // Set LEDs to green
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);
}

void loop() {
  // Use up the battery by playing sound
  music();

  // Read the battery level
  digitalWrite(PIN_VBAT_ENABLE, LOW);
  unsigned int vBat = analogRead(PIN_VBAT); //floor(100 * analogRead(PIN_VBAT) / 1023);
  digitalWrite(PIN_VBAT_ENABLE, HIGH);

  // Scan for Bluetooth connection and loop to send the battery level
  BLEDevice central = BLE.central();
  if (central) {
    // Set LEDs to blue
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);

    // Set value and wait for disconnection
    BatteryCharacteristics.writeValue(vBat);
    while (central.connected()) {}

    // Set LEDs back to green
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
  }

  // Wait 1 second before next loop
  delay(1000);
}