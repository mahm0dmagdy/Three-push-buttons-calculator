/****************************************************************************/
/****************************************************************************/
/********************** Autor: Mahmoud Magdy ********************************/
/********************** File: CLCD_program.c ********************************/
/**********************    Version: 1.00     ********************************/
/****************************************************************************/
/****************************************************************************/


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#define F_CPU 1000000U
#include <util/delay.h>
#include "../../MCAL/1- DIO/DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "../../Library/defines.h"

static void voidSendEnablePulse(void){
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

static void voidSetLcdHalfDataPort(uint8 Copy_u8Nipple){
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,GET_BIT(Copy_u8Nipple,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,GET_BIT(Copy_u8Nipple,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,GET_BIT(Copy_u8Nipple,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,GET_BIT(Copy_u8Nipple,3));
}

void CLCD_voidSendCmd(uint8 Copy_u8Cmd){
	
/* Set RS pin low for command*/
DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

/* Set RW pin low for write*/	
DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

#if CLCD_OP_MODE == EIGHT_BIT_MODE
/* Send the command on data pins */
DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Cmd);

/* Set enable pulse */
voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

voidSetLcdHalfDataPort(Copy_u8Cmd>>4);

/* Set enable pulse */
voidSendEnablePulse();

voidSetLcdHalfDataPort(Copy_u8Cmd);

/* Set enable pulse */
voidSendEnablePulse();
#endif
}
	

void CLCD_voidSendData(uint8 Copy_u8Data){
	
/* Set RS pin high for data*/
DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

/* Set RW pin low for write*/
DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

/* Send the data on data pins */
#if CLCD_OP_MODE == EIGHT_BIT_MODE
DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

/* Set enable pulse */
voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

voidSetLcdHalfDataPort(Copy_u8Data>>4);

/* Set enable pulse */
voidSendEnablePulse();

voidSetLcdHalfDataPort(Copy_u8Data);

/* Set enable pulse */
voidSendEnablePulse();
#endif
}
	
void CLCD_voidInit(void){
	/* Wait for more than 30ms after power on */
	_delay_ms(40);
	
	#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Function set command: 2 lines, 5*7 font size */
	CLCD_voidSendCmd(0b00111000);
	
	#elif CLCD_OP_MODE == FOUR_BIT_MODE
	
	voidSetLcdHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLcdHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLcdHalfDataPort(0b1000);
	voidSendEnablePulse();

	/*	Why this also working
	CLCD_voidSendCmd(0b00000010);
	CLCD_voidSendCmd(0b00000010);
	CLCD_voidSendCmd(0b00001000);
	*/
	#endif
	
	/*Display on/off ctrl: display enable, cursor and blink disable*/
	CLCD_voidSendCmd(0b00001100);
	
	/*Display Clear*/
	CLCD_voidSendCmd(0b00000001);
	
}

uint8 CLCD_u8Send_String(const char* Copy_chString){
	uint8 Local_u8ErrorState = OK;
	
	if(Copy_chString != NULL){
		uint8 Local_u8Counter = 0u;
		
	while(Copy_chString[Local_u8Counter] != '\0'){
		CLCD_voidSendData(Copy_chString[Local_u8Counter]);
		Local_u8Counter++;
		}
	}
	
	else
		Local_u8ErrorState = NULL_PTR_ERR;
		
	return Local_u8ErrorState;
}

void CLCD_voidSendNumber(sint32 Copy_s32Number){
	
	char local_chNumberArray[10];
	
	uint8 local_u8RightDigit,local_u8Counter = 0 ;
	sint8 local_u8Counter2;
	
	if(Copy_s32Number == 0){
		CLCD_voidSendData('0');
		return;
	}
	else if(Copy_s32Number < 0){
		CLCD_voidSendData('-');
		Copy_s32Number*= -1;		
	}
	
	while(Copy_s32Number != 0){
	    local_u8RightDigit = Copy_s32Number %10 ;
		local_chNumberArray[local_u8Counter] = local_u8RightDigit+'0';
		Copy_s32Number /= 10;
		local_u8Counter++;
	}
	for(local_u8Counter2 = local_u8Counter-1 ; local_u8Counter2>=0 ; local_u8Counter2--){
	CLCD_voidSendData(local_chNumberArray[local_u8Counter2]);
	}
	
}

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos){
	uint8 Local_u8DDramAdd;
	if(Copy_u8YPos == 0u)
		Local_u8DDramAdd = Copy_u8XPos;
	else if	(Copy_u8YPos == 1u)
		Local_u8DDramAdd = 0x40 + Copy_u8XPos;
		
	SET_BIT(Local_u8DDramAdd,7u);		
	CLCD_voidSendCmd(Local_u8DDramAdd);
}

void CLCD_voidSendSpecialCharacter(uint8* Copy_pu8Pattern , uint8 Copy_u8PatternNum,uint8 Copy_u8XPos, uint8 Copy_u8YPos){
	uint8 Local_u8LoopCounter ;
	uint8 Local_u8CGRAMAdd = Copy_u8PatternNum *8 ;
	/*Set bit number 6 for set CGram address command*/
	SET_BIT(Local_u8CGRAMAdd,6u);
	
	/*set CGram address*/
	CLCD_voidSendCmd(Local_u8CGRAMAdd);
	
	/*Write pattern into CGram*/
	for(Local_u8LoopCounter=0;Local_u8LoopCounter<8;Local_u8LoopCounter++)
	CLCD_voidSendData(Copy_pu8Pattern[Local_u8LoopCounter]);
	
	/*Goto DDRam to display pattern*/
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	/*Display the pattern written inside CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNum);	
}
void CLCD_voidDisplayBinary(uint8 Copy_u8DecimalNum){
	uint8 Local_u8BinaryNum[8];
	sint8 Local_u8Remainder;
	uint8 Local_u8Counter;
	for(Local_u8Remainder = 7 ; Local_u8Remainder >= 0 ; Local_u8Remainder--){
	if(Copy_u8DecimalNum % 2 == 0){
	Local_u8BinaryNum[Local_u8Remainder] = 0;
	}
	else{	
		Local_u8BinaryNum[Local_u8Remainder] = 1;
		Copy_u8DecimalNum--;
			 }		
		Copy_u8DecimalNum = Copy_u8DecimalNum / 2;
	}
		CLCD_voidSendData('0');
		CLCD_voidSendData('b');
	   for(Local_u8Counter =0 ; Local_u8Counter<8 ; Local_u8Counter++){
		   CLCD_voidSendNumber(Local_u8BinaryNum[Local_u8Counter]);
	   }
	}
void CLCD_voidDisplayHex(uint8 Copy_u8DecimalNum){
	uint8 Local_u8OctalNum = 0;
	while(Copy_u8DecimalNum != 0){
	Local_u8OctalNum = Local_u8OctalNum + ((Copy_u8DecimalNum % 8) * 10);
	Copy_u8DecimalNum = (Copy_u8DecimalNum - (Copy_u8DecimalNum % 8)) / 8;
    }
	CLCD_voidSendNumber(Local_u8OctalNum);
}
