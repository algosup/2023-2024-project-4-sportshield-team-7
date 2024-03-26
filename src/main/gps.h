#ifndef SPORTSHIELD_GPS
#define SPORTSHIELD_GPS

void setupGPS(void);
void updateGPS(void);
bool getGPSStatus(void);
float getGPSLongitude(void);
float getGPSLatitude(void);

#endif