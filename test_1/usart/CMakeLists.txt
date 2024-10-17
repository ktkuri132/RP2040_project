#创建可执行文件
add_executable(usart usart.c)

#添加外部库
target_link_libraries(usart pico_stdlib hardware_uart)

#添加输出文件
pico_add_extra_outputs(usart)