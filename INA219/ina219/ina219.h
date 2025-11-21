#ifndef INA219_h
#define INA219_H

#include "i2c/i2c_driver.h"

#define INA219_ADDRESS_GND_GND  0b1000000
#define INA219_ADDRESS_GND_VS   0b1000001
#define INA219_ADDRESS_GND_SDA  0b1000010
#define INA19__ADDRESS_GND_SCL  0b1000011
#define INA219_ADDRESS_VS_GND   0b1000100
#define INA219_ADDRESS_VS_VS    0b1000101
#define INA219_ADDRESS_VS_SDA   0b1000110
#define INA219_ADDRESS_VS_SCL   0b1000111
#define INA219_ADDRESS_SDA_GND  0b1001000
#define INA219_ADDRESS_SDA_VS   0b1001001
#define INA219_ADDRESS_SDA_SDA  0b1001010
#define INA219_ADDRESS_SDA_SCL  0b1001011
#define INA219_ADDRESS_SCL_GND  0b1001100
#define INA219_ADDRESS_SCL_VS   0b1001101
#define INA219_ADDRESS_SCL_SDA  0b1001110
#define INA219_ADDRESS_SCL_SCL  0b1001111

enum MODES {
    POWER_DOWN = 0x00,
    SHUNT_VOLTAGE_TRIGGERED = 0x01,
    BUS_VOLTAGE_TRIGGERED = 0x02,
    SHUNT_AND_BUS_TRIGGERED = 0x03,
    ADC_OFF = 0x04,
    SHUNT_VOLTAGE_CONTINUOUS = 0x05,
    BUS_VOLTAGE_CONTINUOUS = 0x06,
    SHUNT_AND_BUS_CONTINUOUS = 0x07
};

enum ADC_RESOLUTION {
    ADC_RES_9BIT      = 0x0, 
    ADC_RES_10BIT     = 0x1, 
    ADC_RES_11BIT     = 0x2, 
    ADC_RES_12BIT     = 0x3,  
    ADC_RES_12BIT_ALT = 0x8, 

    ADC_RES_2_SAMPLES  = 0x9,
    ADC_RES_4_SAMPLES  = 0xA,  
    ADC_RES_8_SAMPLES  = 0xB,  
    ADC_RES_16_SAMPLES = 0xC,  
    ADC_RES_32_SAMPLES = 0xD,  
    ADC_RES_64_SAMPLES = 0xE,  
    ADC_RES_128_SAMPLES= 0xF    
};

enum PGA_GAIN {
    _40mV = 0x00,
    _80mV = 0x01,
    _160mV = 0x02,
    _320mV = 0x03
};

enum BUS_VOLTAGE_RANGE {
    _16V = 0x00,
    _32V = 0x01
};

void setAddressINA219(const int address_i2c);
int isConnectedINA219(void);

void calibrateINA219(const float maxCurrent, const float resistance_shunt);

void resetINA219(void);

void setBusVoltageRangeINA219(enum BUS_VOLTAGE_RANGE range);
void setShuntVoltageRangeINA219(enum PGA_GAIN gain);
void setBusVoltageResolutionINA219(enum ADC_RESOLUTION resolution);
void setShuntVoltageResolutionINA219(enum ADC_RESOLUTION resolution);
void setModeINA219(enum MODES mode);

float getShuntVoltageINA219(void);
float getBusVoltageINA219(void);
float getCurrentINA219(void);
float getPowerINA219(void);


#endif