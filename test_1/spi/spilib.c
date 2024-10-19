#include <spilib.h>


void SPI_GPIO_Init(spi_inst_t *SPI_PORT, uint8_t SCK, uint8_t MOSI, uint8_t MISO, uint8_t CS)
{
	gpio_init(SCK);
	gpio_init(MOSI);
	gpio_init(MISO);
	gpio_init(CS);
    
	gpio_set_function(SCK, GPIO_FUNC_SPI);
	gpio_set_function(MOSI, GPIO_FUNC_SPI);
	gpio_set_function(MISO, GPIO_FUNC_SPI);

	gpio_set_dir(CS, GPIO_OUT);
	gpio_put(CS, 1); // CS 高电平表示不选中

	spi_init(SPI_PORT, 2500000);
}

// SPI 写命令，无需写入长度
uint8_t SPI_WriteCommand(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t Command)
{

	gpio_put(CS, 0); // CS 低电平表示选中
	spi_write_blocking(SPI_PORT, &Command, 1);
	gpio_put(CS, 1); // CS 高电平表示不选中
	return 0;
}

// SPI 写数据，需要写入长度
uint8_t SPI_WriteData(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t *Data, uint8_t Count)
{
	gpio_put(CS, 0); // CS 低电平表示选中
	spi_write_blocking(SPI_PORT, Data, Count);
	gpio_put(CS, 1); // CS 高电平表示不选中
	return 0;
}

// SPI 读数据，需要读取长度
uint8_t SPI_ReadData(spi_inst_t *SPI_PORT, uint8_t CS, uint8_t *Data, uint8_t Count)
{
    gpio_put(CS, 0); // CS 低电平表示选中
    spi_read_blocking(SPI_PORT, 0, Data, Count);
    gpio_put(CS, 1); // CS 高电平表示不选中
    return 0;
}