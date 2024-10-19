#include <pico/stdlib.h>    

#include <OLED.h>
#include <OLED_Data.h>
#include <spilib.h>


int main()
{
    stdio_init_all();
    OLED_Init();
    while (1)
    {
        OLED_Printf(0, 0,OLED_8X16, "Hello, world!");
        OLED_Update();
    }
    
}