#声明可执行文件与参与编译的文件
add_executable(led led.c)

#添加链接库
target_link_libraries(led pico_stdlib)

#添加输出文件
pico_add_extra_outputs(led)