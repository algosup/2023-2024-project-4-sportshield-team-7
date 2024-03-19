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
  Serial.print(abs(imu.readFloatAccelX()));
  Serial.print(" ");
  Serial.print(abs(imu.readFloatAccelY()));
  Serial.print(" ");
  Serial.print(abs(imu.readFloatAccelZ()));
  Serial.print(" > ");
  // TODO: Adapt gravity on all 3 axes
  return abs(imu.readFloatAccelX()) + \
         abs(imu.readFloatAccelY()) + \
         abs(imu.readFloatAccelZ()) + \
         -1; // Ignore gravity (value of 1G)
}

Level getMotionLevel(void) {
  // Read the values
  float acceleration = getAcceleration();
  Serial.print(acceleration);
  Serial.print(" ");
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