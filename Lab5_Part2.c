
/*	Partner(s) Name & E-mail: David Wilson
 *	Lab Section: 023
 *	Assignment: Lab #5  Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>

enum states {start, increment, decrement, reset, hold, holdincrement, holddecrement, holdreset} state;
unsigned char button1 = 0x00;
unsigned char button2 = 0x00;

void transition()
{
	//transitions
	switch(state)
	{
		case start:
		state = hold;
		break;
		
		case hold:
		if(!button1 && button2)
		state = increment;
		if(button1 && !button2)
		state = decrement;
		if(button1 && button2)
		state = reset;
		if(!button1 && !button2)
		state = hold;
		break;
		
		case increment:
		state = holdincrement;
		break;
		
		case holdincrement:
		if(!button1 && button2)
		state = holdincrement;
		else
		state = hold;
		break;
		
		case decrement:
		state = holddecrement;
		break;
		
		case holddecrement:
		if(button1 && !button2)
		state = holddecrement;
		else
		state = hold;
		break;
		
		case reset:
		state = holdreset;
		break;
		
		case holdreset:
		if(button1 && button2)
		state = holdreset;
		else
		state = hold;
		break;
		
		default:
		state = start;
		break;
	}
	
	//actions
	switch(state)
	{
		case start:
		break;
		
		case hold:
		break;
		
		case increment:
		if(PORTC != 0x09)
		PORTC = PORTC + 0x01;
		break;
		
		case holdincrement:
		break;
		
		case decrement:
		if(PORTC != 0x00)
		PORTC = PORTC - 0x01;
		break;
		
		case holddecrement:
		break;
		
		case reset:
		PORTC = 0x00;
		break;
		
		case holdreset:
		break;
		
		default:
		break;
	}
}

int main(void)
{
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	state = start;
	PORTC = 0x07; //initial starting value for PORTC
	
	while (1)
	{
		button1 = ~PINA & 0x01;
		button2 = ~PINA & 0x02;
		transition();
	}
	return 0;
}
