/*
 * WDT_Interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: nours
 */

#ifndef INCLUDE_MCAL_WDT_WDT_INTERFACE_H_
#define INCLUDE_MCAL_WDT_WDT_INTERFACE_H_


/* 000 16K (16,384) 17.1 ms 16.3 ms
   001 32K (32,768) 34.3 ms 32.5 ms
   010 64K (65,536) 68.5 ms 65 ms
   011 128K (131,072) 0.14 s 0.13 s
   100 256K (262,144) 0.27 s 0.26 s
   101 512K (524,288) 0.55 s 0.52 s
   110 1,024K (1,048,576) 1.1 s 1.0 s
   111 2,048K (2,097,152) 2.2 s 2.1 s
 *
 */
typedef enum{
	WDT_16_3_ms=0,
	WDT_32_5_ms,
	WDT_65_ms,
	WDT_0_13_s,
	WDT_0_26_s,
	WDT_0_52_s,
	WDT_1_s,
	WDT_2_1_s
}WDT_TIME_e;

void MWDT_voidEnable(WDT_TIME_e A_TimeToReset);
void MWDT_voidDisable(void);


#endif /* INCLUDE_MCAL_WDT_WDT_INTERFACE_H_ */
