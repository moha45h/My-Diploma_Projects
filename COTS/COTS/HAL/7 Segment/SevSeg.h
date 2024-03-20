/*
 * SevSeg.h
 *
 * Created: 3/20/2024 1:22:07 AM
 *  Author: Mohamed
 */ 


#ifndef SEVSEG_H_
#define SEVSEG_H_

static const uint8 SevenSegment_Values[10] = {0x7E , 0X0C , 0XB6 , 0X9E , 0XCC , 0XDA , 0XFA , 0X0E , 0XFE , 0XCE};

void SevenSegment_Init(void)
{
	DIO_PORTA->DDR = 0XFF;
	SET_BIT(DIO_PORTC->DDR , 6);
	SET_BIT(DIO_PORTC->DDR , 7);
}

void SevenSegment_DisplayDigit(uint8 Digit)
{
	SET_BIT(DIO_PORTC->PORT , 6);
	CLR_BIT(DIO_PORTC->PORT , 7);
	DIO_PORTA->PORT = SevenSegment_Values[Digit%10];
	_delay_ms(1);
	CLR_BIT(DIO_PORTC->PORT , 6);
	SET_BIT(DIO_PORTC->PORT , 7);
	DIO_PORTA->PORT = SevenSegment_Values[Digit/10];
	_delay_ms(1);
}



#endif /* SEVSEG_H_ */