/****************************************************************************/
/****************************************************************************/
/********************** Autor: Mahmoud Magdy ********************************/
/********************** File: PORT_private.h ********************************/
/**********************    Version: 1.00     ********************************/
/****************************************************************************/
/****************************************************************************/

#include "../../Library/BIT_MATH.h"
#include "../../Library/STD_TYPES.h"

#include "PORT_interface.h"
#include "PORT_reg.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PORT_voidInit(void){

DDRA = PORTA_DIR;
DDRB = PORTB_DIR;
DDRC = PORTC_DIR;
DDRD = PORTD_DIR;

PORTA = PORTA_INIT_VALUE;
PORTB = PORTB_INIT_VALUE;
PORTC = PORTC_INIT_VALUE;
PORTD = PORTD_INIT_VALUE;

	
}


