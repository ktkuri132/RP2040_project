add_executable(pj_pwm pj_pwm.c)

target_link_libraries(pj_pwm pico_stdlib hardware_pwm)

pico_add_extra_outputs(pj_pwm)



