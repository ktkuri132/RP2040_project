#ifndef __SPILIB_H__
#define __SPILIB_H__

#include <pico/stdlib.h>    
#include <hardware/spi.h>

void SPI_GPIO_Init(spi_inst_t *SPI_PORT, uint8_t SCK, uint8_t MOSI, uint8_t MISO, uint8_t CS);
uint8_t SPI_WriteCommand(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t Command);
uint8_t SPI_WriteData(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t *Data, uint8_t Count);
uint8_t SPI_ReadData(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t *Data, uint8_t Count);


#endif