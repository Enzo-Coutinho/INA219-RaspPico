#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <inttypes.h>
#include <stddef.h>

#define _400kHz (400e3)
#define _100kHz (100e3)

enum I2C_BUS {
    I2C_0,
    I2C_1,
};

void init_i2c_comm(enum I2C_BUS i2c_bus, const uint8_t sda, const uint8_t scl, const uint32_t freq_hz);

int i2c_write(const uint8_t address, const uint8_t *data, const size_t length);
int i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, const size_t length);

int i2c_find_device(const uint8_t address);

#endif