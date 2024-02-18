
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "../../Library/defines.h"

uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction){
	
	uint8 Local_u8ErrorState = OK;
	
	if(Copy_u8Pin <= DIO_u8PIN7){
		
	switch (Copy_u8Port){
		case DIO_u8PORTA:
			if(Copy_u8Direction == DIO_u8PIN_OUTPUT){
				DDRA |= (1<<Copy_u8Pin); }
			else if (Copy_u8Direction == DIO_u8PIN_INPUT){
				DDRA &=~ (1<<Copy_u8Pin);}
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTB: 
			if(Copy_u8Direction == DIO_u8PIN_OUTPUT){
				DDRB |= (1<<Copy_u8Pin); }
			else if (Copy_u8Direction == DIO_u8PIN_INPUT){
				DDRB &=~ (1<<Copy_u8Pin);}
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTC: 
			if(Copy_u8Direction == DIO_u8PIN_OUTPUT){
				DDRC |= (1<<Copy_u8Pin); }
			else if (Copy_u8Direction == DIO_u8PIN_INPUT){
				DDRC &=~ (1<<Copy_u8Pin);}
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTD: 
			if(Copy_u8Direction == DIO_u8PIN_OUTPUT){
				DDRD |= (1<<Copy_u8Pin); }
			else if (Copy_u8Direction == DIO_u8PIN_INPUT){
				DDRD &=~ (1<<Copy_u8Pin);}
			else 
				Local_u8ErrorState = NOK;
			break;
		default:Local_u8ErrorState = NOK; break;
	}
}
else 
	Local_u8ErrorState = NOK;

	return Local_u8ErrorState;

}


uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value){
	
	uint8 Local_u8ErrorState = OK;
	
	if(Copy_u8Pin <= DIO_u8PIN7){
		
	switch (Copy_u8Port){
		case DIO_u8PORTA:
			if(Copy_u8Value == DIO_u8PIN_HIGH)
				PORTA |= (1<<Copy_u8Pin); 
			else if (Copy_u8Value == DIO_u8PIN_LOW)
				PORTA &=~ (1<<Copy_u8Pin);
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTB: 
			if(Copy_u8Value == DIO_u8PIN_HIGH)
				PORTB |= (1<<Copy_u8Pin); 
			else if (Copy_u8Value == DIO_u8PIN_LOW)
				PORTB &=~ (1<<Copy_u8Pin);
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTC: 
			if(Copy_u8Value == DIO_u8PIN_HIGH)
				PORTC |= (1<<Copy_u8Pin);
			else if (Copy_u8Value == DIO_u8PIN_LOW)
				PORTC &=~ (1<<Copy_u8Pin);
			else
				Local_u8ErrorState = NOK;
			break;
		case DIO_u8PORTD: 
			if(Copy_u8Value == DIO_u8PIN_HIGH)
				PORTD |= (1<<Copy_u8Pin); 
			else if (Copy_u8Value == DIO_u8PIN_LOW)
				PORTD &=~ (1<<Copy_u8Pin);
			else 
				Local_u8ErrorState = NOK;
			break;
		default:Local_u8ErrorState = NOK; break;
	}
}
else 
	Local_u8ErrorState = NOK;

	return Local_u8ErrorState;

}

uint8 DIO_u8GetValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value){
	
	uint8 Local_u8ErrorState = OK;
	
	if(Copy_pu8Value != NULL){
		
		if(Copy_u8Pin <= DIO_u8PIN7){
		
	switch (Copy_u8Port){
		case DIO_u8PORTA:
			*Copy_pu8Value = GET_BIT(PINA,Copy_u8Pin);
			break;
		case DIO_u8PORTB: 
			*Copy_pu8Value = GET_BIT(PINB,Copy_u8Pin);
			break;
		case DIO_u8PORTC: 
			*Copy_pu8Value =  GET_BIT(PINC,Copy_u8Pin);
			break;
		case DIO_u8PORTD: 
			*Copy_pu8Value = GET_BIT(PIND,Copy_u8Pin);
			break;
		default: Local_u8ErrorState = NOK; break;
	}
}
else 
	Local_u8ErrorState = NOK;
	}
	else
		Local_u8ErrorState = NULL_PTR_ERR;
	
	return Local_u8ErrorState;
}

uint8 DIO_u8TogglePinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin){
	uint8 Local_u8ErrorState = OK;
if(Copy_u8Pin<=DIO_u8PIN7 ){
	switch(Copy_u8Port){
		case DIO_u8PORTA:	
			TOG_BIT(PORTA,Copy_u8Pin);break;
			
		case DIO_u8PORTB: 
			TOG_BIT(PORTB,Copy_u8Pin);break;
			
		case DIO_u8PORTC: 
			TOG_BIT(PORTC,Copy_u8Pin); break;
			
		case DIO_u8PORTD: 
			TOG_BIT(PORTD,Copy_u8Pin); break;
			
		default: Local_u8ErrorState = NOK; break;
}
}
else
	Local_u8ErrorState = NOK;

return Local_u8ErrorState;
}

/* To init all the port pins direction at once */

uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction){
		uint8 Local_u8ErrorState = OK;

	switch(Copy_u8Port){
		case DIO_u8PORTA:	
			DDRA = Copy_u8Direction; break;
			
		case DIO_u8PORTB: 
			DDRB = Copy_u8Direction; break;
			
		case DIO_u8PORTC: 
			DDRC = Copy_u8Direction; break;
			
		case DIO_u8PORTD: 
			DDRD = Copy_u8Direction; break;
			
		default: Local_u8ErrorState = NOK; break;
}
return Local_u8ErrorState;
}

/* To init all the port pins value at once */
uint8 DIO_u8SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value){
	
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8Port){
		case DIO_u8PORTA:	
			PORTA = Copy_u8Value; break;
			
		case DIO_u8PORTB: 
			PORTB = Copy_u8Value; break;
			
		case DIO_u8PORTC: 
			PORTC = Copy_u8Value; break;
			
		case DIO_u8PORTD: 
			PORTD = Copy_u8Value; break;
			
		default: Local_u8ErrorState = NOK; break;
}
return Local_u8ErrorState;
	
}

