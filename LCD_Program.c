#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "util/delay.h"
#include"DIO_Interface.h"
#include "LCD_Interface.h"

void LCD_VidPulseEnable(void)
{
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */
	_delay_ms(1);
}
void LCD_VidInit(void)
{
	_delay_ms(50);
#if MODE==4
	DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);  /* Configure the control pins(E,RS,RW) as output pins */
	_delay_ms(1);


		// set only PORT 4~7 pins as outputs
		DIO_VidSetPortDirection(LCD_DATA_PORT,0xF0);  /* Configure the data port as output port */

		/* FUNCTION SET */
		//send 0010 twice with delay in between
		LCD_VidWriteCommend(0x02);

		//send N,F flags
		LCD_VidWriteCommend(0x28);
		//_delay_ms(1);
		/* END OF FUNCTION SET */


		/* DISPLAY ON/OFF */
		//send 0000 once with a delay, then send 1(D)(C)(B) flags
		LCD_VidWriteCommend(0x0c);
		_delay_ms(1);
		/* END OF DISPLAY ON/OFF*/



		/* ENTRY MODE SET*/
		LCD_VidWriteCommend(0x06);
		_delay_ms(1);
		/* END OF ENTRY MODE SET*/

		LCD_VidWriteCommend(0x80);

		/* DISPLAY CLEAR */
		LCD_VidWriteCommend(0x01);
		_delay_ms(2);
		/* END OF DISPLAY CLEAR */

#elif MODE==8
	  /*set direction*/
		DIO_VidSetPortDirection(LCD_DATA_PORT,0XFF);
		DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);

	LCD_VidWriteCommend(0x56);//function set
	_delay_ms(1);
	LCD_VidWriteCommend(0x12);//screen on
          _delay_ms(1);
	LCD_VidWriteCommend(0x01);//clear display
          _delay_ms(2);
	LCD_VidWriteCommend(0x06);//Mode Set
	LCD_VidWriteCommend(0x02);//Return Home
	LCD_VidWriteCommend(0x01);
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void LCD_VidWriteCommend(u8 LCD_u8Commend)
{
#if MODE==4
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,0); /* Instruction Mode RS=0 */
		DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		LCD_VidPulseEnable();

		//send LEAST SIGNIFICANT 4-bits
		DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend<<4); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		LCD_VidPulseEnable();	
#elif MODE==8
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN0,0);  //RS=0
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN1,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend); //write commend

	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN2,1);  //EN=1
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN2,0);  //EN=0

	_delay_ms(1);     //wait lcd to write letter
#else
#error "WRONG CHOOSE THE MODE"
#endif


}
void LCD_VidWriteData(u8 LCD_u8Data)
{
#if MODE==4
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1); /* Instruction Mode RS=0 */
		DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		LCD_VidPulseEnable();

		//send LEAST SIGNIFICANT 4-bits
		DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data<<4); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		LCD_VidPulseEnable();
#elif MODE==8
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1);  //RS=0
	DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data); //write commend

	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0

	_delay_ms(1);     //wait lcd to write letter
#else
#error "WRONG CHOOSE THE MODE"
#endif

}


void LCD_VidWriteString(u8 *ptr)
{
	for(u8 i=0;i<100;i++)
	{
		if(ptr[i]=='\0')
		    {
		    	break;
		    }
	LCD_VidWriteData(ptr[i]);

	}

}

void LCD_VidWriteNumber(u32 LOC_u32num)
{ 	u32 revrese=0;
u8 y;
u8 counter=0;
if(LOC_u32num==0)
{
	LCD_VidWriteData(48);
}
while(LOC_u32num>0)
{
	revrese=(revrese*10)+(LOC_u32num)%10;
	if(revrese==0)
	{
		 y=0;
		 counter++;
	}
	LOC_u32num=LOC_u32num/10;
}
while(revrese>0)
{
	u8 res=revrese%10;
	LCD_VidWriteData(res+48);
	revrese=revrese/10;
}
if(y==0)
{
	for(u8 i=0;i<counter;i++)
	{
LCD_VidWriteData(48);
	}
}
}

void LCD_GoToXY(u8 row,u8 col)
{
	if(row==0)
	{
		LCD_VidWriteCommend(128+col);
	}
	else if (row==1)
	{
		LCD_VidWriteCommend(192+col);
	}
}

void LCD_CONSTANT(u8 *Arr,u8 Adress,u8 Row,u8 Col,u8 Data)
{
//	LCD_VidWriteCommend(1);
	LCD_VidWriteCommend(Adress+64);
		/*for face*/
for(u8 i=0;i<8;i++)
	{
	LCD_VidWriteData(Arr[i]);
	}

LCD_GoToXY(Row,Col);
LCD_VidWriteData(Data);
}
void LCD_CLEAR(u8 Row,u8 start,u8 end)
{
	u8 empty[8]={0,0,0,0,0,0,0,0};
	while(1)
	{
		LCD_CONSTANT(empty,0,Row,start,0);
		  start++;
		  if(start==end)
		  {
			  break;
		  }
	}


}


