/*
 * DIO_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: user
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"
#include "DIO_private.h"

void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir){

	if(Copy_u8Dir==DIO_u8INPUT){
		switch(Copy_u8Port)
		{

			case DIO_u8PORTA :ClR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8PORTB :ClR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8PORTC :ClR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8PORTD :ClR_BIT(DDRD,Copy_u8Pin); break;
		}
	}
	else if(Copy_u8Dir==DIO_u8OUTPUT){
		switch(Copy_u8Port){

			case DIO_u8PORTA: SET_BIT(DDRA , Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(DDRB,Copy_u8Pin);
			break;
			case DIO_u8PORTC: SET_BIT(DDRC,Copy_u8Pin);
			break;
			case DIO_u8PORTD: SET_BIT(DDRD,Copy_u8Pin);
			break;
		}
	}

}
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	if(Copy_u8Value==DIO_u8HIGH){
		switch(Copy_u8Port){
			case DIO_u8PORTA:SET_BIT(PORTA,Copy_u8Pin);
			break;
			case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);
			break;
			case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);
			break;
			case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin); break;
		}
	}
	else if(Copy_u8Value==DIO_u8LOW){
		switch(Copy_u8Port){
			case DIO_u8PORTA:ClR_BIT(PORTA,Copy_u8Pin);
			break;
			case DIO_u8PORTB:ClR_BIT(PORTB,Copy_u8Pin);
			break;
			case DIO_u8PORTC:ClR_BIT(PORTC,Copy_u8Pin);
			break;
			case DIO_u8PORTD:ClR_BIT(PORTD,Copy_u8Pin);
			break;
		}
	}
}

void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA :
		DDRA = Copy_u8Direction; break;
	case DIO_u8PORTB :
			DDRB = Copy_u8Direction; break;
	case DIO_u8PORTC :
			DDRC = Copy_u8Direction; break;
	case DIO_u8PORTD :
			DDRD = Copy_u8Direction; break;
	}

}
void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
		{
		case DIO_u8PORTA :
			PORTA = Copy_u8Value; break;
		case DIO_u8PORTB :
			PORTB = Copy_u8Value; break;
		case DIO_u8PORTC :
			PORTC = Copy_u8Value; break;
		case DIO_u8PORTD :
			PORTD = Copy_u8Value; break;
		}

}

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8Result;
	switch(Copy_u8Port){
		case DIO_u8PORTA:Local_u8Result=GET_BIT(PINA,Copy_u8Pin);break;
		case DIO_u8PORTB:Local_u8Result=GET_BIT(PINB,Copy_u8Pin);break;
		case DIO_u8PORTC:Local_u8Result=GET_BIT(PINC,Copy_u8Pin);break;
		case DIO_u8PORTD:Local_u8Result=GET_BIT(PIND,Copy_u8Pin);break;
	}
	return Local_u8Result;
}
