/*
 * Drivers.c
 *
 * Created: 7/28/2023 10:31:14 AM
 * Author : mahmo
 */ 
#define F_CPU 1000000U
#include <util/delay.h>
#include "Library/BIT_MATH.h"
#include "Library/STD_TYPES.h"

#include "MCAL/1- DIO/DIO_interface.h"
#include "ECUAL/1- CLCD/CLCD_interface.h"
#include "MCAL/2- PORT/PORT_config.h"
#include "MCAL/2- PORT/PORT_interface.h"

void Local_voidDelResult(uint8* Copy_u8BlankPattern);

int main(void)
{
	
	uint8 Local_u8ArrowPattern[7] = {0b00000100,0b00000100,0b00001110,0b00010101,0b00000100,0b00000100,0b00000100};
	uint8 Local_u8BlankPattern[7] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};

	uint8 Local_u8Math[4] = {'+','-','*','/'};
	uint8 Local_u8Up;
	uint8 Local_u8Down;
	uint8 Local_u8Enter;
	uint8 Local_u8FirstValue = 1;
	uint8 Local_u8SecondValue = 1;
	uint8 Local_u8CharacterCounter = 1u ;
	uint8 Local_u8X = 0u;
	uint8 Local_u8Y = 1u;
	sint32 Local_u8Resualt;
	sint8 Local_s8MathCounter = 0;
	
	PORT_voidInit();
	CLCD_voidInit();

	/*Init button pin direction*/
	/*
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_INPUT); //UP
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_INPUT); //DOWN
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_INPUT); //Enter
	
	
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT); //RS
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT); //E
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_OUTPUT); //RW
	
	DIO_u8SetPortDirection(DIO_u8PORTB,0xff); //Data Port
	 */

CLCD_voidSendNumber(Local_u8FirstValue);
CLCD_voidSendData(Local_u8Math[Local_s8MathCounter]);
CLCD_voidSendNumber(Local_u8SecondValue);
CLCD_voidSendData('=');

