/*
 * _7Seg_StopWatch.c
 *
 * Created: 2/14/2024 11:08:16 AM
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
#include "StopWatch.h"

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
void sevseg_init(void)
{
	DIO_PORTA->DDR=0xff;
	SET_BIT(DIO_PORTC->DDR,6);
	SET_BIT(DIO_PORTC->DDR,7);
	
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
void buttons_init(void)
{
	CLR_BIT(DIO_PORTD->DDR,2);
	CLR_BIT(DIO_PORTD->DDR,3);
	CLR_BIT(DIO_PORTD->DDR,4);
	CLR_BIT(DIO_PORTD->DDR,5);
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
void SevSeg_display(uint8 num)
{
	SET_BIT(DIO_PORTC->PORT,6);
	CLR_BIT(DIO_PORTC->PORT,7);
	DIO_PORTA->PORT=sev_seg[num%10];
	_delay_ms(1);
	CLR_BIT(DIO_PORTC->PORT,6);
	SET_BIT(DIO_PORTC->PORT,7);
	DIO_PORTA->PORT=sev_seg[num/10];
	_delay_ms(1);
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

void start(void)
{
	uint8 counter=0;
	uint8 button_val=GET_BIT(DIO_PORTD->PIN,4);
	if (button_val==0)
	{
		
		for (int i=counter;i>counter; i--)
		{
			CLR_BIT(DIO_PORTC->PORT,6);
			SET_BIT(DIO_PORTC->PORT,7);
			DIO_PORTA->PORT=sev_seg[counter/10];
			_delay_ms(1);
			SET_BIT(DIO_PORTC->PORT,6);
			CLR_BIT(DIO_PORTC->PORT,7);
			DIO_PORTA->PORT=sev_seg[counter%10];
			_delay_ms(1);
			if (counter==0)
			{
				SET_BIT(DIO_PORTC->PORT,5);
			}
			
		}
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


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
