#ifndef _EXIT_INTERFACE_H_
#define _EXIT_INTERFACE_H_



#define ISR_ADC()  void __vector_16(void)__attribute__((signal));\
	                     void __vector_16(void)

     /*TAKE YOUR MOOD FROM HER*/
   

/* ADC Multiplexer Selection Register â€“ ADMUX*/

#define REFS1  7  //Reference Selection Bits
#define REFS0  6  //Reference Selection Bits
#define ADLAR  5  //ADC Left Adjust Result
#define MUX4   4  //Analog Channel and Gain Selection Bits
#define MUX3   3  //Analog Channel and Gain Selection Bits
#define MUX2   2  //Analog Channel and Gain Selection Bits
#define MUX1   1  //Analog Channel and Gain Selection Bits
#define MUX0   0  //Analog Channel and Gain Selection Bits

/* ADC Control and Status Register A â€“ ADCSRA*/

#define ADEN   7   //ADC Enable
#define ADSC   6   //ADC Start Conversion
#define ADATE  5   //ADC Auto Trigger Enable
#define ADIF   4   //Interrupt Flag
#define ADIE   3   //Interrupt Enable
#define ADPS2  2   //ADC Prescaler2
#define ADPS1  1   //ADC Prescaler1
#define ADPS0  0   //ADC Prescaler0

#define ADC0    0    //PARTA PIN0
#define ADC1    1    //PARTA PIN1
#define ADC2    2    //PARTA PIN2
#define ADC3    3    //PARTA PIN3
#define ADC4    4    //PARTA PIN4
#define ADC5    5    //PARTA PIN5
#define ADC6    6    //PARTA PIN6
#define ADC7    7    //PARTA PIN7

       /**/
#define SingleConversionMode             0
#define Free_Running_Mode                1
#define Analog_Comparator                2
#define External_Interrupt_Request0      3
#define Timer_Counter0_Compare_Match     4
#define Timer_Counter0_Overflow          5
#define Timer_Counter_Compare_Match_B    6
#define Timer_Counter1_Overflow          7
#define Timer_Counter1_Capture_Event     8


     /*TAKE YOUR MOOD FROM HER*/
/*
#define LOC_U8SpecialFunction  SingleConversionMode
#define LOC_U8SpecialFunction  Free_Running_Mode
#define LOC_U8Special Function  Analog_Comparator
#define LOC_U8SpecialFunction  External_Interrupt_Request0
#define LOC_U8SpecialFunction  Timer_Counter0_Compare_Match
#define LOC_U8SpecialFunction  Timer_Counter0_Overflow
#define LOC_U8SpecialFunction  Timer_Counter_Compare_Match_B
#define LOC_U8SpecialFunction  Timer_Counter1_Overflow
#define LOC_U8SpecialFunction  Timer_Counter1_Capture_Event
*/
#define LOC_U8SpecialFunction  Free_Running_Mode


#define POLLING 0
#define INTERRUPT 1

#define ADTS0                            7
#define ADTS1                            6
#define ADTS2                            5




void ADC_INIT(void);

void StartConversion(void);

u16 ADC_GET_RESULT(void);

void ADC_SELECT_CHANNAL(u8 LOC_U8Channal);

void ADC_CHECKMODE(u8 LOC_U8Type);

void ADC_SetCallBack(void (*LocalPFunc)(void));


void Interrupt_Disable(void);














#endif
