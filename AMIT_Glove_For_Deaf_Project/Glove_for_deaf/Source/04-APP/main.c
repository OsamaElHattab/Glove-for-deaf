/***************************************
 * main.c
 * Created on: Oct 9, 2022
 * Author: Osama
 ***************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "LCD.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "ExInt.h"
#include "ADC.h"



#define Open      < 2.5     //(volt < 2.5 -> open flex sensor)
#define Hold      > 2.5     //(volt > 2.5 -> hold flex sensor)


int main()
{


	ADC_vidInit();
	Lcd_vidinit();
	Lcd_vidCmd(_LCD_CURSOR_OFF);

	f64  THUMB,INDEX,MIDDLE,RING,PINKY;

	LCD_vidRowColumn(0,0);

	Lcd_vidCmd(_LCD_CLEAR);
	_delay_ms(2000);

	LCD_vidRowColumn(0,0);       //To start from (0,0)

	while(1)
	{
		// To Read from the flexible sensors and return a voltage value (from 0 to 5)

		THUMB = ADC_f64ADCRead(ADC_CHANNEL0);
		_delay_ms(50);

		INDEX = ADC_f64ADCRead(ADC_CHANNEL1);
		_delay_ms(50);

		MIDDLE = ADC_f64ADCRead(ADC_CHANNEL2);
		_delay_ms(50);

		RING = ADC_f64ADCRead(ADC_CHANNEL3);
		_delay_ms(50);

		PINKY = ADC_f64ADCRead(ADC_CHANNEL4);
		_delay_ms(50);

		//To check for the sensors condition and display the right message

		if	   (THUMB Hold && INDEX Open && MIDDLE Hold && RING Hold && PINKY Hold)
		{
			Lcd_vidDisplayStr("       You       ");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		else if(THUMB Hold && INDEX Open && MIDDLE Open && RING Hold && PINKY Hold)
		{
			Lcd_vidDisplayStr("I am watching you");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		else if(THUMB Open && INDEX Open && MIDDLE Hold && RING Hold && PINKY Open)
		{
			Lcd_vidDisplayStr("    I love you    ");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		else if(THUMB Open && INDEX Open && MIDDLE Open && RING Hold && PINKY Open)
		{
			Lcd_vidDisplayStr("I'm really love you");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		else if(THUMB Hold && INDEX Open && MIDDLE Hold && RING Hold && PINKY Open)
		{
			Lcd_vidDisplayStr("This is incredible");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		else if(THUMB Open && INDEX Open && MIDDLE Open && RING Open && PINKY Open)
		{
			Lcd_vidDisplayStr(" I wish you a ");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("  happy life  ");
		}

		else if(THUMB Open && INDEX Hold && MIDDLE Hold  && RING Hold && PINKY Hold)
		{
			Lcd_vidDisplayStr("    Good job    ");
			LCD_vidRowColumn(1,0);
			Lcd_vidDisplayStr("                  ");
		}

		_delay_ms(500);
		LCD_vidRowColumn(0,0); //To return to (0,0)

	}

return 0;
}
