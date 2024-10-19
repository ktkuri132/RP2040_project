#ifndef __OLED_H_
#define __OLED_H_
#define __OLED_

#include <OLED_Data.h>
#include <stdarg.h>

/* 外部接口头文件  */
//#include <i2clib.h>
#include <spilib.h>

#ifdef __I2CLIB_H__

#define OLED_I2C_PORT i2c1
#define OLED_SCL 3
#define OLED_SDA 2

/* 定义1.3寸OLED地址及其寄存器  */
#define OLED_ADDRESS 0x3C //7位OLED地址  stm32上OLED的IIC地址为0x78
#define OLED_Data_Mode 0x40
#define OLED_Command_Mode 0x00

/* 江科大OLED IIC操作接口   */
#define OLED_WriteCommand(Command)      IIC_WriteCommand(OLED_I2C_PORT,OLED_ADDRESS,OLED_Command_Mode,Command)
#define OLED_WriteData(Data,Count)      IIC_WriteData(OLED_I2C_PORT,OLED_ADDRESS,OLED_Data_Mode,Data,Count)
#define OLED_GPIO_Init(port,scl,sda)    IIC_GPIO_Init(port,scl,sda)

#endif

#ifdef __SPILIB_H__

#define SCK     2   //时钟信号
#define MOSI    3  //TX
#define MISO    4  //RX
#define CSn     5    //片选信号

#define OLED_SPI_PORT   spi0
#define OLED_DO         SCK    
#define OLED_DI         MOSI
#define OLED_RES        6
#define OLED_DC         7
#define OLED_CS         CSn

#define OLED_WriteCommand(Command)  {                                                       \      
                                        gpio_put(OLED_DC,0);                                \
                                        SPI_WriteCommand(OLED_SPI_PORT,OLED_CS,Command);    \
                                        gpio_put(OLED_DC,1);                                \
                                    }

#define OLED_WriteData(Data,Count)  SPI_WriteData(OLED_SPI_PORT,OLED_CS,Data,Count)
#define OLED_GPIO_Init(port,DO,DI,CS)       SPI_GPIO_Init(port,DO,DI,MISO,CS)

#endif


/*FontSize参数取值*/
/*此参数值不仅用于判断，而且用于计算横向字符偏移，默认值为字体像素宽度*/
#define OLED_8X16				8
#define OLED_6X8				6

/*IsFilled参数数值*/
#define OLED_UNFILLED			0
#define OLED_FILLED				1


/*初始化函数*/
void OLED_Init(void);

/*更新函数*/
void OLED_Update(void);
void OLED_UpdateArea(int16_t X, int16_t Y, uint8_t Width, uint8_t Height);

/*显存控制函数*/
void OLED_Clear(void);
void OLED_ClearArea(int16_t X, int16_t Y, uint8_t Width, uint8_t Height);
void OLED_Reverse(void);
void OLED_ReverseArea(int16_t X, int16_t Y, uint8_t Width, uint8_t Height);

/*显示函数*/
void OLED_ShowChar(int16_t X, int16_t Y, char Char, uint8_t FontSize);
void OLED_ShowString(int16_t X, int16_t Y, char *String, uint8_t FontSize);
void OLED_ShowNum(int16_t X, int16_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowSignedNum(int16_t X, int16_t Y, int32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowHexNum(int16_t X, int16_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowBinNum(int16_t X, int16_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowFloatNum(int16_t X, int16_t Y, double Number, uint8_t IntLength, uint8_t FraLength, uint8_t FontSize);
void OLED_ShowChinese(int16_t X, int16_t Y, char *Chinese);
void OLED_ShowImage(int16_t X, int16_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image);
void OLED_Printf(int16_t X, int16_t Y, uint8_t FontSize, char *format, ...);

/*绘图函数*/
void OLED_DrawPoint(int16_t X, int16_t Y);
uint8_t OLED_GetPoint(int16_t X, int16_t Y);
void OLED_DrawLine(int16_t X0, int16_t Y0, int16_t X1, int16_t Y1);
void OLED_DrawRectangle(int16_t X, int16_t Y, uint8_t Width, uint8_t Height, uint8_t IsFilled);
void OLED_DrawTriangle(int16_t X0, int16_t Y0, int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, uint8_t IsFilled);
void OLED_DrawCircle(int16_t X, int16_t Y, uint8_t Radius, uint8_t IsFilled);
void OLED_DrawEllipse(int16_t X, int16_t Y, uint8_t A, uint8_t B, uint8_t IsFilled);
void OLED_DrawArc(int16_t X, int16_t Y, uint8_t Radius, int16_t StartAngle, int16_t EndAngle, uint8_t IsFilled);

#endif