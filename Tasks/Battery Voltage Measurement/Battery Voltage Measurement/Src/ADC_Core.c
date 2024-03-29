/*
 * ADC_Core.c
 *
 * Created: 3/22/2024 9:19:37 PM
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
#include "ADC_Cfg.h"
#include "ADC_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 uint32 ADC_vinvalue_mv;
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

void ADC_Init(void)
{
	/******************************voltage refernce selection***********************************/
	#if (ADC_VOLTAGE_REFAERENCE == ADC_VREF_AVCC)
	   SET_BIT(ADMUX,6);
	   CLR_BIT(ADMUX,7);
	#elif (ADC_VOLTAGE_REFAERENCE == ADC_VREF_AREF)
	  	  CLR_BIT(ADMUX,6);
	  	   CLR_BIT(ADMUX,7);
	#elif (ADC_VOLTAGE_REFAERENCE == ADC_VREF_INTERNAL)
      	   SET_BIT(ADMUX,6);
      	  SET_BIT(ADMUX,7);
    #endif /*ADC_VOLTAGE_REFAERENCE == ADC_VREF_AVCC*/
	
/******************************channel selection***********************************/	

	#if (ADC_CHANNEL== ADC_CHANNEL_0)
	  CLR_BIT(ADMUX,0);
	  CLR_BIT(ADMUX,1);
	  CLR_BIT(ADMUX,2);
	  CLR_BIT(ADMUX,3);
	  CLR_BIT(ADMUX,4);
	#elif (ADC_CHANNEL== ADC_CHANNEL_1)
		  SET_BIT(ADMUX,0);
		  CLR_BIT(ADMUX,1);
		  CLR_BIT(ADMUX,2);
		  CLR_BIT(ADMUX,3);
		  CLR_BIT(ADMUX,4);
	#elif (ADC_CHANNEL== ADC_CHANNEL_2)
	   	  CLR_BIT(ADMUX,0);
	   	  SET_BIT(ADMUX,1);
	   	  CLR_BIT(ADMUX,2);
	   	  CLR_BIT(ADMUX,3);
	   	  CLR_BIT(ADMUX,4);
	#elif (ADC_CHANNEL== ADC_CHANNEL_3)
	    	   	  SET_BIT(ADMUX,0);
	    	   	  SET_BIT(ADMUX,1);
	    	   	  CLR_BIT(ADMUX,2);
	    	   	  CLR_BIT(ADMUX,3);
	    	   	  CLR_BIT(ADMUX,4);
	#elif (ADC_CHANNEL== ADC_CHANNEL_4)
	  	   	  CLR_BIT(ADMUX,0);
	  	   	  CLR_BIT(ADMUX,1);
	  	   	  SET_BIT(ADMUX,2);
	  	   	  CLR_BIT(ADMUX,3);
	  	   	  CLR_BIT(ADMUX,4);
	#elif (ADC_CHANNEL== ADC_CHANNEL_5)
	   ADMUX |=0x05;
	#elif (ADC_CHANNEL== ADC_CHANNEL_6)
	   ADMUX |=0x06;
	#elif (ADC_CHANNEL== ADC_CHANNEL_7)
	  ADMUX |=0x07;
    #endif /*ADC_CHANNEL== ADC_CHANNEL_0*/
	
	/******************************trigger selection***********************************/
	#if (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_SINGLE)
	 CLR_BIT(ADCSRA,5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_FREE_RUNNING)
	    SET_BIT(ADCSRA,5);
	    SFIOR |=(0X00<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_ANALOG_COMPARATOR)
		SET_BIT(ADCSRA,5);
		SFIOR |=(0X01<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_EXTERNAL_INTERRUPT0)
		SET_BIT(ADCSRA,5);
		SFIOR |=(0X02<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_TIMER0_COMPARE_MATCH)
	 	SET_BIT(ADCSRA,5);
	 	SFIOR |=(0X03<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_TIMER0_OVERFLOW)
		SET_BIT(ADCSRA,5);
		SFIOR |=(0X04<<5)
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_TIMER1_COMPARE_MATCH_B)
	  	SET_BIT(ADCSRA,5);
	  	SFIOR |=(0X05<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_TIMER1_OVERFLOW)
	 	SET_BIT(ADCSRA,5);
	 	SFIOR |=(0X06<<5);
	#elif (ADC_CONVERSION_TRIGGER==ADC_CONVERSION_TIMER_CAPTURE_EVENT)
	 	SET_BIT(ADCSRA,5);
	 	SFIOR |=(0X07<<5);
    #endif /*ADC_CONVERSION_TRIGGER==ADC_CONVERSION_FREE_RUNNING*/
	
	/******************************prescaler selection***********************************/
	#if (ADC_PRESCALER == ADC_PRESCALER_2)
	ADCSRA |=0X01;
    #elif (ADC_PRESCALER == ADC_PRESCALER_4)
	ADCSRA |=0X02;
	#elif (ADC_PRESCALER == ADC_PRESCALER_8)
	ADCSRA |=0X03;
	#elif (ADC_PRESCALER == ADC_PRESCALER_16)
	ADCSRA |=0X04;
	#elif (ADC_PRESCALER == ADC_PRESCALER_32)
	ADCSRA |=0X05;
	#elif (ADC_PRESCALER == ADC_PRESCALER_64)
	ADCSRA |=0X06;
	#elif (ADC_PRESCALER == ADC_PRESCALER_128)
	ADCSRA |=0X07;
	#endif /*ADC_PRESCALER == ADC_PRESCALER_128*/


/******************************interrupt selection***********************************/	
	#if ( ADC_INTERRUPT_STATUS==ADC_INTERRUPT_ENABLE)
	 SET_BIT(ADCSRA,3);
	#elif ( ADC_INTERRUPT_STATUS==ADC_INTERRUPT_DISABLE)
   CLR_BIT(ADCSRA,3);
	#endif /* ADC_INTERRUPT_STATUS==ADC_INTERRUPT_DISABLE*/
	
	
	/******************************adgjust selection***********************************/
	#if (ADC_REG_ADJUST==ADC_RIGHT_ADJUST)
	  CLR_BIT(ADMUX,5);
    #elif (ADC_REG_ADJUST==ADC_LEFT_ADJUST)
	  SET_BIT(ADMUX,5);
	#endif /*ADC_REG_ADJUST==ADC_RIGHT_ADJUST*/
	
	/*******ENABLE ADC******/
	SET_BIT(ADCSRA,7);
}

void ADC_Read(void)
{
	/**Bit 6 – ADSC: ADC Start Conversion**/
	uint32 ADC_Digital_val=0;
	SET_BIT(ADCSRA,6);
	
	#if ( ADC_INTERRUPT_STATUS==ADC_INTERRUPT_DISABLE)
	 while (GET_BIT(ADCSRA,4)==0);
	
	   	#if (ADC_REG_ADJUST==ADC_RIGHT_ADJUST)
	   	 ADC_Digital_val =ADC_INPUT_16BIT_ACCESS;
			
	   	#elif (ADC_REG_ADJUST==ADC_LEFT_ADJUST)
	   	ADC_Digital_val =(ADCH <<2) |(ADCL >>6);
	   	#endif /*ADC_REG_ADJUST==ADC_RIGHT_ADJUST*/
		   
		     ADC_vinvalue_mv = (ADC_Digital_val *ADC_VREF_VALUE)/ADC_RESOLUTION;

   #endif
	
	
	
	
}
/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
