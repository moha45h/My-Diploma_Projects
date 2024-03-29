/*
 * Battery Voltage Measurement.c
 *
 * Created: 3/27/2024 12:59:16 PM
 * Author : Mohamed
 */ 

#include "BVM.h"

int main(void)
{
   PORT_Init();
   ADC_Init();
   LCD_Init();
   
   uint32 value=0;
   
   
   
    while (1) 
    {
		value=Voltage_Measure();
		LCD_WriteInteger(value);
    }
}

