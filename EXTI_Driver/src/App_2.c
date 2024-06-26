/*

 * App_2.c
 *
 *  Created on: Oct 7, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include <util/delay.h>
#define F_CPU	8000000UL

void FUNC(void)
{
	HLED_voidToggleLED(DIO_PORTA,PIN0);
}

void main(void)
{
	MDIO_voidInit();
	MEXTI_voidConfig(EXTI0,FALLING_EDGE);
	MEXTI_voidSetCallBack(EXTI0,FUNC);
	MEXTI_voidEnable(EXTI0);
	MGI_voidEnable();

	while(1)
	{

	}
}

