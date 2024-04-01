/*
 * COTS.c
 *
 * Created: 2/9/2024 9:26:56 PM
 * Author : Ali
 */ 


#define F_CPU 16000000U
#include "util/delay.h"
#include "PORT_Core.h"
#include "LED_Core.h"
#include "Button_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "Interrupt.h"
#include "ADC_Core.h"
#include "GPT.h"
#include <avr/interrupt.h>



void wrapperfunction(void)
{
			LED_Toggle(LED_0);
}

int main(void)
{
    uint8 val = 0;
    IRQH_setCallBacks(Timer_Counter1_Compare_Match_A_VECTOR_INDEX,wrapperfunction);
	PORT_Init();
	IRQH_setGIE(INT_ENABLE);
	GPT_Init();
	GPT_SetTime();
 
    while (1) 
    {	
    }
}



