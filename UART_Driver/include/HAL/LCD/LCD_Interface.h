/*
 * LCD_Interface.h
 *
 *  Created on: Sep 26, 2023
 *      Author: nours
 */

#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_

typedef enum
{
	LCD_ROW1=1,
	LCD_ROW2,
}LCD_ROW_E;

typedef enum
{
	LCD_COL1=1,
	LCD_COL2,
	LCD_COL3,
	LCD_COL4,
	LCD_COL5,
	LCD_COL6,
	LCD_COL7,
	LCD_COL8,
	LCD_COL9,
	LCD_COL10,
	LCD_COL11,
	LCD_COL12,
	LCD_COL13,
	LCD_COL14,
	LCD_COL15,
	LCD_COL16,
}LCD_COL_E;

typedef enum
{
	LCD_PATTERN0=0,
	LCD_PATTERN1,
}LCD_PATTERN_E;



void HLCD_voidSendCommand(u8 A_u8Command);

void HLCD_voidSendData(u8 A_u8Data);

void HLCD_voidInit(void);

void HLCD_voidClearDisplay(void);

void HLCD_DisplayString(u8 *A_u8PtrToString);

void HLCD_GoToPos(LCD_ROW_E A_LCDRow,LCD_COL_E A_LCDCol);

void HLCD_voidDisplayNumber(u32 A_u32Number);

void HLCD_SendSpecialSymbol(u8 *A_pu8SSymbolArray,LCD_PATTERN_E A_PatternNum,LCD_ROW_E A_RowNo,LCD_COL_E A_ColNo);



#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
