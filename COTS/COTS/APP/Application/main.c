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
#include <avr/interrupt.h>





int main(void)
{
	IRQH_setGIE(INT_ENABLE);
	IRQ_setExtInterrupt();
	PORT_Init();
	LCD_Init();
	KeyPad_Init();

	uint8 val = 0;
  
    while (1) 
    {
		val = KeyPad_GetValue();
		
		if(val)
		{
			LCD_Clear();
			LCD_WriteData(val);
			val = 0;
		}
		
    }
}

ISR(INT0_vect)
{
	LED_Toggle(LED_0);
}