#include <stdio.h>
#include "pico/stdlib.h"
#include "ina219/ina219.h"

#define I2C_SDA 8
#define I2C_SCL 9

int main()
{
    stdio_init_all();

    init_i2c_comm(I2C_0, I2C_SDA, I2C_SCL, _400kHz);

    setAddressINA219(INA219_ADDRESS_GND_GND);

    resetINA219();

    stdio_printf("Connecting to INA219...");
    while(!isConnectedINA219())
        stdio_printf("...");
        
    stdio_printf("\nSuccessful connection!\n");
    
    for(;;) {
        stdio_printf("Bus Voltage (V): %f\n", getBusVoltageINA219());
        stdio_printf("Shunt Voltage (mV): %f\n", getShuntVoltageINA219());
        stdio_printf("Current (A): %f\n", getCurrentINA219());
        stdio_printf("Power (W): %f\n", getPowerINA219());
    }
}
