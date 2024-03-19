// https://github.com/Seeed-Studio/Seeed_Arduino_LSM6DS3/blob/master/examples/IMU_Capture/IMU_Capture.ino

#include <LSM6DS3.h>

// Using a time and keeping track of the old values to calculate velocity
float oldRotationX, oldRotationY, oldRotationZ;
unsigned long oldTime;

// The measurement device
LSM6DS3 imu = LSM6DS3(I2C_MODE, 0x6A); // I2C device, address 0x6A

void setupMotion(void) {
  if (imu.begin()) {
    // TEMP: Send message via serial
    Serial.println("ERROR: Motion sensor startup");
  }
}

float getAcceleration(void) {
  Serial.print(abs(imu.readFloatAccelX()));
  Serial.print(" ");
  Serial.print(abs(imu.readFloatAccelY()));
  Serial.print(" ");
  Serial.print(abs(imu.readFloatAccelZ()));
  Serial.print(" | ");

  // Uses the Manhattan norm
  // TODO: Adapt gravity on all 3 axes
  return abs(imu.readFloatAccelX()) +
         abs(imu.readFloatAccelY()) +
         abs(imu.readFloatAccelZ()) +
         -1; // Ignore gravity (value of 1G)
}

float getAngularVelocity(void) {
  unsigned long now = millis();
  unsigned long deltaTime = now - oldTime; // TODO: Ensure there is no overflow
  float gyroX = imu.readFloatGyroX();
  float gyroY = imu.readFloatGyroY();
  float gyroZ = imu.readFloatGyroZ();
  
  Serial.print(abs(gyroX));
  Serial.print(" ");
  Serial.print(abs(gyroY));
  Serial.print(" ");
  Serial.print(abs(gyroZ));
  Serial.print(" | ");

  // w = dphi / dt = (phi(t) - phi(t - dt)) / dt
  float value = abs(
    gyroX - oldRotationX +
    gyroY - oldRotationY +
    gyroZ - oldRotationZ
  ) / deltaTime;

  oldRotationX = gyroX;
  oldRotationY = gyroY;
  oldRotationZ = gyroZ;
  oldTime = now;

  return value;
}

Level getMotionLevel(void) {
  // Read the values
  float acceleration = getAcceleration();
  float angular_velocity = getAngularVelocity();
  Serial.print(acceleration);
  Serial.print(" ");
  Serial.print(angular_velocity);
  Serial.print(" ");
  // TODO: Get angular acceleration

  // Check if it's above the threshold
  if (
    acceleration < ACCELERATION_THRESHOLD_LOW &&
    angular_velocity < ANGULAR_VELOCITY_THRESHOLD_LOW
  ) {
    return off;
  }
  if (
    acceleration >= ACCELERATION_THRESHOLD_HIGH ||
    angular_velocity >= ANGULAR_VELOCITY_THRESHOLD_HIGH
  ) {
    return high;
  }
  return low;
}