CLCD_voidSendSpecialCharacter(Local_u8ArrowPattern,0u,Local_u8X,Local_u8Y);

    while (1) 
    {
	DIO_u8GetValue(DIO_u8PORTC,DIO_u8PIN2,&Local_u8Up);
	DIO_u8GetValue(DIO_u8PORTC,DIO_u8PIN5,&Local_u8Down);
	DIO_u8GetValue(DIO_u8PORTC,DIO_u8PIN6,&Local_u8Enter);

	if(Local_u8Enter == DIO_u8PIN_HIGH ){
	_delay_ms(200);
	CLCD_voidSendSpecialCharacter(Local_u8BlankPattern,1u,Local_u8X,Local_u8Y);
	
	if(Local_u8X == 2u){
		Local_u8X = 0u;
	}
	else{
		Local_u8X++;
	}
	
	CLCD_voidSendSpecialCharacter(Local_u8ArrowPattern,0u,Local_u8X,Local_u8Y);
	if(Local_u8CharacterCounter==3){
		Local_u8CharacterCounter = 1;
	}
	else{
		Local_u8CharacterCounter++;
	}
	}
	
switch (Local_u8CharacterCounter)	{
	case 1:
	if(Local_u8Up == DIO_u8PIN_HIGH ){
		_delay_ms(200);
		Local_u8FirstValue++;
		if(Local_u8FirstValue > 9){
			Local_u8FirstValue = 0;
		}
		CLCD_voidGoToXY(0u, 0u);
		CLCD_voidSendNumber(Local_u8FirstValue);
		}
	
	else if(Local_u8Down == DIO_u8PIN_HIGH ){
		_delay_ms(200);
		if(Local_u8FirstValue == 0){
			Local_u8FirstValue = 9;	
		}
		else{
			Local_u8FirstValue--;
		}
		CLCD_voidGoToXY(0u, 0u);
		CLCD_voidSendNumber(Local_u8FirstValue);
	}
	break;
	
	case 2:
	if(Local_u8Up == DIO_u8PIN_HIGH ){
		_delay_ms(200);
		CLCD_voidGoToXY(1u, 0u);

		if(Local_s8MathCounter == 3 || (Local_s8MathCounter == 2 && Local_u8SecondValue == 0) ){
			Local_s8MathCounter = 0;
		}
		else{
			Local_s8MathCounter++;
		}
		CLCD_voidSendData(Local_u8Math[Local_s8MathCounter]);
	}
	
	else if (Local_u8Down == DIO_u8PIN_HIGH){
		_delay_ms(200);
		CLCD_voidGoToXY(1u, 0u);
	
		if(Local_s8MathCounter == 0){
			if(Local_u8SecondValue == 0){
				Local_s8MathCounter = 2;
			}
			else{
				Local_s8MathCounter = 3;
			}
		}
		else{
			Local_s8MathCounter--;
		}
		CLCD_voidSendData(Local_u8Math[Local_s8MathCounter]);
	}
	break;
	
	case 3:
	if(Local_u8Up == DIO_u8PIN_HIGH ){
		_delay_ms(200);
		
		if(Local_u8SecondValue == 9){
			if(Local_s8MathCounter == 3){
				Local_u8SecondValue = 1;
			}
			else{
				Local_u8SecondValue=0;
		}
		}
		else{
		Local_u8SecondValue++;
		}
		
		CLCD_voidGoToXY(2u, 0u);
		CLCD_voidSendNumber(Local_u8SecondValue);
	}
	
	else if(Local_u8Down == DIO_u8PIN_HIGH ){
		_delay_ms(200);
		if((Local_u8SecondValue == 1 && Local_s8MathCounter == 3) || (Local_u8SecondValue == 0)){
				Local_u8SecondValue = 9;
		}
		else{
			Local_u8SecondValue--;
		}
		
		CLCD_voidGoToXY(2u, 0u);
		CLCD_voidSendNumber(Local_u8SecondValue);
	}
	break;
    }
	
	switch(Local_s8MathCounter){
		case 0: 
		if(Local_u8Resualt!=Local_u8FirstValue + Local_u8SecondValue){
			Local_voidDelResult(Local_u8BlankPattern);
		
			Local_u8Resualt =Local_u8FirstValue + Local_u8SecondValue;
				CLCD_voidGoToXY(4u,0u);
				CLCD_voidSendNumber(Local_u8Resualt);
		}
		break;
		
		case 1: 
		if(Local_u8Resualt != Local_u8FirstValue - Local_u8SecondValue && Local_u8Resualt != Local_u8SecondValue - Local_u8FirstValue){
			Local_voidDelResult(Local_u8BlankPattern);
			
			Local_u8Resualt = Local_u8FirstValue - Local_u8SecondValue;
			CLCD_voidGoToXY(4u,0u);
			CLCD_voidSendNumber(Local_u8Resualt);
		}
			break;
		
		case 2:
			if(Local_u8Resualt!=Local_u8FirstValue * Local_u8SecondValue){
				Local_voidDelResult(Local_u8BlankPattern);
			
				Local_u8Resualt = Local_u8FirstValue * Local_u8SecondValue;
				CLCD_voidGoToXY(4u,0u);
				CLCD_voidSendNumber(Local_u8Resualt);
		}		
		break;
		
		case 3:
			if(Local_u8Resualt!= (Local_u8FirstValue*1000) / Local_u8SecondValue ){
				Local_voidDelResult(Local_u8BlankPattern);
				
				Local_u8Resualt = (1000*Local_u8FirstValue) / Local_u8SecondValue;
				CLCD_voidGoToXY(4u,0u);
				CLCD_voidSendNumber(Local_u8Resualt/1000);
				CLCD_voidSendData('.');
				CLCD_voidSendNumber((Local_u8Resualt) - ((Local_u8Resualt/1000) * 1000));
		}
		break;
	}	
}

	}
	
void Local_voidDelResult(uint8* Copy_u8BlankPattern){
		CLCD_voidSendSpecialCharacter(Copy_u8BlankPattern,1u,5u,0u);
		CLCD_voidSendSpecialCharacter(Copy_u8BlankPattern,1u,6u,0u);
		CLCD_voidSendSpecialCharacter(Copy_u8BlankPattern,1u,7u,0u);
		CLCD_voidSendSpecialCharacter(Copy_u8BlankPattern,1u,8u,0u);
	}
