/*
 * CFile1.c
 *
 * Created: 3/2/2024 9:41:36 PM
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
#include "LCD_Core.h"

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
void LCD_Init(void)
{
	#if LCD_OPERATION_MODE  ==  LCD_4BIT_MODE
	/*4 Bit Mode Commands*/
	 LCD_WriteCmd(0x33);
	 LCD_WriteCmd(0x32);
	 LCD_WriteCmd(0x28);
	 /*Cursor Off*/
	 LCD_WriteCmd(0x0C);
	 /*Clear Display*/
	 LCD_WriteCmd(0x01);
	 /*Move cursor to right*/
	 LCD_WriteCmd(0x06);
	 /*Return Home*/
	 LCD_WriteCmd(0x02);
	 
	#elif LCD_OPERATION_MODE  ==  LCD_8BIT_MODE
		/*8 Bit Mode Commands*/
		LCD_WriteCmd(0x38);
		/*Cursor Off*/
		LCD_WriteCmd(0x0C);
		/*Clear Display*/
		LCD_WriteCmd(0x01);
		/*Move cursor to right*/
		LCD_WriteCmd(0x06);
		/*Return Home*/
		LCD_WriteCmd(0x02);
	#endif /*LCD_OPERATION_MODE  ==  LCD_4BIT_MODE*/
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
void LCD_WriteCmd(uint8 cmd)
{
	/*select command register*/
	DIO_WriteChannel(RS_PIN , PIN_LOW);
	/*Default low on E pin*/
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , GET_BIT(cmd , 4));
	DIO_WriteChannel(D5_PIN , GET_BIT(cmd , 5));
	DIO_WriteChannel(D6_PIN , GET_BIT(cmd , 6));
	DIO_WriteChannel(D7_PIN , GET_BIT(cmd , 7));
	
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , GET_BIT(cmd , 0));
	DIO_WriteChannel(D5_PIN , GET_BIT(cmd , 1));
	DIO_WriteChannel(D6_PIN , GET_BIT(cmd , 2));
	DIO_WriteChannel(D7_PIN , GET_BIT(cmd , 3));
	
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	_delay_ms(5);
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
void LCD_WriteData(uint8 data)
{
	/*select Data register*/
	DIO_WriteChannel(RS_PIN , PIN_HIGH);
	/*Default low on E pin*/
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , GET_BIT(data , 4));
	DIO_WriteChannel(D5_PIN , GET_BIT(data , 5));
	DIO_WriteChannel(D6_PIN , GET_BIT(data , 6));
	DIO_WriteChannel(D7_PIN , GET_BIT(data , 7));
	
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , GET_BIT(data , 0));
	DIO_WriteChannel(D5_PIN , GET_BIT(data , 1));
	DIO_WriteChannel(D6_PIN , GET_BIT(data , 2));
	DIO_WriteChannel(D7_PIN , GET_BIT(data , 3));
	
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	_delay_ms(5);	
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
void LCD_WriteString(uint8* str)
{
	uint8 cnt = 0;
	
	while(str[cnt] != '\0')
	{
		LCD_WriteData(str[cnt]);
		cnt++;
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
void LCD_WriteInteger(sint32 integer)
{
	uint8 temp =1;
	/*if number is zero */
	if (integer==0)
	{
		LCD_WriteData('0');
	}
	/*if number is negative */
	if (integer<0)
	{
		LCD_WriteData('-');
		integer *=-1;
	}
	/*if number is positive */
	/*reverse step*/
	while (integer>0)
	{
		temp =(temp*10)+(integer%10);
		integer /=10;
	}
	while (temp>1)
	{
		LCD_WriteData((temp%10)+48);
		temp /=10;
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
void LCD_Goto(uint8 Col , uint8 Row)
{
	
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
void LCD_Clear(void)
{
	LCD_WriteCmd(0X01);
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
void LCD_WriteCustomChar(void)
{
	
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
