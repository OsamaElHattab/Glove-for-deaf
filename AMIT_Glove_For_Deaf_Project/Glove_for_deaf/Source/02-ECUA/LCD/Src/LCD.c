/*
 * LCD.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Osama
 */
#include "LCD.h"
#include "Dio.h"
#include <util/delay.h>
#define LCD_MASK (0x0F)

void Lcd_vidinit(void)
{
	//configure
	Dio_vidconfigChanel(DIO_PORTB , DIO_PIN1 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB , DIO_PIN2 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT);

	//configure data pins as output
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN4 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN5 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN6 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN7 , DIO_OUTPUT);

	//Always write on LCD
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN2 , DIO_LOW);

	_delay_ms(15);
	Lcd_vidCmd(0x03);
	_delay_ms(5);
	Lcd_vidCmd(0x03);
	_delay_us(100);
	Lcd_vidCmd(0x03);
	Lcd_vidCmd(0x02);
	Lcd_vidCmd(_LCD_4BIT_MODE);
}

static void Lcd_VidenablePulse(void) //not in .h and static as user will not use it
{
	//send enable pulse
		Dio_vidwriteChanel(DIO_PORTB , DIO_PIN3 , DIO_HIGH);
		_delay_us(1);
		Dio_vidwriteChanel(DIO_PORTB , DIO_PIN3 , DIO_LOW);
		_delay_ms(2);
}

void Lcd_vidDisplayChar(u8 chr)
{
	//    MSB  LSB
	//0b 1101 1001
	u8 loc_MSB = chr & 0xF0;  //0xF0 = ~LCD_MASK  //1101 0000
	u8 loc_LSB = chr << 4;						  //1001 0000

	// RS->1
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN1 , DIO_HIGH);

	// Write data to MSB
	Dio_vidWriteChanelGroup(DIO_PORTA , loc_MSB , LCD_MASK);

	//send enable pulse
	Lcd_VidenablePulse();

	// Write data to LSB
	Dio_vidWriteChanelGroup(DIO_PORTA , loc_LSB , LCD_MASK);

	//send enable pulse
	Lcd_VidenablePulse();

}

void Lcd_vidDisplayStr(u8 * str)
{
	while (*str != '\0')
	{
		Lcd_vidDisplayChar(*str);
		str++;
	}
}

void LCD_vidDisplayInt(u32 num)
{
	u8 buffer [5];
	sprintf(buffer , "%d" , num);
	Lcd_vidDisplayStr(buffer);
}

void LCD_vidDisplayFloat(f64 num)
{

}

void Lcd_vidCmd(lcd_Cmd_t cmd)
{
	//    MSB  LSB
	//0b 1101 1001
	u8 loc_MSB = cmd & 0xF0;  //0xF0 = ~LCD_MASK  //1101 0000
	u8 loc_LSB = cmd << 4;						  //1001 0000

	// RS->0
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN1 , DIO_LOW);

	// Write data to MSB
	Dio_vidWriteChanelGroup(DIO_PORTA , loc_MSB , LCD_MASK);

	//send enable pulse
	Lcd_VidenablePulse();

	// Write data to LSB
	Dio_vidWriteChanelGroup(DIO_PORTA , loc_LSB , LCD_MASK);

	//send enable pulse
	Lcd_VidenablePulse();
}

void LCD_vidRowColumn(u8 row , u8 col)
{
	switch (row)
	{
	case 0:
		Lcd_vidCmd(0x80 + col);
		break;
	case 1:
		Lcd_vidCmd(0xC0 + col);
		break;
	}
}

