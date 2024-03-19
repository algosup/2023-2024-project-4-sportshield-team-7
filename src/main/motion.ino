// https://github.com/Seeed-Studio/Seeed_Arduino_LSM6DS3/blob/master/examples/IMU_Capture/IMU_Capture.ino

#include <LSM6DS3.h>

// The measurement device
LSM6DS3 imu = LSM6DS3(I2C_MODE, 0x6A); // I2C device, address 0x6A

void setupMotion(void) {
  if (imu.begin()) {
    // TEMP: Send message via serial
    Serial.println("ERROR: Motion sensor startup");
  }
}

float getAcceleration(void) {
  // Uses the Manhattan norm
  return abs(imu.readFloatAccelX()) + \
         abs(imu.readFloatAccelY()) + \
         abs(imu.readFloatAccelZ());
}

Level getMotionLevel(void) {
  // Read the values
  float acceleration = getAcceleration();
  // TODO: Get angular acceleration

  // Check if it's above the threshold
  if (acceleration < ACCELERATION_THRESHOLD_LOW) {
    return off;
  }
  if (acceleration >= ACCELERATION_THRESHOLD_HIGH) {
    return high;
  }
  return low;
}