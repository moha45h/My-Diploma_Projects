/*
 * Registers.h
 *
 * Created: 2/10/2024 8:19:28 PM
 *  Author: Ali
 */ 


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/


#ifndef REGISTERS_H_
#define REGISTERS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define   PINA    *(volatile uint8*)(0x39)
#define   DDRA    *(volatile uint8*)(0x3A)
#define   PORTA   *(volatile uint8*)(0x3B)


#define   PINB    *(volatile uint8*)(0x36)
#define   DDRB    *(volatile uint8*)(0x37)
#define   PORTB   *(volatile uint8*)(0x38)


#define   PINC    *(volatile uint8*)(0x33)
#define   DDRC    *(volatile uint8*)(0x34)
#define   PORTC   *(volatile uint8*)(0x35)


#define   PIND    *(volatile uint8*)(0x30)
#define   DDRD    *(volatile uint8*)(0x31)
#define   PORTD   *(volatile uint8*)(0x32)




typedef struct
{
	uint8 PIN;
	uint8 DDR;
	uint8 PORT;
}DIO_Type;

#define  DIO_PORTA  ((volatile DIO_Type*)(0x39))
#define  DIO_PORTB  ((volatile DIO_Type*)(0x36))
#define  DIO_PORTC  ((volatile DIO_Type*)(0x33))
#define  DIO_PORTD  ((volatile DIO_Type*)(0x30))



/******************interrupts registers ***************/
#define   GICR    *(volatile uint8*)(0x5B) //global interrupt control register
#define   SREG    *(volatile uint8*)(0x5F)
#define   MCUCSR  *(volatile uint8*)(0x54)
#define   MCUCR   *(volatile uint8*)(0x55)


/******************ADC registers ***************/
#define ADMUX                      (*(volatile uint8 *)(0x27))#define ADCSRA                     (*(volatile uint8 *)(0x26))#define ADCH                       (*(volatile uint8 *)(0x25))#define ADCL                       (*(volatile uint8 *)(0x24))#define ADC_INPUT_16BIT_ACCESS    (*(volatile uint16*)(0x24))#define SFIOR                      (*(volatile uint8 *)(0x50))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/

//tips
/*
• Bit 7 – I: Global Interrupt Enable
The Global Interrupt Enable bit must be set for the interrupts to be enabled. The individual interrupt enable control is then performed in separate control registers. If the GlobalInterrupt Enable Register is cleared, none of the interrupts are enabled independent ofthe individual interrupt enable settings. The I-bit is cleared by hardware after an interrupthas occurred, and is set by the RETI instruction to enable subsequent interrupts. The Ibit can also be set and cleared by the application with the SEI and CLI instructions, asdescribed in the instruction set reference
*/

#endif /* REGISTERS_H_ */