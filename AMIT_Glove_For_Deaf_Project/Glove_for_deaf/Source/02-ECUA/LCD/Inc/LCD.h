/*
 * LCD.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Osama
 */

#ifndef SOURCE_02_ECUA_LCD_INC_LCD_H_
#define SOURCE_02_ECUA_LCD_INC_LCD_H_

#include "Std_Types.h"
#include "LCD.types.h"

void Lcd_vidinit(void);
void Lcd_vidDisplayChar(u8 chr);
void Lcd_vidDisplayStr(u8 * str);
void LCD_vidDisplayInt(u32 num);
void LCD_vidDisplayFloat(f64 num);
void Lcd_vidCmd(lcd_Cmd_t cmd);
void LCD_vidRowColumn(u8 row , u8 col);


#endif /* SOURCE_02_ECUA_LCD_INC_LCD_H_ */
