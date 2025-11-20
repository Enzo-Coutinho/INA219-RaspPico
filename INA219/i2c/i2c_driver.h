#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define INIT_I2C_WITH_PINS(i2c_port, SDA_PIN, SCL_PIN, FREQ) \
    i2c_init(i2c_port, FREQ); \
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C); \
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C); \
    gpio_pull_up(SDA_PIN); \
    gpio_pull_up(SCL_PIN); \
    bi_decl(bi_2pins_with_func(SDA_PIN, SCL_PIN, GPIO_FUNC_I2C));

void i2c_write(const uint8_t address, const uint8_t *data, const size_t length);
void i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, const size_t length);

#endif