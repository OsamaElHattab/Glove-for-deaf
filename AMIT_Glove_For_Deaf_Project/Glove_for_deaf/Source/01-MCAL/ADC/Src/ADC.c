/*
 * ADC.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Osama
 */

#include "ADC.h"
#include "Bit_Math.h"

void ADC_vidInit(void)
{
	// Enable adc
	SET_BIT(ADC_ADCSRA_REG , 7);
	// select Verf+
	SET_BIT(ADC_ADMUX_REG , 6);
	CLEAR_BIT(ADC_ADMUX_REG , 7);
	//select prescaler factor /128
	SET_BIT(ADC_ADCSRA_REG , 0);
	SET_BIT(ADC_ADCSRA_REG , 1);
	SET_BIT(ADC_ADCSRA_REG , 2);
		//or
		//ADC_ADCSRA_REG |= 7;

}


f64 ADC_f64ADCRead (ADC_channelID_t channel)
{
	u16 loc_ADCResult = 0;     //result to be returned
	f64 loc_volt = loc_ADCResult*ADC_step;
	//select channel ADC1
	ADC_ADMUX_REG =(ADC_ADMUX_REG & 0xF8) | channel;


	//set start conversion
	SET_BIT(ADC_ADCSRA_REG , 6);

	//wait on ADIF flag to be raised
	while ( CHECK_BIT(ADC_ADCSRA_REG , 4) != 1 )
	{
		// DO nothing
	}
	// to clear the flag ,you should write 1 on the bit (related to AVR) , but the hardware will write 0 on the bit
	SET_BIT(ADC_ADCSRA_REG , 4); //to clear the interrupt flag

	//read ADCL and ADCH
	loc_ADCResult = (ADC_ADCL_REG)|(ADC_ADCH_REG << 8);

	loc_volt = loc_ADCResult *ADC_step;

	return loc_volt;
}
