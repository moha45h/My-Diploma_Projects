/*
 * ADC_Cfg.h
 *
 * Created: 3/22/2024 9:21:45 PM
 *  Author: Mohamed
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

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
#include "ADC_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC_VOLTAGE_REFAERENCE     ADC_VREF_AVCC
#define ADC_CHANNEL                ADC_CHANNEL_0
#define ADC_CONVERSION_TRIGGER     ADC_CONVERSION_FREE_RUNNING
#define ADC_PRESCALER              ADC_PRESCALER_128
#define ADC_INTERRUPT_STATUS       ADC_INTERRUPT_ENABLE
#define ADC_REG_ADJUST             ADC_RIGHT_ADJUST


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern uint32 ADC_vinvalue_mv;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/




#endif /* ADC_CFG_H_ */