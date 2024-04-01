/*
 * GPT.c
 *
 * Created: 3/27/2024 10:52:25 PM
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
#include "GPT_Cfg.h"
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
 uint32 timer0_number_of_over;
 uint32 timer0_initValue;
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
void GPT_Init(void)
{
	/*******timer0 init ********/
	#if (TIMER_0_STATE==TIMER_ENABLE)
	
	   #if (TIMER_0_MODE==NORMAL_MODE)
	        CLR_BIT(TCCR0,3);
		    CLR_BIT(TCCR0,6);
	   
             #if (TIMER_0_INTERRUPT_STATE==INTERRUPT_ENABLED)
			    SET_BIT(TIMSK,0);
             #elif (TIMER_0_INTERRUPT_STATE==INTERRUPT_DISABLED)
			    CLR_BIT(TIMSK,0);
            #endif /*interrupt check*/
       #elif (TIMER_0_MODE==CTC_MODE)
	        CLR_BIT(TCCR0,3);
	        SET_BIT(TCCR0,6);
	    
	         #if (TIMER_0_INTERRUPT_STATE==INTERRUPT_ENABLED)
			 SET_BIT(TIMSK,2);
	    
	         #elif (TIMER_0_INTERRUPT_STATE==INTERRUPT_DISABLED)
			 CLR_BIT(TIMSK,2);
			 #endif /*interrupt check*/
       #endif /*(TIMER_0_MODE==NORMAL_MODE)*/
	   
	   #if (TIMER_0_PRESCALER==CLK_SRC_WITH_NO_PRESCALING)
	    TCCR0 |=0x01;
		#elif (TIMER_0_PRESCALER==CLK_SRC_PRESCALING_8)
		TCCR0 |=0x02;
	   #elif (TIMER_0_PRESCALER==CLK_SRC_PRESCALING_64)
	    TCCR0 |=0x03;
	   #elif (TIMER_0_PRESCALER==CLK_SRC_PRESCALING_256)
	    TCCR0 |=0x04;
	   #elif (TIMER_0_PRESCALER==CLK_SRC_PRESCALING_1024)
	    TCCR0 |=0x05;
       #endif /*choosing prescaler*/

    #endif /*(TIMER_0_STATE==TIMER_ENABLE)*/
	
	/***************************************Timer1 Initalization**********************************************/
	
 #if (TIMER_1_STATE==TIMER_ENABLE)
		
	#if (TIMER_1_MODE==NORMAL_MODE)
		    CLR_BIT(TCCR1A,0);
		    CLR_BIT(TCCR1A,1);
		    CLR_BIT(TCCR1B,3);
		    CLR_BIT(TCCR1B,4);
		
		#if (TIMER_1_INTERRUPT_STATE==INTERRUPT_ENABLED)
		     SET_BIT(TIMSK,2);//TOIE1
		    
		#elif (TIMER_1_INTERRUPT_STATE==INTERRUPT_DISABLED)
		      CLR_BIT(TIMSK,2);//TOIE1
		#endif /*interrupt check*/
		
  #elif (TIMER_1_MODE==CTC_MODE)
		    CLR_BIT(TCCR1A,0);
		    CLR_BIT(TCCR1A,1);
		    SET_BIT(TCCR1B,3);
		    CLR_BIT(TCCR1B,4);
		
		#if (TIMER_1_INTERRUPT_STATE==INTERRUPT_ENABLED)
		     SET_BIT(TIMSK,4);//OCIE1A
			 SET_BIT(TIMSK,3);//OCIE1B
		
		#elif (TIMER_1_INTERRUPT_STATE==INTERRUPT_DISABLED)
		    CLR_BIT(TIMSK,4);//OCIE1A
			CLR_BIT(TIMSK,3);//OCIE1B
		#endif /*interrupt check*/
  #endif /*(TIMER_1_MODE==CTC_MODE)*/
  
	 #if (TIMER_1_PRESCALER==CLK_SRC_WITH_NO_PRESCALING)
	 TCCR1B |=0x01;
	 #elif (TIMER_1_PRESCALER==CLK_SRC_PRESCALING_8)
	 TCCR1B |=0x02;
	 #elif (TIMER_1_PRESCALER==CLK_SRC_PRESCALING_64)
	 TCCR1B |=0x03;
	 #elif (TIMER_1_PRESCALER==CLK_SRC_PRESCALING_256)
	 TCCR1B |=0x04;
	 #elif (TIMER_1_PRESCALER==CLK_SRC_PRESCALING_1024)
	 TCCR1B |=0x05;
	 #endif /*choosing prescaler*/

