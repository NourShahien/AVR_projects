/*
 * App_3.c
 *
 *  Created on: Oct 12, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include<util/delay.h>


#define F_CPU 8000000UL

/*void main(void)
{
	//PA0-->I/P Floating ,(PC0,PC1,PC2) -->O/P Low
	MDIO_voidInit();
	MADC_voidInit();
	u16 local_u16DigitalValue, local_u16AnalogValue;
	while(1)
	{
		local_u16DigitalValue = MADC_u16GetDigitalValue(ADC0);
		local_u16AnalogValue = (local_u16DigitalValue * 5000UL) / 1024;// Read in mv
		if(local_u16AnalogValue < 1500)
		{
			HLED_voidTurnLEDOn(DIO_PORTC,PIN0);
			HLED_voidTurnLEDOff(DIO_PORTC,PIN1);
			HLED_voidTurnLEDOff(DIO_PORTC,PIN2);
		}
		else if(local_u16AnalogValue < 3000)
		{
			HLED_voidTurnLEDOn(DIO_PORTC,PIN0);
			HLED_voidTurnLEDOn(DIO_PORTC,PIN1);
			HLED_voidTurnLEDOff(DIO_PORTC,PIN2);
		}
		else if(local_u16AnalogValue > 3000)
		{
			HLED_voidTurnLEDOn(DIO_PORTC,PIN0);
			HLED_voidTurnLEDOn(DIO_PORTC,PIN1);
			HLED_voidTurnLEDOn(DIO_PORTC,PIN2);

		}

	}
}*/


void main(void)
{
	//PA0-->I/P Floating ,(PC0,PC1,PC2) -->O/P Low
	MDIO_voidInit();
	MADC_voidInit();
	HLCD_voidInit();
	u16 local_u16DigitalValue, local_u16AnalogValue;
	while(1)
	{
		local_u16DigitalValue = MADC_u16GetDigitalValue(ADC0);
		local_u16AnalogValue = (local_u16DigitalValue * 500UL) / 1024;// Read in mv

		HLCD_voidClearDisplay();
		HLCD_DisplayString("Temperature: ");
		HLCD_voidDisplayNumber(local_u16AnalogValue);
		_delay_ms(5000);
	}
}

