add_executable(multicore multicore.c)

target_link_libraries(multicore pico_stdlib pico_multicore)

# 启用 USB 串口支持
pico_enable_stdio_usb(multicore 1)
pico_enable_stdio_uart(multicore 0)

pico_add_extra_outputs(multicore)



