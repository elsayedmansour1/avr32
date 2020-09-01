#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
              /*PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
              /*DIRECTION*/
#define OUTPUT 1
#define INPUT  0
				/*VLAUE*/
#define HIGH 1
#define LOW  0
              /*PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

void DIO_VidSetPinDirection(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8State);
/*comment*/
void DIO_VidSetPinValue(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8Value);
/*comment*/
void DIO_VidSetPortDirection(u8 LOC_u8Port,u8 LOC_u8Value);
/*comment*/
void DIO_VidSetPortValue(u8 LOC_u8Port,u8 LOC_u8Value);
/*comment*/
u8 DIO_u8GitPinValue(u8 LOC_u8Port,u8 LOC_u8Pin);
/*comment*/










#endif
