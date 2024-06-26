/*
 * LCD_Cfg.h
 *
 *  Created on: Sep 26, 2023
 *      Author: nours
 */

#ifndef INCLUDE_HAL_LCD_CFG_H_
#define INCLUDE_HAL_LCD_CFG_H_


#define LCD_DATA_PORT	DIO_PORTD
#define LCD_CTRL_PORT	DIO_PORTC

#define LCD_RS_PIN	PIN0
#define LCD_RW_PIN	PIN1
#define LCD_E_PIN	PIN2

/*
 * 0-->	1 Line Display
 * 1-->	2 Line Display
 */
#define LCD_NO_OF_LINES	1

/*
 * 0-->	5 * 7
 * 1-->	5 * 10
 */
#define	LCD_CHAR_SIZE	0

/*
 * 0-->	OFF
 * 1-->	ON
 */
#define DISPLAY_STATUS	1

/*
 * 0-->	OFF
 * 1-->	ON
 */
#define CURSOR_DISPLAY	1

/*
 * 0-->	OFF
 * 1-->	ON
 */
#define CURSOR_BLINK	1

/*
 * 0-->	RIGHT TO LEFT
 * 1-->	LEFT TO RIGHT
 */
#define SHIFT_DIRECTION	1

/*
 *   0-->	OFF
 *   1-->	ON
 */
#define SHIFT_ENABLE	0



#endif /* INCLUDE_HAL_LCD_CFG_H_ */
