/*
 * Interrupt.c
 *
 * Created: 3/16/2024 11:58:20 PM
 *  Author: Mohamed
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Interrupt.h"
#include "BIT_Math.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void IRQH_setGIE(uint8 GlobalInterruptStatus)
{
	switch (GlobalInterruptStatus)
	{
		case INT_ENABLE:
		  SET_BIT (SREG,7);
		break;
		
		case INT_DISABLE :
		    CLR_BIT (SREG,7);
		break;
		
		default:
		break;
		
	}
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void IRQ_setEXIT(void)
{
	#if (EXT_INT0 == INT_ENABLE)
	       SET_BIT(GICR,6); // to enable external interrupt 0
	       #if (EXT_INT0_TRIGGER == EXT_INT_LOW_LEVEL)
	           CLR_BIT(MCUCR,0);
	           CLR_BIT(MCUCR,1);
		   #elif (EXT_INT0_TRIGGER == EXT_INT_ANY_CHANGE)
		  	    SET_BIT(MCUCR,0);
		  	    CLR_BIT(MCUCR,1);
	       #elif (EXT_INT0_TRIGGER == EXT_INT_FALLING_EDGE)
		           CLR_BIT(MCUCR,0);
		           SET_BIT(MCUCR,1);   
           #elif (EXT_INT0_TRIGGER == EXT_INT_RISING_EDGE)
		       	   SET_BIT(MCUCR,0);
		       	   SET_BIT(MCUCR,1);
	       #endif
      #endif /*EXT_INT0 == INT_ENABLE*/
	
	#if (EXT_INT1 == INT_ENABLE)
	       SET_BIT(GICR,7); // to enable external interrupt 1
	       #if (EXT_INT1_TRIGGER == EXT_INT_LOW_LEVEL)
		         CLR_BIT(MCUCR,0);
		         CLR_BIT(MCUCR,1);
		   #elif (EXT_INT1_TRIGGER == EXT_INT_ANY_CHANGE)
		         SET_BIT(MCUCR,0);
		         CLR_BIT(MCUCR,1);
	 	   #elif (EXT_INT1_TRIGGER == EXT_INT_FALLING_EDGE)
			     CLR_BIT(MCUCR,0);
			     SET_BIT(MCUCR,1);
	 	   #elif (EXT_INT1_TRIGGER == EXT_INT_RISING_EDGE)
	 	       	  SET_BIT(MCUCR,0);
	 	       	  SET_BIT(MCUCR,1);
		 #endif
	#endif /*EXT_INT1 == INT_ENABLE*/
	
	#if (EXT_INT2 == INT_ENABLE)
	    SET_BIT(GICR,5); // to enable external interrupt 2
	      #if (EXT_INT2_TRIGGER == EXT_INT_FALLING_EDGE)
		    CLR_BIT(MCUCSR,6);
	      #elif (EXT_INT2_TRIGGER == EXT_INT_RISING_EDGE)
		    SET_BIT(MCUCSR,6);
		   #endif
	#endif /*EXT_INT2 == INT_ENABLE*/
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
