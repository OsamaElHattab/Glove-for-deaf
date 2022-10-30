/*
 * ExInt.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Osama
 */

#ifndef SOURCE_01_MCAL_EXINT_INC_EXINT_H_
#define SOURCE_01_MCAL_EXINT_INC_EXINT_H_

#include "ExInt_types.h"

#define INT0_EN_BIT (6)
#define INT1_EN_BIT (7)
#define INT2_EN_BIT (5)

void ExtInt_vidConfigExtInt (extint_id_t INTid   , extint_sensectrl  senseCtrl);
void ExtInt_vidDisapleExtInt (extint_id_t INTid );

#endif /* SOURCE_01_MCAL_EXINT_INC_EXINT_H_ */
