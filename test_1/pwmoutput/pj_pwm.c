#include <pico/stdlib.h>
#include <hardware/pwm.h>   
#include <hardware/gpio.h>

int main()
{
    gpio_init(25);
    gpio_init(0);

    /* gpio设置复用  */
    gpio_set_function(0,GPIO_FUNC_PWM);
    /* 确定gpio端口对应的pwm切片  */
    uint slice_num = pwm_gpio_to_slice_num(0);
    /* 设置指定的pwm切片的周期（频率）  */
    uint pwm_freq = 100;
    uint clock_freq = 125000;
    uint wrap = clock_freq/pwm_freq -1;
    pwm_set_wrap(slice_num,wrap);
    /* 设置指定的pwm切片的输出通道，以及占空比  */
    pwm_set_chan_level(slice_num,PWM_CHAN_A,wrap/2);
    /* 输出使能  */
    pwm_set_enabled(slice_num,true);

    
    gpio_set_dir(25, GPIO_OUT);
    


    while (1)
    {
        gpio_put(25, 1);
        //sleep_ms(500);
        //gpio_put(25, 0);
        //sleep_ms(500);
    }
    
}
