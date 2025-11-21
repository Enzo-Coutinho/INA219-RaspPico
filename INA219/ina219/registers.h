#ifndef REGISTERS_H
#define REGISTERS_H

typedef unsigned char u8;
typedef unsigned short int u16;

/*    ADRESS SLAVE
========================
    GND GND 1000000
    GND VS+ 1000001
    GND SDA 1000010
    GND SCL 1000011
    VS+ GND 1000100
    VS+ VS+ 1000101
    VS+ SDA 1000110
    VS+ SCL 1000111
    SDA GND 1001000
    SDA VS+ 1001001
    SDA SDA 1001010
    SDA SCL 1001011
    SCL GND 1001100
    SCL VS+ 1001101
    SCL SDA 1001110
    SCL SCL 1001111
=======================
*/

#define DEFAULT_VALUE_CONFIGURATION 0x399F

enum REGISTERS {
    __ADDR_CONFIGURATION = 0x00,
    __ADDR_SHUNT_VOLTAGE = 0x01,
    __ADDR_BUS_VOLTAGE = 0x02,
    __ADDR_POWER = 0x03,
    __ADDR_CURRENT = 0x04,
    __ADDR_CALIBRATION = 0x05
};

union configuration_t {
    struct configuration_bitmap_t {
        u16 MODES : 3;
        u16 SADC : 4;
        u16 BADC : 4;
        u16 PG : 2;
        u16 BRNG : 1;
        u16 : 1;
        u16 RST : 1;
    } _configuration_bitmap;
    u16 configuration;
};



#endif