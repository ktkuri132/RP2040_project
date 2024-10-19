add_executable(user main.c)

# 添加依赖库
target_link_libraries(user pico_stdlib oled spi i2c)

pico_add_extra_outputs(user)

