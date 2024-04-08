/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: user
 */
/*start-hash-includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <avr/delay.h>
/*end-hash-includes*/
/*start-hash-define*/
#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111
#define RED_PIN 0
#define YELLOW_PIN 1
#define GREEN_PIN 2
#define COMMON_ONE 3
#define COMMON_TWO 4
/*end-hash-define*/

/*start-global*/
u8 num[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
/*end-global*/
/*start-functions-prototypes*/
void counter_func();
void yellow_counter_func();
/*end-functions-prototypes*/
int main(void){
	/*portA
	 * red lamp pin 0
	 * yellow lamp pin 1
	 * green lamp pin 2
	 * Common_one pin 3
	 * Common_two pin r
	 * */
	/*PORTC for the seven segment
	*/
	DIO_voidSetPortDirection(DIO_u8PORTA,0b00011111);
	DIO_voidSetPortDirection(DIO_u8PORTC,0b01111111);

	while(1){
		/*open red lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,RED_PIN,DIO_u8HIGH);
		counter_func();
		/*close red lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,RED_PIN,DIO_u8LOW);
		/*open green lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,GREEN_PIN,DIO_u8HIGH);
		counter_func();
		/*close green lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,GREEN_PIN,DIO_u8LOW);
		/*open yellow lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,YELLOW_PIN,DIO_u8HIGH);
		yellow_counter_func();
		/*close yellow lamp*/
		DIO_voidSetPinValue(DIO_u8PORTA,YELLOW_PIN,DIO_u8LOW);
	}

}
void counter_func(){
	s8 k=0;
	for(s8 i=5;i>=0;i--){
		for(s8 j=9;j>=0;j--){
			k=0;
			while(k<50){
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_ONE,DIO_u8LOW);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_TWO,DIO_u8HIGH);
			DIO_voidSetPortValue(DIO_u8PORTC,num[i]);
			_delay_ms(10);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_TWO,DIO_u8LOW);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_ONE,DIO_u8HIGH);
		    DIO_voidSetPortValue(DIO_u8PORTC,num[j]);
			_delay_ms(10);
			k++;
			}

		}
	}
}
void yellow_counter_func(){
	s8 k=0;
	for(s8 i=3;i>=0;i--){
		k=0;
		while(k<50){
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_ONE,DIO_u8LOW);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_TWO,DIO_u8HIGH);
			DIO_voidSetPortValue(DIO_u8PORTC,num[0]);
			_delay_ms(10);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_TWO,DIO_u8LOW);
			DIO_voidSetPinValue(DIO_u8PORTA,COMMON_ONE,DIO_u8HIGH);
			DIO_voidSetPortValue(DIO_u8PORTC,num[i]);
		    _delay_ms(10);
			k++;
		}
	}
}
