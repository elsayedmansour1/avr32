/*
 * confrim.c
 *
 *  Created on: Jul 22, 2020
 *      Author: elsay
 */

#include"STD_TYPES.h"
#include"BIT_Math.h"
#include "util/delay.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"UART_Interface.h"
#include"UART_Register.h"
#include"UART_Configuration.h"
#include"confirm.h"



u8 Correct_ID(u8 *ptr1,u8 *ptr2,u8 correct)
{
	u8  counter_right=0;
	u8  counter_right1=0;
	u8  counter_wrong=0;
	u8  counter_wrong1=0;
	u8  arr_size=0;
	u8 counter=0;
	for(u8 z=0;z<5;z++)
	{
		if(ptr1[z]==ptr2[z])
		{
			counter++;
		}
	}
	if(counter==5)
	{
				LCD_GoToXY(1, 0);
				LCD_VidWriteString("Correct ID");
				_delay_ms(1000);
				LCD_VidWriteCommend(1);                        //clear LCD
				counter_right=0;
				counter_wrong=0;
				arr_size=0;
				return correct;
		}

	return 0;
}
u8 Correct_PASSWORD(u8 *ptr1,u8 *ptr2,u8 correct)
{
	u8  counter_right=0;
	u8  counter_right1=0;
	u8  counter_wrong=0;
	u8  counter_wrong1=0;
	u8  arr_size=0;
	u8 counter=0;
	for(u8 z=0;z<5;z++)
	{
		if(ptr1[z]==ptr2[z])
		{
			counter++;
		}
	}
	if(counter==5)
	{
		LCD_GoToXY(1, 0);
		LCD_VidWriteString("Correct pass");
		_delay_ms(1000);
		LCD_VidWriteCommend(1);                        //clear LCD
		counter_right=0;
		counter_wrong=0;
		arr_size=0;
		return correct;
		}

	return 0;
}
void NOT_CORRECT(u8 counter_wrong)
{
	LCD_GoToXY(1, 4);
			LCD_VidWriteString("Incorrect ");
			_delay_ms(1000);
			LCD_GoToXY(1, 4);
			LCD_VidWriteString("Try Again");
			_delay_ms(1000);
			LCD_VidWriteCommend(1);                        //clear LCD
			if(counter_wrong ==3)
			{
				LCD_VidWriteCommend(1);                        //clear LCD
				while(1)
				{
					LCD_GoToXY(0, 2);
					LCD_VidWriteString("No more Tries");
					LCD_GoToXY(1, 2);
					LCD_VidWriteString("No more Tries");
				}
			}

}
