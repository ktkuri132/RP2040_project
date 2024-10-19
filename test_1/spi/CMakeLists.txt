add_library(spi spilib.c)

target_include_directories(spi PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(spi pico_stdlib hardware_spi)

target_link_libraries(spi oled)