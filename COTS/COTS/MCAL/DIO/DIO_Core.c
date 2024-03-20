/*
 * DIO_Core.c
 *
 * Created: 3/1/2024 9:10:22 PM
 *  Author: Ali
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
#include "DIO_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define    DIO_TOTAL_PORT_PINS    ((uint8)(8U))
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
void DIO_WriteChannel(uint8 pin_number, PIN_VALUE_t  Vlaue)
{
	uint8 port = 0 , pin = 0;
	
	port = pin_number / DIO_TOTAL_PORT_PINS;
	pin = pin_number % DIO_TOTAL_PORT_PINS;
	
	switch(Vlaue)
	{
		case PIN_HIGH :
		 switch(port)
		 {
			 case DIO_PORT_A :
			 SET_BIT(DIO_PORTA->PORT , pin);
			 break;
			 case DIO_PORT_B :
			 SET_BIT(DIO_PORTB->PORT , pin);
			 break;
			 case DIO_PORT_C :
			 SET_BIT(DIO_PORTC->PORT , pin);
			 break;
			 case DIO_PORT_D :
			 SET_BIT(DIO_PORTD->PORT , pin);
			 break;	
			 default:
			 break;
		 }
		 break;
		 
		case PIN_LOW :
		switch(port)
		{
			case DIO_PORT_A :
			CLR_BIT(DIO_PORTA->PORT , pin);
			break;
			case DIO_PORT_B :
			CLR_BIT(DIO_PORTB->PORT , pin);
			break;
			case DIO_PORT_C :
			CLR_BIT(DIO_PORTC->PORT , pin);
			break;
			case DIO_PORT_D :
			CLR_BIT(DIO_PORTD->PORT , pin);
			break;
			default:
			break;
		}
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
void DIO_ReadChannel(uint8 pin_number , PIN_VALUE_t* Value)
{
	uint8 port = 0 , pin = 0;
	
	port = pin_number / DIO_TOTAL_PORT_PINS;
	pin = pin_number % DIO_TOTAL_PORT_PINS;

	switch(port)
	{
		case DIO_PORT_A :
		*Value = GET_BIT(DIO_PORTA->PIN , pin);
		break;
		case DIO_PORT_B :
		*Value = GET_BIT(DIO_PORTB->PIN , pin);
		break;
		case DIO_PORT_C :
		*Value = GET_BIT(DIO_PORTC->PIN , pin);
		break;
		case DIO_PORT_D :
		*Value = GET_BIT(DIO_PORTD->PIN , pin);
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
void DIO_FlipChannel(uint8 pin_number)
{
	uint8 port = 0 , pin = 0;
	
	port = pin_number / DIO_TOTAL_PORT_PINS;
	pin = pin_number % DIO_TOTAL_PORT_PINS;

	switch(port)
	{
		case DIO_PORT_A :
		TOGGLE_BIT(DIO_PORTA->PORT , pin);
		break;
		case DIO_PORT_B :
		TOGGLE_BIT(DIO_PORTB->PORT , pin);
		break;
		case DIO_PORT_C :
		TOGGLE_BIT(DIO_PORTC->PORT , pin);
		break;
		case DIO_PORT_D :
		TOGGLE_BIT(DIO_PORTD->PORT , pin);
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
void DIO_SetPullUp(uint8 pin_number)
{
	uint8 port = 0 , pin = 0;
	
	port = pin_number / DIO_TOTAL_PORT_PINS;
	pin = pin_number % DIO_TOTAL_PORT_PINS;

	switch(port)
	{
		case DIO_PORT_A :
		SET_BIT(DIO_PORTA->PORT , pin);
		break;
		case DIO_PORT_B :
		SET_BIT(DIO_PORTB->PORT , pin);
		break;
		case DIO_PORT_C :
		SET_BIT(DIO_PORTC->PORT , pin);
		break;
		case DIO_PORT_D :
		SET_BIT(DIO_PORTD->PORT , pin);
		break;
		default:
		break;
	}	
}

/******************************************************************************
* \Syntax          : void DIO_WritePORTValue(uint8 port , uint8 PortValue)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Description
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_WritePORTValue(uint8 port , uint8 PortValue)
{
	switch(port)
	{
		case DIO_PORT_A :
		DIO_PORTA->PORT = PortValue;
		break;
		case DIO_PORT_B :
		DIO_PORTB->PORT = PortValue;
		break;
		case DIO_PORT_C :
		DIO_PORTC->PORT = PortValue;
		break;
		case DIO_PORT_D :
		DIO_PORTD->PORT = PortValue;
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
void DIO_ReadPORTValue(uint8 port , uint8* PortValue)
{
	switch(port)
	{
		case DIO_PORT_A :
		*PortValue = DIO_PORTA->PIN  ;
		break;
		case DIO_PORT_B :
		*PortValue = DIO_PORTB->PIN  ;
		break;
		case DIO_PORT_C :
		*PortValue = DIO_PORTC->PIN  ;
		break;
		case DIO_PORT_D :
		*PortValue = DIO_PORTD->PIN  ;
		break;
		default:
		break;
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
