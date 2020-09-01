/*
 * LCD_Interface.h
 *
 *  Created on: Aug 21, 2020
 *      Author: ELSAYED
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_Interface.h"

/* LCD data length MODE select */
#define MODE 8

/* LCD HW Pins */
#define RS PIN0
#define RW PIN1
#define EN  PIN2
#define LCD_CTRL_PORT PORTB

/*LCD DATA PINS*/
//#define D4 PIN4
//#define D5 PIN5
//#define D6 PIN6
//#define D7 PIN7
#define LCD_DATA_PORT PORTD


 /* functions  */
void LCD_VidPulseEnable(void);

void LCD_VidInit(void);

void LCD_VidWriteCommend(u8 LOC_u8command);

void LCD_VidWriteData(u8 LOC_u8data);

void LCD_VidWriteString(u8 *ptr);

void LCD_VidWriteNumber(u32 LOC_u32num);

void LCD_GoToXY(u8 row,u8 col);

void LCD_CLEAR(u8 Row,u8 start,u8 end);

void LCD_CONSTANT(u8 *Arr,u8 Adress,u8 Row,u8 Col,u8 Data);


#endif /* LCD_INTERFACE_H_ */
