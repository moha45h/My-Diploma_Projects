/*
 * Calculator.c
 *
 * Created: 3/20/2024 11:07:21 AM
 * Author : Mohamed
 */ 

#include "STD.h"
#include "BIT_Math.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "DIO_Core.h"
#include "PORT_Core.h"


int main(void)
{
	uint16 key_val=0;
	uint16 num[10]={0};
	uint8 operation[5]={0};
	
	

    
    while (1) 
    {
			key_val=KeyPad_GetValue();
			
			if (key_val !=0)
			{
				if (key_val =='+'||key_val =='-'||key_val =='*'||key_val=='/')
				{
					
				    if (key_val>=0 && key_val <=9)
				    {
					   num[]+=key_val;
					}
				}

				
			}
		
		
		
    }
}

