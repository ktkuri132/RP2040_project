#include <pico/stdlib.h>
#include <pico/types.h>
#include <pico/multicore.h>

void core1_main()
{
    while (1)
    {
        printf("Core 1\n");
        sleep_ms(1000);
    }
}


int main()
{
    uint16_t i = 0;
    stdio_init_all();

    gpio_init(25);
    gpio_init(26);
    gpio_set_dir(25, GPIO_OUT);
    
    
    multicore_launch_core1(core1_main);
    while (1)
    {
        printf("Core 0\n");
        gpio_put(25, 1);
        sleep_ms(1000);
        gpio_put(25, 0);
        sleep_ms(1000);
    }
    
}