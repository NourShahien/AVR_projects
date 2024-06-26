/*
 * TIMERS_Program.c
 *
 *  Created on: Oct 14, 2023
 *      Author: nours
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Private.h"
#include "../include/MCAL/TIMERS/TIMERS_Cfg.h"

#define NULL	0
void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;


void MTIMER0_voidInit(void)
{

	#if TIMER0_MODE == NORMAL_MODE
	// Set Wave Generation To Normal Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//Enable OVF Interrupt, And Disable CTC Interrupt
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);

	//Start Timer By Setting Its CLK
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= TIMER0_CLK;

	#elif TIMER0_MODE == PHASE_CORRECT_MODE
	#elif TIMER0_MODE == CTC_MODE
	// Set Wave Generation To CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	//Disable OVF Interrupt, And ENable CTC Interrupt
	SET_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);

	//Set Compare Match Value
	OCR0 = OCR0_VALUE;

	//Start Timer By Setting Its CLK And Also Set OC0 Pin Mode
	TCCR0 &= TIMER0_CLK_OCR_MASK;
	TCCR0 |= (TIMER0_CLK | (OCR0_MODE << 4));

	#elif TIMER0_MODE == FAST_PWM_MODE
	// Set Wave Generation To CTC Mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	//Disable All Timers Interrupt
	CLR_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);

	//Set OCR0 Value
	OCR0 = OCR0_VALUE;

	//Set OC0 Cfg
	//Start Timer By Setting Its CLK
	TCCR0 &= TIMER0_CLK_OCR_MASK;
	TCCR0 |= (TIMER0_CLK | (OCR0_MODE << 4));


	#endif


}

void MTIMER0_voidSetPreLoadValue(u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidStopTimer(void)
{
	TCCR0 &= TIMER0_CLK_MASK;
}

void MTIMER0_voidSetOCR0Value(u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}

void MTIMER0_voidSetOVFCallBack(void (*A_PtrToFunc)(void))
{
	if(A_PtrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}


void MTIMER0_voidSetCTCCallBack(void (*A_PtrToFunc)(void))
{
	if(A_PtrToFunc != NULL)
		{
			TIMER0_CTC_CALLBACK = A_PtrToFunc;
		}
}



void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}


void MTIMER1_voidInit()
{
	//Select Timer Mode --> 14
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	CLR_BIT(TCCR1A,0);
	//Non-Inverting Mode For OC1A
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
	//ICR1 --> 19999
	ICR1 = 19999;
	//OCR1 --> 1000
	OCR1A = 1500;
	//Start Timer By Setting Its CLK
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,2);

}

void MTIMER1_voidSetOCR1AValue(u16 A_u16Value)
{
	OCR1A = A_u16Value;
}


void MTIMER1_voidICUSWInit()
{
	//Start Timer By Setting Its CLK
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,2);
}

void MTIMER1_voidSetTimerValue(u16 A_u16Value)
{
	TCNT1 = A_u16Value;
}

u16 MTIMER1_u16ReadTimerValue(void)
{
	return TCNT1;
}

