/*
 * Interrupt.h
 *
 * Created: 3/16/2024 11:58:41 PM
 *  Author: Mohamed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Interrupt_Cfg.h"
#include "STD.h"
#include "Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INT_ENABLE               (1U)
#define INT_DISABLE              (0U)

#define EXT_INT_FALLING_EDGE      0U
#define EXT_INT_RISING_EDGE       1U
#define EXT_INT_LOW_LEVEL         2U
#define EXT_INT_ANY_CHANGE        3U
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
void IRQH_setGIE(uint8 GlobalInterruptStatus);// to enable global interrupts
void IRQ_setExtInterrupt(void);
void IRQH_setCallBacks(uint8 vectortableindex,void (*p)(void));
 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/



#endif /* INTERRUPT_H_ */