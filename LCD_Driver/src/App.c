/*
 * App.c
 *
 *  Created on: Sep 21, 2023
 *      Author: nours
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include<util/delay.h>
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#define F_CPU	8000000UL


/*void main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();

	u8 local_u8KeyPadValue;
	u8 local_u8CharCounter = 0;


	while(1)
	{
		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
		if(local_u8KeyPadValue != 255)
		{
			HLCD_voidSendData(local_u8KeyPadValue);
			local_u8CharCounter++;

		if(local_u8CharCounter == 16)
		{
			HLCD_GoToPos(LCD_ROW2,LCD_COL1);
		}
		else if(local_u8CharCounter == 32)
		{
			HLCD_voidClearDisplay();
			HLCD_GoToPos(LCD_ROW1,LCD_COL1);
			local_u8CharCounter = 0;
		}

	}
 }
}*/
/*void main(void)
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
}*/
void main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HLCD_DisplayString("Abdelrahman");
	while(1)
	{



	}
}


/*void main(void)
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
}*/

