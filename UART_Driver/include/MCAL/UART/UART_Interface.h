/*
 * UART_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: nours
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

void MUART_voidInit(void);
void MUART_voidSendByteSyncNonBlocking(u8 A_u8DataByte);
void MUART_voidSendStringSyncNonBlocking(u8 *A_pu8String);
void MUART_voidSendByteAsync(u8 A_u8DataByte);
u8 MUART_u8ReadByteSyncBlocking(void);
u8 MUART_u8ReadByteAsync(void);
u8 MUART_u8ReadByteSyncNonBlocking(void);







#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
