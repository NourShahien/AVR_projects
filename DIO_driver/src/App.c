/*
 * App.c
 *
 *  Created on: Sep 21, 2023
 *      Author: nours
 */


#include<util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#define F_CPU	8000000UL


void main(void)
{
MDIO_voidSetPortDirection(DIO_PORTA,0x0F);

	while(1)
	{
		//step1
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);
		//Step2
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);

		//Step3
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);

		//Step4
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_RESET);
		_delay_ms(10);



	}
}
