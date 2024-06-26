/*
 * ADC_Program.c
 *
 *  Created on: Oct 12, 2023
 *      Author: nours
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include "../include/MCAL/ADC/ADC_Private.h"
#include "../include/MCAL/ADC/ADC_Cfg.h"


void MADC_voidInit(void)
{
	//Select AVCC With External Capacitor At AREF Pin
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//Right Adjustment
	CLR_BIT(ADMUX,5);

	//Disable Auto Trigger
	CLR_BIT(ADCSRA,5);

	//Select Clk/64
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,0);

	//Enable ADC
	SET_BIT(ADCSRA,7);

}

u16 MADC_u16GetDigitalValue(ADC_CHANNELS A_AdcChannel)
{
	u16 local_u16DigitalValue = 0;
	if(A_AdcChannel < 32)
	{
		//Clear The Channel 5-Bits
		ADMUX &= ADC_CHANNEL_MASK;
		/*CLR_BIT(ADMUX,4);
		CLR_BIT(ADMUX,3);
		CLR_BIT(ADMUX,2);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,0);*/

		//Select Channel
		ADMUX |= A_AdcChannel;
		/*switch(A_AdcChannel)
		{
		case ADC0:
			break;
		case ADC1:
			SET_BIT(ADMUX,0);
			break;
		case ADC2:
			SET_BIT(ADMUX,1);
			break;
		case ADC3:
			SET_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			break;
		case ADC4:
			SET_BIT(ADMUX,2);
			break;
		case ADC5:
			SET_BIT(ADMUX,0);
			SET_BIT(ADMUX,2);
			break;
		case ADC6:
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			break;
		case ADC7:
			SET_BIT(ADMUX,0);
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,2);
			break;

		}*/
		//Start Conversion
		SET_BIT(ADCSRA,6);

		//Polling On ADC Complete Flag
		while(GET_BIT(ADCSRA,4) == 0);

		//Clear INt Flag
		SET_BIT(ADCSRA,4);

		//Read Conversion Value
		local_u16DigitalValue = ADCLH;

	}
	//Return Result Of Conversion
	return local_u16DigitalValue;
}



