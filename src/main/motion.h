#ifndef SPORTSHIELD_
#define SPORTSHIELD_

#include <LSM6DS3.h>

enum Level { off, low, high };

// The measurement device
extern LSM6DS3 imu;

// Threshold of significance in G's
const float ACCELERATION_THRESHOLD_LOW = 1;
const float ACCELERATION_THRESHOLD_HIGH = 2.5;
const float ANGULAR_VELOCITY_THRESHOLD_LOW = 15;
const float ANGULAR_VELOCITY_THRESHOLD_HIGH = 30;

void setupMotion(void);
float getAcceleration(void);
float getAngularVelocity(void);
Level getMotionLevel(void);

#endif