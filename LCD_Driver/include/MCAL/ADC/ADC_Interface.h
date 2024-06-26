/*
 * ADC_Interface.h
 *
 *  Created on: Oct 12, 2023
 *      Author: nours
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_


typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7

}ADC_CHANNELS;

void MADC_voidInit(void);
u16 MADC_u16GetDigitalValue(ADC_CHANNELS A_AdcChannel);




#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
