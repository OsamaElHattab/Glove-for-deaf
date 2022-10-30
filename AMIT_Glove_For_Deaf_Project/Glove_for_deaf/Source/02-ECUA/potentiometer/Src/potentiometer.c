/*
 * potentiometer.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Osama
 */

#include "potentiometer.h"

void pot_vidInit(void)
{
	ADC_vidInit();
}

u16 pot_u16Read(void)
{
	f64 loc_adcRead =0;
	u16 loc_pot =0;

	loc_adcRead = ADC_f64ADCRead (ADC_CHANNEL1);
	loc_pot = loc_adcRead / 10;

	return loc_pot;
}

