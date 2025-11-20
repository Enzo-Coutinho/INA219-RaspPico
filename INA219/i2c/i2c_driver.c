#include "i2c_driver.h"

i2c_inst_t * i2c_bus;

void init_i2c_comm(i2c_inst_t * i2c_port, const uint sda, const uint scl, const uint freq_hz) {
    i2c_bus = i2c_port;
    
    i2c_init(i2c_port, freq_hz); 
    gpio_set_function(sda, GPIO_FUNC_I2C); 
    gpio_set_function(scl, GPIO_FUNC_I2C); 
    gpio_pull_up(sda); 
    gpio_pull_up(scl); 
}

int i2c_write(const uint8_t address, const uint8_t *data, const size_t length) {
    int i2c_result = i2c_write_blocking(i2c_bus, address, data, length, false);
    return i2c_result;
}

int i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, size_t length) {
    int i2c_result = i2c_write_blocking(i2c_bus, address, &reg, 1, true); 
    i2c_result += i2c_read_blocking(i2c_bus, address, data, length, false); 
    return i2c_result;
}