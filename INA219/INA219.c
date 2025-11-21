#include <stdio.h>
#include "ina219/ina219.h"

#define I2C_SDA 8
#define I2C_SCL 9

int main()
{
    init_i2c_comm(I2C_0, I2C_SDA, I2C_SCL, _400kHz);

    setAddressINA219(INA219_ADDRESS_GND_GND);

    resetINA219();

    printf("Connecting to INA219...");
    while(!isConnectedINA219())
        printf("...");
        
    printf("\nSuccessful connection!\n");
    
    for(;;) {
        printf("Bus Voltage (V): %f", getBusVoltageINA219());
        printf("Shunt Voltage (mV): %f", getShuntVoltageINA219());
    }
}
