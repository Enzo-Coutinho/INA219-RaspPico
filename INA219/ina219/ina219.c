#include "ina219.h"
#include "i2c/i2c_driver.h"
#include "registers.h"

const size_t LENGHT = 2;
int ADDRESS;

uint16_t read_register(enum REGISTERS reg);
void write_register(enum REGISTERS reg, const uint16_t data);

void initializeINA219(const int sda, const int scl, const int freq, const int address_i2c) {
    ADDRESS = address_i2c;
    init_i2c_comm(i2c0, sda, scl, freq);
}


uint16_t read_register(enum REGISTERS reg) {
    uint8_t data[LENGHT];
    i2c_read(ADDRESS, reg, data, LENGHT);
}

void write_register(enum REGISTERS reg, const uint16_t data) {
    const size_t adapt_lenght = LENGHT + 1;
    const uint8_t data_format[adapt_lenght] = {reg, (uint8_t)((data & 0xFF00) >> 8), (uint8_t)(data & 0xFF)};
    i2c_write(ADDRESS, data_format, adapt_lenght);
}