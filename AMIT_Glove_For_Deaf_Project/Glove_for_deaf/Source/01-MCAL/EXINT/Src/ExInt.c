/*
 * ExInt.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Osama
 */

#include "Bit_Math.h"
#include "ExInt_Types.h"
#include "ExInt_Reg.h"
#include "ExInt.h"
#include "Std_Types.h"

void ExtInt_vidConfigExtInt (extint_id_t INTid   , extint_sensectrl  senseCtrl)
{
	switch (INTid)
	{
	case EXT_INT0:
		if (senseCtrl == EXT_RISING_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG , 0);
			SET_BIT(EXTINT_MCUCR_REG , 1);
		}
		else if (senseCtrl == EXT_FALLING_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG , 0);
			SET_BIT(EXTINT_MCUCR_REG , 1);
		}
		else if (senseCtrl == EXT_BOTH_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG , 0);
			CLEAR_BIT(EXTINT_MCUCR_REG , 1);
		}
		else if (senseCtrl == EXT_LOW_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG , 0);
			CLEAR_BIT(EXTINT_MCUCR_REG , 1);
		}

		SET_BIT(EXTINT_GICR_REG , INT0_EN_BIT);
		break;


	case EXT_INT1:
		if (senseCtrl == EXT_RISING_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG , 2);
			SET_BIT(EXTINT_MCUCR_REG , 3);
		}
		else if (senseCtrl == EXT_FALLING_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG , 2);
			SET_BIT(EXTINT_MCUCR_REG , 3);
		}
		else if (senseCtrl == EXT_BOTH_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG , 2);
			CLEAR_BIT(EXTINT_MCUCR_REG , 3);
		}
		else if (senseCtrl == EXT_LOW_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG , 2);
			CLEAR_BIT(EXTINT_MCUCR_REG , 3);
		}

		SET_BIT(EXTINT_GICR_REG , INT1_EN_BIT);
		break;


	case EXT_INT2:

		if (senseCtrl == EXT_RISING_EDGE)
		{
			SET_BIT(EXTINT_MCUCSR_REG , 6);
		}
		else if (senseCtrl == EXT_FALLING_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCSR_REG , 6);
		}

		SET_BIT(EXTINT_GICR_REG , INT2_EN_BIT);
		break;
	}
}

void ExtInt_vidDisapleExtInt (extint_id_t INTid )
{
	switch (INTid)
	{
	case EXT_INT0:
		SET_BIT(EXTINT_GICR_REG,INT0_EN_BIT);
		break;

	case EXT_INT1:
		SET_BIT(EXTINT_GICR_REG,INT1_EN_BIT);
		break;

	case EXT_INT2:
		SET_BIT(EXTINT_GICR_REG,INT2_EN_BIT);
		break;
	}
}
