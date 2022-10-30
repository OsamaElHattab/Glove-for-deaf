/*
 * ADC_Reg.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Osama
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_REG_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_REG_H_

#include "Std_Types.h"

#define ADC_ADMUX_REG    (*(volatile u8*)0x27)
#define ADC_ADCSRA_REG   (*(volatile u8*)0x26)
#define ADC_ADCH_REG     (*(volatile u8*)0x25)
#define ADC_ADCL_REG     (*(volatile u8*)0x24)
#define ADC_SFIOR_REG    (*(volatile u8*)0x50)


#endif /* SOURCE_01_MCAL_ADC_INC_ADC_REG_H_ */
