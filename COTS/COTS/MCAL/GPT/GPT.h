/*
 * GPT.h
 *
 * Created: 3/27/2024 10:52:08 PM
 *  Author: Mohamed
 */ 


#ifndef GPT_H_
#define GPT_H_

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
#include "STD.h"
#include "Registers.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define TIMER_ENABLE                 1U#define TIMER_DISABLE                0U#define NORMAL_MODE                  0U#define CTC_MODE                     1U#define PWM_Phase_Frequency_Correct  2U#define PWM_Phase_Correct            3U#define Fast_PWM                     4U#define NO_CLK_SRC                   0U#define CLK_SRC_WITH_NO_PRESCALING	 1U#define CLK_SRC_PRESCALING_8		 8U#define CLK_SRC_PRESCALING_32 		 32U#define CLK_SRC_PRESCALING_64 		 64U#define CLK_SRC_PRESCALING_128 		 128U#define CLK_SRC_PRESCALING_256 		 256U#define CLK_SRC_PRESCALING_1024      1024U#define INTERRUPT_ENABLED            1U#define INTERRUPT_DISABLED           0U
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
void GPT_Init(void);

void GPT_SetTime(void);
 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/




#endif /* GPT_H_ */