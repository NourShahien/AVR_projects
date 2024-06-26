/*
 * WDT_Program.c
 *
 *  Created on: Oct 25, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/WDT/WDT_Interface.h"
#include "../include/MCAL/WDT/WDT_Private.h"
#include "../include/MCAL/WDT/WDT_Cfg.h"


void MWDT_voidEnable(WDT_TIME_e A_TimeToReset)
{
	WDTCR = 0x00;
	WDTCR |= ((1 << 3) | (A_TimeToReset));
}
void MWDT_voidDisable(void)
{
	WDTCR |= ((1 << 3) | (1 << 4));
	WDTCR = 0x00;
}

