/*
 * SPI_Program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/SPI/SPI_Interface.h"
#include "../include/MCAL/SPI/SPI_Private.h"
#include "../include/MCAL/SPI/SPI_Cfg.h"


void MSPI_voidInit(void)
{
	//Data Order = MSB First
	//Choose CPOL and CPHA => Falling / Rising, Setup, Sample
	CLR_BIT(SPCR,5);
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
    #if(SPI_MODE == SPI_MASTER_MODE)
	//Select Master Mode
	//Select CLK => Fosc/64
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	#elif(SPI_MODE == SPI_SLAVE_MODE)
	//Select Slave Mode
	CLR_BIT(SPCR,4);
	#endif
	//Enable SPI
	SET_BIT(SPCR,6);
}


u8 MSPI_u8TransReceive(u8 A_u8Data)
{
	//Set Data To be Sent into Data Register
	SPDR = A_u8Data;
	//Wait Until Data Transmission End
	while(GET_BIT(SPSR,7) == 0);
	//Return Data Received
	return SPDR;
}
