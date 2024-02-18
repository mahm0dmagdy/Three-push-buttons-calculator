/****************************************************************************/
/****************************************************************************/
/********************** Autor: Mahmoud Magdy ********************************/
/********************** File: CLCD_interface ********************************/
/**********************    Version: 1.00     ********************************/
/****************************************************************************/
/****************************************************************************/


#ifndef  INTERFACE_H_
#define INTERFACE_H_

//Cmd --> command
void CLCD_voidSendCmd(uint8 Copy_u8Cmd );
void CLCD_voidSendData(uint8 Copy_u8Data );
void CLCD_voidInit(void);
uint8 CLCD_u8Send_String(const char* Copy_chString);
void CLCD_voidSendNumber(sint32 Copy_s32Number);
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);
void CLCD_voidSendSpecialCharacter(uint8* Copy_pu8Pattern, uint8 Copy_u8PatternNumber,uint8 Copy_u8XPos, uint8 Copy_u8YPos);
void CLCD_voidDisplayBinary(uint8 Copy_u8DecimalNum);
void CLCD_voidDisplayHex(uint8 Copy_u8DecimalNum);

#endif