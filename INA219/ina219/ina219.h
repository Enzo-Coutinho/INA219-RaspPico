#ifndef INA219_h
#define INA219_H

#define _400kHz (400e3)
#define _100kHz (100e3)

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