#include <pico/stdlib.h>
#include <hardware/uart.h>

int main()
{

    stdio_init_all();

    uart_init(uart0, 115200);
    
    gpio_set_function(1, GPIO_FUNC_UART);
    gpio_set_function(0, GPIO_FUNC_UART);   

    uart_set_format(uart0, 8, 1, UART_PARITY_NONE);

    while(1)
    {
        uart_puts(uart0, "Hello, world!\n");
        sleep_ms(1000);
    }

    return 0;

}
