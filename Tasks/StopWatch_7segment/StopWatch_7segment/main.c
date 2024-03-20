/*
 * StopWatch_7segment.c
 *
 * Created: 2/13/2024 11:19:43 AM
 * Author : Mohamed
 */ 

#include "StopWatch.h"
uint8 counter=0;

int main(void)
{

 
   uint8 temp=0;
    sevseg_init();
	buttons_init();
	SET_BIT(DIO_PORTC->DDR,5);
	
  while(1) {
		 sec_button=GET_BIT(DIO_PORTD->PIN,2);
		 min_button=GET_BIT(DIO_PORTD->PIN,3);
		start_button=GET_BIT(DIO_PORTD->PIN,4);
		//reset_button=GET_BIT(DIO_PORTD->PIN,5);
		 if (min_button==0)
		 {
			 			 counter++;
			 			 while(temp==0)
			 			 {
				 			 temp=min_button=GET_BIT(DIO_PORTD->PIN,3);
			 			 }
			 			 temp=0;
			 			 
	                     CLR_BIT(DIO_PORTC->PORT,6);
	                     SET_BIT(DIO_PORTC->PORT,7);
	                     DIO_PORTA->PORT=sev_seg[counter/10];
	                     _delay_ms(1);
	                    				  
	                     }
		else if (sec_button==0)
				  {
				  counter++;
				  while(temp==0)
				  {
					  temp=sec_button=GET_BIT(DIO_PORTD->PIN,2);
				  }
				  temp=0;
					  
	               SET_BIT(DIO_PORTC->PORT,6);
	               CLR_BIT(DIO_PORTC->PORT,7);
	               DIO_PORTA->PORT=sev_seg[counter%10];

	               _delay_ms(1);
				  }
			  
			  
             else if(start_button==0)
		 	 {
		     counter--;
			 while(temp==0)
			 {
				  temp=sec_button=GET_BIT(DIO_PORTD->PIN,4);
			 }
			 temp=0;
			 
			 SET_BIT(DIO_PORTC->PORT,6);
			 CLR_BIT(DIO_PORTC->PORT,7);
			 DIO_PORTA->PORT=sev_seg[counter%10];
			 CLR_BIT(DIO_PORTC->PORT,6);
			 SET_BIT(DIO_PORTC->PORT,7);
			 DIO_PORTA->PORT=sev_seg[counter/10];
			 _delay_ms(1); 
			
			 if(counter==0)
			 {
				 SET_BIT(DIO_PORTC->PORT,5);
				 _delay_ms(500);
				 CLR_BIT(DIO_PORTC->PORT,5);
			 }
		 }
  }
}
		 
	 	

	




