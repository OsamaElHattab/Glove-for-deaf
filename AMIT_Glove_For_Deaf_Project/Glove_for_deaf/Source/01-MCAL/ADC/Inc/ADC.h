/*
 * ADC.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Osama
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_H_

#include "ADC_Types.h"
#include "ADC_Reg.h"
#include "Std_Types.h"

#define ADC_step (4.8)

void ADC_vidInit(void);
f64 ADC_f64ADCRead (ADC_channelID_t channel);  //to return the number of steps (10 bits)


#endif /* SOURCE_01_MCAL_ADC_INC_ADC_H_ */
