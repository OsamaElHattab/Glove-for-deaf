/*
 * ExInt_types.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Osama
 */

#ifndef SOURCE_01_MCAL_EXINT_INC_EXINT_TYPES_H_
#define SOURCE_01_MCAL_EXINT_INC_EXINT_TYPES_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2,
}extint_id_t;

typedef enum
{
	EXT_FALLING_EDGE,
	EXT_RISING_EDGE,
	EXT_BOTH_EDGE,
	EXT_LOW_EDGE
}extint_sensectrl;

#endif /* SOURCE_01_MCAL_EXINT_INC_EXINT_TYPES_H_ */
