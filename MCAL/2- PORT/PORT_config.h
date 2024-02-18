/*
 * PORT_cfg.h
 *
 * Created: 8/3/2023 2:32:03 AM
 *  Author: mahmo
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/* Configure pins direction, Options: 1- INPUT
									  2- OUTPUT
									  */
#define PORTA_PIN0_DIR              OUTPUT
#define PORTA_PIN1_DIR		        OUTPUT
#define PORTA_PIN2_DIR              OUTPUT
#define PORTA_PIN3_DIR              OUTPUT
#define PORTA_PIN4_DIR              INPUT
#define PORTA_PIN5_DIR              INPUT
#define PORTA_PIN6_DIR              INPUT
#define PORTA_PIN7_DIR              INPUT
						         
#define PORTB_PIN0_DIR              OUTPUT
#define PORTB_PIN1_DIR		        OUTPUT
#define PORTB_PIN2_DIR              OUTPUT
#define PORTB_PIN3_DIR              OUTPUT
#define PORTB_PIN4_DIR              OUTPUT
#define PORTB_PIN5_DIR              OUTPUT
#define PORTB_PIN6_DIR              OUTPUT
#define PORTB_PIN7_DIR              OUTPUT
						         
#define PORTC_PIN0_DIR              INPUT
#define PORTC_PIN1_DIR		        INPUT
#define PORTC_PIN2_DIR              INPUT
#define PORTC_PIN3_DIR              OUTPUT
#define PORTC_PIN4_DIR              INPUT
#define PORTC_PIN5_DIR              INPUT
#define PORTC_PIN6_DIR              INPUT
#define PORTC_PIN7_DIR              INPUT
						         
#define PORTD_PIN0_DIR              OUTPUT
#define PORTD_PIN1_DIR		        INPUT
#define PORTD_PIN2_DIR              INPUT
#define PORTD_PIN3_DIR              INPUT
#define PORTD_PIN4_DIR              INPUT
#define PORTD_PIN5_DIR              INPUT
#define PORTD_PIN6_DIR              INPUT
#define PORTD_PIN7_DIR              INPUT

/* Configure the initial value, Options for input pin:  1- FLOATING
														2- PULLED_UP
														
								Options for Output pin:  1- LOW
														 2- HIGH */					         
#define PORTA_PIN0_INIT_VALUE        LOW
#define PORTA_PIN1_INIT_VALUE	     LOW
#define PORTA_PIN2_INIT_VALUE        LOW
#define PORTA_PIN3_INIT_VALUE        LOW
#define PORTA_PIN4_INIT_VALUE        FLOATING
#define PORTA_PIN5_INIT_VALUE        FLOATING
#define PORTA_PIN6_INIT_VALUE        FLOATING
#define PORTA_PIN7_INIT_VALUE        FLOATING
				   					 
#define PORTB_PIN0_INIT_VALUE        LOW
#define PORTB_PIN1_INIT_VALUE 	     LOW
#define PORTB_PIN2_INIT_VALUE        LOW
#define PORTB_PIN3_INIT_VALUE        LOW
#define PORTB_PIN4_INIT_VALUE        LOW
#define PORTB_PIN5_INIT_VALUE        LOW
#define PORTB_PIN6_INIT_VALUE        LOW
#define PORTB_PIN7_INIT_VALUE        LOW
				   					 
#define PORTC_PIN0_INIT_VALUE        FLOATING
#define PORTC_PIN1_INIT_VALUE 		 FLOATING
#define PORTC_PIN2_INIT_VALUE        FLOATING
#define PORTC_PIN3_INIT_VALUE        LOW
#define PORTC_PIN4_INIT_VALUE        FLOATING
#define PORTC_PIN5_INIT_VALUE        FLOATING
#define PORTC_PIN6_INIT_VALUE        FLOATING
#define PORTC_PIN7_INIT_VALUE        FLOATING
									 
#define PORTD_PIN0_INIT_VALUE        FLOATING
#define PORTD_PIN1_INIT_VALUE		 FLOATING
#define PORTD_PIN2_INIT_VALUE        FLOATING
#define PORTD_PIN3_INIT_VALUE        FLOATING
#define PORTD_PIN4_INIT_VALUE        FLOATING
#define PORTD_PIN5_INIT_VALUE        FLOATING
#define PORTD_PIN6_INIT_VALUE        FLOATING
#define PORTD_PIN7_INIT_VALUE        FLOATING
				   
#endif /* PORT_CFG_H_ */