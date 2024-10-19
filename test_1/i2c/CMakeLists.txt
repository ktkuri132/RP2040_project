add_library(i2c i2clib.c)
# 添加外部链接库
target_link_libraries(i2c pico_stdlib hardware_i2c)

#添加本目录头文件
target_include_directories(i2c PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# 启用 USB 串口支持
pico_enable_stdio_usb(i2c 1)
pico_enable_stdio_uart(i2c 0)


# 添加外部库的方法

# 1.添加子目录
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../OLED oled)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../MPU6050 mpu6050)

# 2.链接子目录生成的库
target_link_libraries(i2c oled)
target_link_libraries(i2c mpu6050)