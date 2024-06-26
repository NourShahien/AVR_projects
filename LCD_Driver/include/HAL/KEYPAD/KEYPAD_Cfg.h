/*
 * KEYPAD_Cfg.h
 *
 *  Created on: Sep 28, 2023
 *      Author: nours
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_


#define KEYPAD_ROW_NO	4
#define KEYPAD_COL_NO	4

u8 globl_u8arrOfKeyValues	[KEYPAD_ROW_NO] [KEYPAD_COL_NO] ={
																{'1','2','3','+'},
																{'4','5','6','-'},
																{'7','8','9','*'},
																{'C','0','=','/'}
															};

#define NO_KEY_PRESSED	255

#define KEYPAD_PORT	 DIO_PORTA

#define KEYPAD_ROW0		PIN0
#define KEYPAD_ROW1		PIN1
#define KEYPAD_ROW2		PIN2
#define KEYPAD_ROW3		PIN3

#define KEYPAD_COL0		PIN4
#define KEYPAD_COL1		PIN5
#define KEYPAD_COL2		PIN6
#define KEYPAD_COL3		PIN7

#define KEYPAD_ROWS		{KEYPAD_ROW0,KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3}
#define KEYPAD_COLS		{KEYPAD_COL0,KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3}

#define KEYPAD_DEBOUNCING_DELAY_ms	30


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
