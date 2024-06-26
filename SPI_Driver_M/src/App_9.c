/*
 * App_9.c
 *
 *  Created on: Oct 31, 2023
 *      Author: nours
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/MCAL/SPI/SPI_Interface.h"

#include<util/delay.h>
#define F_CPU 8000000UL

void main(void)
{
	MDIO_voidInit();
	MSPI_voidInit();
	u8 local_u8ReceivedData;
	while(1)
	{
		local_u8ReceivedData = MSPI_u8TransReceive('7');
		if(local_u8ReceivedData == '5')
		{
			HLED_voidToggleLED(DIO_PORTA,PIN0);
		}
		_delay_ms(2000);
	}
}
