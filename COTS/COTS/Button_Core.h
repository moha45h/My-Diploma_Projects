/*
 * Button_Core.h
 *
 * Created: 2/10/2024 10:27:09 PM
 *  Author: Mohamed
 */ 


#ifndef BUTTON_CORE_H_
#define BUTTON_CORE_H_



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
#include "BIT_MATH.h"
#include "Registers.h"
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Button_0     ((uint8)(2u))
#define Button_1     ((uint8)(3u))
#define Button_2     ((uint8)(4u))



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
void button_init(uint8 button_pin);
uint8 get_button_val(uint8 button_pin);
 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/


#endif /* BUTTON_CORE_H_ */