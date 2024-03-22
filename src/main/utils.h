#ifndef SPORTSHIELD_UTILS
#define SPORTSHIELD_UTILS

enum Level { off, low_level, high_level };

void setupLEDs(void);
void setLEDs(bool red, bool green, bool blue);
void clearLEDs(void);
char Conversion(unsigned short int data);
String convertDMMtoDD(String dmmCoordinates);

#endif