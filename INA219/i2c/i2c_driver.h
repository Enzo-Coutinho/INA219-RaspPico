#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

void init_i2c_comm(i2c_inst_t * i2c_port, const uint sda, const uint scl, const uint freq_hz);

int i2c_write(const uint8_t address, const uint8_t *data, const size_t length);
int i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, const size_t length);

#endif