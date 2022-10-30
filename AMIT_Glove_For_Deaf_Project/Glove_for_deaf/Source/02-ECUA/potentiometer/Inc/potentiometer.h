/*
 * potentiometer.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Osama
 */

#ifndef SOURCE_02_ECUA_POTENTIOMETER_INC_POTENTIOMETER_H_
#define SOURCE_02_ECUA_POTENTIOMETER_INC_POTENTIOMETER_H_

#include "ADC.h"

void pot_vidInit(void);
u16 pot_u16Read(void);

#endif /* SOURCE_02_ECUA_POTENTIOMETER_INC_POTENTIOMETER_H_ */
