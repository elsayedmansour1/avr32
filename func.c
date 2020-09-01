/*
 * func.c
 *
 *  Created on: Jul 25, 2020
 *      Author: elsay
 */
#include"STD_TYPES.h"
#include"BIT_Math.h"
#include "util/delay.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"func.h"


void SYSTEM_LOADING(void)
{
	LCD_GoToXY(0,0);
	LCD_VidWriteString("SYSTEM_LOADING");
	LCD_GoToXY(1,0);
	for(u8 x=0;x<15;x++)
	{
		LCD_VidWriteData('>');
		_delay_ms(100);
	}

}
void StartScreen(void)
{
    LCD_GoToXY(0,1);
	LCD_VidWriteString("1-LM-35");
	LCD_GoToXY(0,11);
	LCD_VidWriteString("2-LDR");
	LCD_GoToXY(1,1);
	LCD_VidWriteString("3-DC_MOTOR");
}
void Controll(u8 data,u8*ptr1)
{
	 u8 customChar[] = {0x10,0x18,0x1C,0x1E,0x1C,0x18,0x10,0x00};



		if(data=='l')   																//                //
		{                                                                               //
			LCD_CLEAR( 1,  0,  1);
			LCD_CLEAR( 0, 10, 11);
			LCD_CONSTANT(customChar, 8, 0, 0, 1);
			*ptr1=1;
		}
		else if(data=='r')
		{
			LCD_CLEAR( 1, 0, 1);
			LCD_CLEAR( 0, 0, 1);
			LCD_CONSTANT(customChar, 8, 0, 10, 1);
			*ptr1=2;
		}
		else if(data=='d')
		{
			LCD_CLEAR( 0,  0,  1);
			LCD_CLEAR( 0, 10, 11);
			LCD_CONSTANT(customChar, 8, 1, 0, 1);
			*ptr1=3;
		}




}
 void Controll2(u8 data,u8*ptr2)
{

	if(data=='e')
	{
		*ptr2=1;
	}

}
