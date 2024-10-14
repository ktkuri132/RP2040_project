#include <pico/stdlib.h>
#include <pico/types.h>
#include <hardware/i2c.h>
#include <i2clib.h>
#include <OLED.h>
#include <mpu6050.h>
#include <inv_mpu.h>

float pitch, roll, yaw;

int main()
{
    stdio_init_all();
    mpu_dmp_init();
    OLED_Init();
    
    //uint8_t data[2] = {0x00, 0x00};
    //i2c_read_blocking(I2C_PORT, ADDRESS, data, 2, false);
    

    while (1)
    {
        //printf("MPU6050 Init: %d\n", res);
        //
        //printf("Data: %d %d\n", data[0], data[1]);
        mpu_dmp_get_data(&pitch, &roll, &yaw);
        OLED_Printf(0, 0, OLED_8X16, "Pitch: %f", pitch);
        OLED_Update();
        
        //printf("Pitch: %f, Roll: %f, Yaw: %f\n", pitch, roll, yaw);
        //sleep_ms(1000);
    }
    
    return 0;
}