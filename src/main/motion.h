#include <LSM6DS3.h>

enum Level { off, low, high };

// The measurement device
extern LSM6DS3 imu;

// Threshold of significant in G's
const float ACCELERATION_THRESHOLD_LOW = 1;
const float ACCELERATION_THRESHOLD_HIGH = 2.5;

void setupMotion(void);
float getAcceleration(void);
Level getMotionLevel(void);