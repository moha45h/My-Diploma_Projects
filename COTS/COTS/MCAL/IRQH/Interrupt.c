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
#include <avr/interrupt.h>

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*CallBack_ptrtofunc[20])(void)={0};


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
void IRQH_setCallBacks(uint8 vectortableindex,void(*p)(void))
{			CallBack_ptrtofunc[vectortableindex] = p;
}




ISR(INT0_vect)
{
	if(CallBack_ptrtofunc[External_Interrupt_Request_0_VECTOR_INDEX] != 0)	{	  (*CallBack_ptrtofunc[External_Interrupt_Request_0_VECTOR_INDEX])();	}
}

ISR(ADC_vect)
{
	uint32 ADC_Digital_val =ADC_INPUT_16BIT_ACCESS;
	
	ADC_vinvalue_mv=(ADC_Digital_val * 5000)/1024;
		if(CallBack_ptrtofunc[ADC_Conversion_Complete_VECTOR_INDEX] != 0)		{			(*CallBack_ptrtofunc[ADC_Conversion_Complete_VECTOR_INDEX])();		}
}


ISR(TIMER0_OVF_vect)
{
	static uint32 ovfcnt=0;
	ovfcnt++;
	if (ovfcnt==timer0_number_of_over)
	{
		if(CallBack_ptrtofunc[Timer_Counter0_Overflow_VECTOR_INDEX] != 0)		{			(*CallBack_ptrtofunc[Timer_Counter0_Overflow_VECTOR_INDEX])();		}
	
	
	ovfcnt=0;
	TCNT0=timer0_initValue;
	}
}

ISR(TIMER1_COMPA_vect)
{
		static uint32 matchcnt=0;
		matchcnt++;
		if (matchcnt==1U)
		{
			if(CallBack_ptrtofunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX] != 0)			{				(*CallBack_ptrtofunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX])();			}
			
			matchcnt=0;
			
		}
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
