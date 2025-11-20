#include "i2c_driver.h"

#define I2C_PORT i2c0

void i2c_write(const uint8_t address, const uint8_t *data, const size_t length) {
    i2c_write_blocking(I2C_PORT, address, data, length, false);
}

void i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, size_t length) {
    i2c_write_blocking(I2C_PORT, address, &reg, 1, true); 
    i2c_read_blocking(I2C_PORT, address, data, length, false); 
}