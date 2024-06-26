/*
 * 7seg.c
 *
 *  Created on: Sep 20, 2023
 *      Author: nours
 */

#include <avr/io.h>
#include <util/delay.h>
#include"../include/LIB/BIT_MATH.h"
#include"../include/LIB/STD_TYPES.h"

#define ZERO	0b01000000
#define ONE		0b01111001
#define TWO		0b00100100
#define THREE	0b00110000
#define FOUR	0b00011001
#define FIVE	0b00010010
#define SIX		0b00000010
#define SEVEN	0b01111000
#define EIGHT	0b00000000
#define NINE	0b00010000

#define F_CPU	8000000UL
/*int main(void)
{
	u8 ssd_u8arrofnumbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	DDRA = 0xFF;
	u8 i = 0;
	while(1)
	{
		for(i = 0;i<10;i++)
		{
			PORTA = ssd_u8arrofnumbers[i];
			_delay_ms(100);
		}
	}


}
*/
int main(void)
{
	u8 ssd_u8arrofnumbers[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	DDRA = 0xFF;
	DDRC = 0xFF;
	u8 i = 0;
	u8 j = 0;
	while(1)
	{
		for(i = 0;i<10;i++)
		{
			PORTA = ssd_u8arrofnumbers[i];
			for(j = 0;j<10;j++)
			{

				PORTC = ssd_u8arrofnumbers[j];
				_delay_ms(1000);
			}
		}
	}
}
