/*
 * LCD_Program.c
 *
 *  Created on: Sep 26, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"

#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LCD/LCD_Interface.h"

#include "../include/HAL/LCD/LCD_Private.h"

#include "../include/HAL/LCD/LCD_Cfg.h"

#include <util/delay.h>

#define F_CPU	8000000UL

void HLCD_voidSendCommand(u8 A_u8Command)
 {
	 //To Send Command	(RS-->0,RW-->0)
	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_RESET);
	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);

	 //Send Command
	 MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	 //Set Pulse On E Pin
	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	 _delay_ms(2);
	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);


 }

void HLCD_voidSendData(u8 A_u8Data)
 {
	     //To Send Data(RS-->1,RW-->0)
	 	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_SET);
	 	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);

	 	 //Send Data
	 	 MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

	 	 //Set Pulse On E Pin
	 	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	 	 _delay_ms(2);
	 	 MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);


 }

void HLCD_voidInit(void)
{
	//Wait For more than 30ms after VDD rises to 4.5v
	_delay_ms(30);

	//Function Set then wait 39	Ms
	HLCD_voidSendCommand(FUNCTION_SET);
	_delay_ms(1);

	//Display On/Off Control The wait 39 Ms
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);

	//Display Clear Then wait 2 ms
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);

	//Entry Mode Set Then wait 39 Ms
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	_delay_ms(1);


}

void HLCD_voidClearDisplay(void)
{
	//Display Clear Then wait 2 ms
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);

}

void HLCD_DisplayString(u8 *A_u8PtrToString)
{
	while(*A_u8PtrToString > 0)
	{
		HLCD_voidSendData(*A_u8PtrToString++);
	}
}


void HLCD_GoToPos(LCD_ROW_E A_LCDRow,LCD_COL_E A_LCDCol)
{
	switch(A_LCDRow)
	{
	case LCD_ROW1:
		HLCD_voidSendCommand(ROW1_BASE_ADD + A_LCDCol);
		break;
	case LCD_ROW2:
		HLCD_voidSendCommand(ROW2_BASE_ADD + A_LCDCol);
		break;

	}
}

void HLCD_voidDisplayNumber (u32 A_u32Number)
{
	u32 local_u32Num = 1;
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}

	while (A_u32Number != 0)
	{
		local_u32Num = (local_u32Num * 10) + (A_u32Number % 10);
		A_u32Number = A_u32Number / 10;
	}
	while (local_u32Num != 1)
	{
		HLCD_voidSendData ((local_u32Num % 10) + 48);
		local_u32Num = local_u32Num / 10;
	}
}


void HLCD_SendSpecialSymbol(u8 *A_pu8SSymbolArray,LCD_PATTERN_E A_PatternNum,LCD_ROW_E A_RowNo,LCD_COL_E A_ColNo)
{
	u8 local_u8CGRAMAdsress;
	//Calculate CGRAM Address
	local_u8CGRAMAdsress = A_PatternNum * 8;
	SET_BIT(local_u8CGRAMAdsress,6);
	//Send Set CGRAM Address Command
	HLCD_voidSendCommand(local_u8CGRAMAdsress);

	for(u8 local_u8Counter = 0; local_u8Counter<8; local_u8Counter++)
	{
		//Send Byte by Byte From Symbol Array
		HLCD_voidSendData(A_pu8SSymbolArray[local_u8Counter]);

	}
	//Send Command To set DDRAM Address
	HLCD_GoToPos(A_RowNo,A_ColNo);
	//Display Pattern
	HLCD_voidSendData(A_PatternNum);

}




