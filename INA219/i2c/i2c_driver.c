#include "i2c_driver.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

i2c_inst_t * i2c_port;

int i2c_is_started(void);

void init_i2c_comm(enum I2C_BUS i2c_bus, const uint8_t sda, const uint8_t scl, const uint32_t freq_hz) {
    
    if(i2c_bus == I2C_0)
        i2c_port = i2c0;
    else
        i2c_port = i2c1;
    
    i2c_init(i2c_port, freq_hz); 
    gpio_set_function(sda, GPIO_FUNC_I2C); 
    gpio_set_function(scl, GPIO_FUNC_I2C); 
    gpio_pull_up(sda); 
    gpio_pull_up(scl); 
}

int i2c_write(const uint8_t address, const uint8_t *data, const size_t length) {
    int i2c_result = i2c_write_blocking(i2c_port, address, data, length, false);
    return i2c_result;
}

int i2c_read(const uint8_t address, const uint8_t reg, uint8_t *data, size_t length) {
    int i2c_result = i2c_write_blocking(i2c_port, address, &reg, 1, true); 
    i2c_result += i2c_read_blocking(i2c_port, address, data, length, false); 
    return i2c_result;
}

int i2c_device_is_connected(const uint8_t address) {
    uint8_t data;
    int isFind = i2c_read_blocking(i2c_port, address, &data, 1, false);
}

int i2c_is_started(void) {
    if(i2c_port == NULL)
        return 0;
    return 1;
}