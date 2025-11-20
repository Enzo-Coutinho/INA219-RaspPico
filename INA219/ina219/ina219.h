#ifndef INA219_h
#define INA219_H

void initializeINA219(const int sda, const int scl, const int freq);
int isConnectedINA219(void);

float getShuntVoltageINA219(void);
float getBusVoltageINA219(void);
float getCurrentINA219(void);
float getPowerINA219(void);


#endif