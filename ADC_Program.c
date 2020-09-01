#include "STD_TYPES.h"
#include "BIT_Math.h"
#include"ADC_Register.h"
#include"ADC_Interface.h"
#include"DIO_Interface.h"

/*GLOBAL POINTER TO FUNCTION*/

static void (*GPFunc)(void)=NULL;
void ADC_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc=LocalPFunc;
}
ISR_ADC()
{
	if(GPFunc!=NULL)
	{
		GPFunc();
	}
}

void ADC_INIT(void)
{
	 CLR_BIT(ADMUX, REFS1);//Reference Selection Bits
	 SET_BIT(ADMUX, REFS0);//Reference Selection Bits
	 CLR_BIT(ADMUX, ADLAR);//ADC Right Adjust Result
	 SET_BIT(ADCSRA, ADEN);//ADC Enable
	 CLR_BIT(ADCSRA,ADPS0); //ADC Prescaler0
	 SET_BIT(ADCSRA,ADPS1); //ADC Prescaler1
	 SET_BIT(ADCSRA,ADPS2); //ADC Prescaler2

}

void StartConversion(void)
{
	SET_BIT(ADCSRA, ADSC);//ADC Start Conversion
}
void ADC_SELECT_CHANNAL(u8 LOC_U8Channal)
{
	ADMUX=ADMUX&0b11100000;    //CLEAR ADMUX
	ADMUX=ADMUX|LOC_U8Channal; //SET CHANNEL
}
u16 ADC_GET_RESULT(void)
{

		#if LOC_U8SpecialFunction==SingleConversionMode
		 CLR_BIT(ADCSRA, ADATE);
		 StartConversion();
		#elif LOC_U8SpecialFunction==Free_Running_Mode
		 //StartConversion();
		SET_BIT(ADCSRA, ADATE); //AutoTriggerEnable
		     /*FREE RUNNING MODE*/
		CLR_BIT(SFIOR, ADTS0);
		CLR_BIT(SFIOR, ADTS1);
		CLR_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Analog_Comparator
		SET_BIT(ADCSRA, ADATE);
		SET_BIT(SFIOR, ADTS0);
		CLR_BIT(SFIOR, ADTS1);
		CLR_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==External_Interrupt_Request0
		SET_BIT(ADCSRA, ADATE);
		CLR_BIT(SFIOR, ADTS0);
		SET_BIT(SFIOR, ADTS1);
		CLR_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Timer_Counter0_Compare_Match
		SET_BIT(ADCSRA, ADATE);
		SET_BIT(SFIOR, ADTS0);
		SET_BIT(SFIOR, ADTS1);
		CLR_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Timer_Counter0_Overflow
		SET_BIT(ADCSRA, ADATE);
		CLR_BIT(SFIOR, ADTS0);
		CLR_BIT(SFIOR, ADTS1);
		SET_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Timer_Counter_Compare_Match_B
		SET_BIT(ADCSRA, ADATE);
		SET_BIT(SFIOR, ADTS0);
		CLR_BIT(SFIOR, ADTS1);
		SET_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Timer_Counter1_Overflow
		SET_BIT(ADCSRA, ADATE);
		CLR_BIT(SFIOR, ADTS0);
		SET_BIT(SFIOR, ADTS1);
		SET_BIT(SFIOR, ADTS2);
		#elif LOC_U8SpecialFunction==Timer_Counter1_Capture_Event
		SET_BIT(ADCSRA, ADATE);
		SET_BIT(SFIOR, ADTS0);
		SET_BIT(SFIOR, ADTS1);
		SET_BIT(SFIOR, ADTS2);
		#else
		#error "WRONG CHOOSE OF SENCE MOOD"
		#endif
	 return ADC;
}
void ADC_CHECKMODE(u8 LOC_U8Type)
{
	if(LOC_U8Type==POLLING)
	 {
	   while(GET_BIT(ADCSRA,ADIF)==0){}

	  SET_BIT(ADCSRA, ADIF); //CLEAR ADC FLAG
	 }
	else if(LOC_U8Type==INTERRUPT)
	{
	  SET_BIT(ADCSRA, ADIE);
	}
}
void Interrupt_Disable(void)
{
	 CLR_BIT(ADCSRA, ADIE);
}
