#ifndef INA219_h
#define INA219_H

#define _400kHz (400e3)
#define _100kHz (100e3)

void initializeINA219(const int sda, const int scl, const int freq, const int address_i2c);
int isConnectedINA219(void);

void resetINA219(void);
void setResolutionINA219(void);

void calibrateINA219(const float maxCurrent, const float resistance_shunt);

float getShuntVoltageINA219(void);
float getBusVoltageINA219(void);
float getCurrentINA219(void);
float getPowerINA219(void);


#endif