#include "ina219.h"
#include "registers.h"
#include "i2c/i2c_driver.h"
#include <math.h>

const size_t LENGHT = 2;
int ADDRESS;

float current_lsb;

union configuration_t configuration_ina219 = {.configuration = 0x0};

void set_configuration(union configuration_t * configure);
void get_configuration(union configuration_t * configure);

void calibrateINA219(const float maxCurrent, const float resistance_shunt);

uint16_t read_register(enum REGISTERS reg);
void write_register(enum REGISTERS reg, const uint16_t data);

void initializeINA219(const int sda, const int scl, const int freq, const int address_i2c) {
    ADDRESS = address_i2c;
    init_i2c_comm(i2c0, sda, scl, freq);
}

void resetINA219(void) {
    configuration_ina219._configuration_bitmap.RST = 1;
    set_configuration(&configuration_ina219);
}

float getCurrentINA219(void) {
    int16_t current_raw = read_register(__ADDR_CURRENT);
    return current_raw * current_lsb;
}

float getPowerINA219(void) {
    uint16_t power_raw = read_register(__ADDR_POWER);
    const float POWER_LSB = current_lsb * 20;
    return power_raw * POWER_LSB;
}

float getShuntVoltageINA219(void) {
    int16_t raw_shunt_voltage = read_register(__ADDR_SHUNT_VOLTAGE);
    const float SHUNT_VOLTAGE_LSB = 1e-5;
    return raw_shunt_voltage * SHUNT_VOLTAGE_LSB;
}


float getBusVoltageINA219(void) {
    int16_t raw_bus_voltage = read_register(__ADDR_BUS_VOLTAGE);
    uint8_t flags = raw_bus_voltage & 0x03;

    if(flags & 0x01) 
        return NAN;

    const float BUS_VOLTAGE_LSB = 4e-3;

    return (raw_bus_voltage >> 3) * BUS_VOLTAGE_LSB;
}

void calibrateINA219(const float maxCurrent, const float resistance_shunt) {
    current_lsb = maxCurrent / (pow(2, 15));

    uint16_t calibration_value = (uint16_t)(0.04096 / (current_lsb * resistance_shunt));

    write_register(__ADDR_CALIBRATION, calibration_value);
}

void set_configuration(union configuration_t * configure) {
    write_register(__ADDR_CONFIGURATION, configure->configuration);
}

void get_configuration(union configuration_t * configure) {
    configure->configuration = read_register(__ADDR_CONFIGURATION);
}

uint16_t read_register(enum REGISTERS reg) {
    uint8_t data[LENGHT];
    i2c_read(ADDRESS, reg, data, LENGHT);
    return ((uint16_t)(data[0] << 8) & 0xFF00) | data[1];
}

void write_register(enum REGISTERS reg, const uint16_t data) {
    const size_t adapt_lenght = LENGHT + 1;
    const uint8_t data_format[] = {reg, (uint8_t)(data & 0xFF), (uint8_t)((data & 0xFF00) >> 8)};
    i2c_write(ADDRESS, data_format, adapt_lenght);
}