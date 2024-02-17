#define F_CPU 16000000U
#include <util/delay.h>
#include "LED_Core.h"
#include "Button_Core.h"

void SevSeg_init(void);
void SevSeg_display(uint8 num);

static const sev_seg[10]={0x7E,0x0C,0xB6,0x9E,0xCC,0xDA,0xFA,0x0E,0xFE,0xCE};
int main(void)
{
    
SevSeg_init();

    while (1) 
    {	
		SevSeg_display(58);
	}

		
}

void SevSeg_init(void){
	DIO_PORTA->DDR=0xff;
	SET_BIT(DIO_PORTC->DDR,6);
	SET_BIT(DIO_PORTC->DDR,7);
	
}

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

