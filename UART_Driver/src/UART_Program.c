/*
 * UART_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/UART/UART_Private.h"
#include "../include/MCAL/UART/UART_Cfg.h"

#define F_CPU 8000000UL
#define NULL 0


void MUART_voidInit(void)
{
	u16 local_u16BaudRate = BAUD_RATE_EQUATION;
	//Set Baudrate
	UBRRL = (u8) local_u16BaudRate;
	UBRRH = ((u8) local_u16BaudRate >> 8);

	//Character Size 8-Bit
	CLR_BIT(UCSRB,2);
	//Character Size 8-Bit
	// Mode Asynchronous operation
	// Parity Disabled
	// 1 Stop Bit
	CONC_BIT(1,0,0,0,0,1,1,0);

	//TX Enable
	//RX Enable
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}

void MUART_voidSendByteSyncBlocking(u8 A_u8DataByte)
{
	//Wait Until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0);

	//Send Data into TX Register and Start Transmission
	UDR = A_u8DataByte;

	//Wait Until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0);

	//Clear Transmit Interrupt Flag
	SET_BIT(UCSRA,6);
}

void MUART_voidSendByteSyncNonBlocking(u8 A_u8DataByte)
{
	u32 local_u32TimeOut = 0;
	//Wait Until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0)
	{
		local_u32TimeOut++;
		if(local_u32TimeOut == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}
	if(local_u32TimeOut != NON_BLOCKING_TIME_OUT)
	{
		local_u32TimeOut = 0;
		//Send Data into TX Register and Start Transmission
		UDR = A_u8DataByte;

		//Wait Until UDR is Empty
		while(GET_BIT(UCSRA,5) == 0)
		{
			local_u32TimeOut++;
			if(local_u32TimeOut == NON_BLOCKING_TIME_OUT)
			{
				break;
			}
		}
	}
	//Clear Transmit Interrupt Flag
	SET_BIT(UCSRA,6);
}

void MUART_voidSendStringSyncNonBlocking(u8 *A_pu8String)
{
	while(*A_pu8String > 0)
	{
		MUART_voidSendByteSyncNonBlocking(*A_pu8String++);
	}
}

void MUART_voidSendByteAsync(u8 A_u8DataByte)
{
	//Check if Data Register is Empty
	if(GET_BIT(UCSRA,5) == 1)
	{
		//Send Data
		UDR = A_u8DataByte;
	}
}

u8 MUART_u8ReadByteSyncBlocking(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}

u8 MUART_u8ReadByteAsync(void)
{
	return UDR;
}

u8 MUART_u8ReadByteSyncNonBlocking(void)
{
	u8 local_u8ReceivedData = NO_VALUE_RETURNED;
	u16 local_u16TimeOut = 0;
	while(GET_BIT(UCSRA,7) == 0)
	{
		local_u16TimeOut++;
		if(local_u16TimeOut == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
		if(local_u16TimeOut != NON_BLOCKING_TIME_OUT)
		{
			//Read Received Data From UDR
			local_u8ReceivedData = UDR;
		}
		return local_u8ReceivedData;
	}
}

