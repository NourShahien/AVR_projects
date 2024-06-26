/*
 * App_7.c
 *
 *  Created on: Oct 14, 2023
 *      Author: nours
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/WDT/WDT_Interface.h"


#include<util/delay.h>


#define F_CPU 8000000UL



void ICU_SW(void);
u16 global_u16PeriodTicks;
u16 global_u16OnTicks;


/* Timer 0 --> Generate PWM On PB3 --> O/P low
 * EXTI  0 --> Read The PWM On PD2 --> I/P Floating
 * LCD Data Port --> Port C --> O/P Low
 * LCD Control Port --> Port D 3,4,5 --> O/P Low
 */

void main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	MEXTI_voidSetCallBack(EXTI0,ICU_SW);
	MEXTI_voidConfig(EXTI0,RISING_EDGE);
	MEXTI_voidEnable(EXTI0);
	MGI_voidEnable();
	MTIMER0_voidInit();
	MTIMER1_voidICUSWInit();

	while(1)
	{
		while((global_u16PeriodTicks == 0) || (global_u16OnTicks == 0));
		HLCD_GoToPos(LCD_ROW1,LCD_COL1);
		HLCD_DisplayString("--> ");
		HLCD_voidDisplayNumber(global_u16PeriodTicks);
		HLCD_GoToPos(LCD_ROW2,LCD_COL1);
		HLCD_DisplayString("--> ");
		HLCD_voidDisplayNumber(global_u16OnTicks);

	}

	}



void ICU_SW(void)
{
	static u8 local_u8Counter = 0;
	local_u8Counter++;
	if(local_u8Counter == 1)
	{
		//First Rising Edge
		MTIMER1_voidSetTimerValue(0);
	}
	else if(local_u8Counter == 2)
	{
		//Second Rising Edge
		global_u16PeriodTicks = MTIMER1_u16ReadTimerValue();
		MEXTI_voidConfig(EXTI0,FALLING_EDGE);
	}
	else if(local_u8Counter == 3)
	{
		global_u16OnTicks = MTIMER1_u16ReadTimerValue();
		global_u16OnTicks -= global_u16PeriodTicks;
		MEXTI_voidDisable(EXTI0);
		local_u8Counter = 0;
	}
}


/*void main(void)
{
	MDIO_voidInit();
	_delay_ms(2000);
	HLED_voidTurnLEDOn(DIO_PORTA,PIN0);
	MWDT_voidEnable(WDT_2_1_s);
	while(1)
	{

	}
}*/
