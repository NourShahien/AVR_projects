/*
++* App_8.c
 *
 *  Created on: Oct 27, 2023
 *      Author: nours
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/MCAL/UART/UART_Interface.h"

// tx_Buffer[30] = "To Turn ON The LED Press o or O \r\nTo Turn OFF The LED Press f or F\r\n"
		//MUART_voidSendStringSyncNonBlocking($uart, tx_buffer,30)
#include<util/delay.h>


#define F_CPU 8000000UL

void main(void)
{
	MDIO_voidInit();
	MUART_voidInit();
	u8 local_u8ReceivedData = 255;
	MUART_voidSendStringSyncNonBlocking("To Turn ON The LED Press o or O \r\nTo Turn OFF The LED Press f or F\r\n");
	while(1)
	{
		local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();
		if((local_u8ReceivedData) == 'o' || (local_u8ReceivedData == 'O'))
		{
			HLED_voidTurnLEDOn(DIO_PORTA,PIN0);
			MUART_voidSendStringSyncNonBlocking("LED ON\r\n");
		}
		else if((local_u8ReceivedData) == 'f' || (local_u8ReceivedData == 'F'))
		{
			HLED_voidTurnLEDOff(DIO_PORTA,PIN0);
			MUART_voidSendStringSyncNonBlocking("LED OFF\r\n");

		}

	}

}
