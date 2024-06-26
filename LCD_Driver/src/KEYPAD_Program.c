/*
 * KEYPAD_Program.c
 *
 *  Created on: Sep 28, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"

#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_Private.h"

#include "../include/HAL/KEYPAD/KEYPAD_Cfg.h"

#include <util/delay.h>

#define F_CPU	8000000UL

u8 static const global_u8ArrOfRows[KEYPAD_ROW_NO] = KEYPAD_ROWS;
u8 static const global_u8ArrOfCols[KEYPAD_COL_NO] = KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8KeyValue = NO_KEY_PRESSED;

	u8 local_u8ROWCounter = 0,	local_u8ColCounter = 0,	local_u8PinValue, local_u8Flag = FLAG_DOWN;
			//Loop On ROWS
			for(local_u8ROWCounter = 0; local_u8ROWCounter<KEYPAD_ROW_NO; local_u8ROWCounter++)
			{
				//Activate One Row
				MDIO_voidSetPinValue(KEYPAD_PORT,global_u8ArrOfRows[local_u8ROWCounter],KEYPAD_ROW_ACTIVE);


				//Check On COLs
				for(local_u8ColCounter = 0; local_u8ColCounter<KEYPAD_COL_NO; local_u8ColCounter++)
				{
					//Read COL
					local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);
					//Check if Key is Pressed
					if(local_u8PinValue == KEY_PRESSED)
					{
						//Debouncing Delay
						_delay_ms(KEYPAD_DEBOUNCING_DELAY_ms);
					    local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);
						if(local_u8PinValue == KEY_PRESSED)
						{
							while(local_u8PinValue == KEY_PRESSED)//Poling On Flag
							{
								local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);
							}//End of While Loop
							local_u8KeyValue = globl_u8arrOfKeyValues[local_u8ROWCounter][local_u8ColCounter];
							local_u8Flag = FLAG_UP;//Notification For COLs.... Loop To break and Return
							break;
						}


					}
				}//End Of COLs Loop
				//DE-Activate One Row
				MDIO_voidSetPinValue(KEYPAD_PORT,global_u8ArrOfRows[local_u8ROWCounter],KEYPAD_ROW_DEACTIVE);

				if(local_u8Flag == FLAG_UP)
				{
					break; //Break ROWs Loop
				}
			}//End Of ROWS Loop



	return local_u8KeyValue; //Return Pressed Key Value
}


