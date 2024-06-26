/*
 * LED_Program.c

 *
 *  Created on: Sep 25, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LED/LED_Interface.h"
#include "../include/HAL/LED/LED_Private.h"
#include "../include/HAL/LED/LED_Cfg.h"

void HLED_voidTurnLEDOn(DIO_PORT_e A_portID,DIO_PIN_e A_pinID)
{
	MDIO_voidSetPinValue(A_portID,A_pinID,DIO_SET);

}


void HLED_voidTurnLEDOff(DIO_PORT_e A_portID,DIO_PIN_e A_pinID)
{
	MDIO_voidSetPinValue(A_portID,A_pinID,DIO_RESET);
}


void HLED_voidToggleLED(DIO_PORT_e A_portID,DIO_PIN_e A_pinID)
{
	MDIO_voidTogglePinValue(A_portID,A_pinID);
}




