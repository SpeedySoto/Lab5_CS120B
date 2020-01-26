/*	Partner(s) Name & E-mail: David Wilson
 *	Lab Section: 023
 *	Assignment: Lab #5  Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Configures PortA as input
	DDRC = 0xFF; PORTC = 0x00; //Configures PortC as outputs
	unsigned char Fuel_Level_Value = 0x00;
	unsigned char Fuel_Level_Sensor = 0x00;
	unsigned char Low_Fuel = 0x00;
 
	while (1) 
    {
	Fuel_Level_Value = PINA;
		
		if(Fuel_Level_Value = 0x0F)
		{
			Fuel_Level_Sensor =0x16;
			Low_Fuel = 0x00;
		}
		if(Fuel_Level_Value = 0x0E)
		{
			Fuel_Level_Sensor =0x16;
			Low_Fuel = 0x00;
		}
		if(Fuel_Level_Value = 0x0D)
		{
			Fuel_Level_Sensor =0x16;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x0C)
		{
			Fuel_Level_Sensor =0x15;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x0B)
		{
			Fuel_Level_Sensor =0x15;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x0A)
		{
			Fuel_Level_Sensor =0x15;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x09)
		{
			Fuel_Level_Sensor =0x14;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x08)
		{
			Fuel_Level_Sensor =0x14;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x07)
		{
			Fuel_Level_Sensor =0x14;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x06)
		{
			Fuel_Level_Sensor =0x13;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x05)
		{
			Fuel_Level_Sensor =0x13;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x04)
		{
			Fuel_Level_Sensor =0x12;
			Low_Fuel = 0x00;
		}		
		if(Fuel_Level_Value = 0x03)
		{
			Fuel_Level_Sensor =0x12;
			Low_Fuel = 0x01;
		}		
		if(Fuel_Level_Value = 0x02)
		{
			Fuel_Level_Sensor =0x11;
			Low_Fuel = 0x01;
		}		
		if(Fuel_Level_Value = 0x01)
		{
			Fuel_Level_Sensor =0x11;
			Low_Fuel = 0x01;
		}		
		if(Fuel_Level_Value = 0x00)
		{
			Fuel_Level_Sensor =0x11;
			Low_Fuel = 0x01;
		}	
		
    }
	PORTC = Fuel_Level_Sensor|Low_Fuel;
}

