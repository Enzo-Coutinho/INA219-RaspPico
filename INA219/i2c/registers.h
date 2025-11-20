#ifndef REGISTERS_H
#define REGISTERS_H

#define ADDRESS_WITH_BIT(X) (1 << X)

typedef unsigned char u8;
typedef unsigned short int u16;

enum REGISTERS {
    __ADDR_CONFIGURATION = 0x00,
    __ADDR_SHUNT_VOLTAGE = 0x01,
    __ADDR_BUS_VOLTAGE = 0x02,
    __ADDR_POWER = 0x03,
    __ADDR_CURRENT = 0x04,
    __ADDR_CALIBRATION = 0x05
};

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

enum RESOLUTION {
    _9_BIT = 0x00,
    _10_BIT = 0x01,
    _11_BIT = 0x02,
    _12_BIT1 = 0x03,
    _12_BIT2 = 0,

};

typedef union configuration_t {
    struct configuration_bitmap_t {
        u8 MODES : 3;
        u8 SADC : 4;
        u8 BADC : 4;
        u8 PG : 2;
        u8 BRNG : 1;
        u8 : 1;
        u8 RST : 1;
    } _configuration_bitmap;
    u16 configuration;
};



#endif