#endif /*(TIMER_1_STATE==TIMER_ENABLE)*/

/**********************************Timer2 initialization **************************************/

	
	#if (TIMER_2_STATE==TIMER_ENABLE)
	
	#if (TIMER_2_MODE==NORMAL_MODE)

	
	#if (TIMER_2_INTERRUPT_STATE==INTERRUPT_ENABLED)
	//SET_BIT(TIMSK,2);//TOIE1
	
	#elif (TIMER_2_INTERRUPT_STATE==INTERRUPT_DISABLED)
	CLR_BIT(TIMSK,2);//TOIE1
	#endif /*interrupt check*/
	
	#elif (TIMER_2_MODE==CTC_MODE)

	
	#if (TIMER_2_INTERRUPT_STATE==INTERRUPT_ENABLED)
	//SET_BIT(TIMSK,4);//OCIE1A
	
	
	#elif (TIMER_2_INTERRUPT_STATE==INTERRUPT_DISABLED)
	//CLR_BIT(TIMSK,4);//OCIE1A

	#endif /*interrupt check*/
	#endif /*(TIMER_2_MODE==CTC_MODE)*/
	
		 #if (TIMER_2_PRESCALER==CLK_SRC_WITH_NO_PRESCALING)
		 TCCR2 |=0x01;
		 #elif (TIMER_2_PRESCALER==CLK_SRC_PRESCALING_8)
		 TCCR2 |=0x02;
		 #elif (TIMER_2_PRESCALER==CLK_SRC_PRESCALING_64)
		 TCCR2 |=0x03;
		 #elif (TIMER_2_PRESCALER==CLK_SRC_PRESCALING_256)
		 TCCR2 |=0x04;
		 #elif (TIMER_2_PRESCALER==CLK_SRC_PRESCALING_1024)
		 TCCR2 |=0x05;
		 #endif /*choosing prescaler*/

		 #endif /*(TIMER_2_STATE==TIMER_DisABLE)*/
	
}

void GPT_SetTime(void)
{
	uint32 mcu_clk_us =16000000/1000000;
	
	#if (TIMER_0_STATE==TIMER_ENABLE)
	  uint32 Timer0_Tick_Us =TIMER_0_PRESCALER/mcu_clk_us;
	   #if (TIMER_0_MODE==NORMAL_MODE)
          uint32 Time_ms =TIMER_0_COUNTED_MS;
		  uint32 timer0_total_ticks= (Time_ms*1000)/Timer0_Tick_Us;
		  timer0_number_of_over =timer0_total_ticks/256;
		  timer0_initValue= 256-(timer0_total_ticks%256);
		  TCNT0 =timer0_initValue;
		  if (timer0_total_ticks %256 !=0)
		  {
			  timer0_number_of_over++;
		  }
		  
		  
       #elif (TIMER_0_MODE==CTC_MODE)
       
       #endif /*(TIMER_0_MODE==NORMAL_MODE)*/

    #endif /*(TIMER_0_STATE==TIMER_ENABLE)*/
	
	
	#if (TIMER_1_STATE==TIMER_ENABLE)
   	  uint32 Timer1_Tick_Us =TIMER_1_PRESCALER/mcu_clk_us;
   	  #if (TIMER_1_MODE==CTC_MODE)
   	  uint32 Time1_ms =TIMER_1_COUNTED_MS;
	  uint32 Timer1_Total_ticks=(Time1_ms*1000)/ Timer1_Tick_Us;
	  OCR1A_16BIT_ACCESS =Timer1_Total_ticks-1;
      #endif
  #endif
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
