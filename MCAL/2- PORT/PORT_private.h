/****************************************************************************/
/****************************************************************************/
/********************** Autor: Mahmoud Magdy ********************************/
/********************** File: PORT_private.h ********************************/
/**********************    Version: 1.00     ********************************/
/****************************************************************************/
/****************************************************************************/


#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

#define INPUT              0
#define OUTPUT             1

#define FLOATING           0
#define PULLEDUP           1
#define LOW                0
#define HIGH               1

#define CONC(P7,P6,P5,P4,P3,P2,P1,P0)                        CONC_HELPER(P7,P6,P5,P4,P3,P2,P1,P0)
#define CONC_HELPER(P7,P6,P5,P4,P3,P2,P1,P0)                 0b##P7##P6##P5##P4##P3##P2##P1##P0

#define PORTA_DIR                                            CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR                                            CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR                                            CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR                                            CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_INIT_VALUE                                     CONC(PORTA_PIN7_INIT_VALUE,PORTA_PIN6_INIT_VALUE,PORTA_PIN4_INIT_VALUE,PORTA_PIN4_INIT_VALUE,PORTA_PIN3_INIT_VALUE,PORTA_PIN2_INIT_VALUE,PORTA_PIN1_INIT_VALUE,PORTA_PIN0_INIT_VALUE)   
#define PORTB_INIT_VALUE                                     CONC(PORTB_PIN7_INIT_VALUE,PORTB_PIN6_INIT_VALUE,PORTB_PIN5_INIT_VALUE,PORTB_PIN4_INIT_VALUE,PORTB_PIN3_INIT_VALUE,PORTB_PIN2_INIT_VALUE,PORTB_PIN1_INIT_VALUE,PORTB_PIN0_INIT_VALUE)   
#define PORTC_INIT_VALUE                                     CONC(PORTC_PIN7_INIT_VALUE,PORTC_PIN6_INIT_VALUE,PORTC_PIN5_INIT_VALUE,PORTC_PIN4_INIT_VALUE,PORTC_PIN3_INIT_VALUE,PORTC_PIN2_INIT_VALUE,PORTC_PIN1_INIT_VALUE,PORTC_PIN0_INIT_VALUE)   
#define PORTD_INIT_VALUE                                     CONC(PORTD_PIN7_INIT_VALUE,PORTD_PIN6_INIT_VALUE,PORTD_PIN5_INIT_VALUE,PORTD_PIN4_INIT_VALUE,PORTD_PIN3_INIT_VALUE,PORTD_PIN2_INIT_VALUE,PORTD_PIN1_INIT_VALUE,PORTD_PIN0_INIT_VALUE)   


#endif /* PORT_PRIVATE_H_ */