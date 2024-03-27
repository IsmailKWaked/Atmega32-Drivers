/*
 * DIO_interface.h
 *
 *  Created on: 29/02/2024
 *      Author: Ismail
 */

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_SetPinDirection(u8 PortNo, u8 PinNo, u8 direction)
{
	if(direction == DIO_OUTPUT)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			SET_BIT(DDRA, PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(DDRB, PinNo);
			break;
		case DIO_PORTC:
			SET_BIT(DDRC, PinNo);
			break;
		case DIO_PORTD:
			SET_BIT(DDRD, PinNo);
			break;
		}
	}
	else if(direction == DIO_INPUT)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA, PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB, PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC, PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD, PinNo);
			break;
		}
	}
}

void DIO_SetPinValue(u8 PortNo, u8 PinNo, u8 value)
{
	if(value == DIO_HIGH)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			SET_BIT(PORTA, PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(PORTB, PinNo);
			break;
		case DIO_PORTC:
			SET_BIT(PORTC, PinNo);
			break;
		case DIO_PORTD:
			SET_BIT(PORTD, PinNo);
			break;
		}
	}
	else if(value == DIO_LOW)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, PinNo);
			break;
		}
	}
}

u8   DIO_GetPinValue(u8 PortNo, u8 PinNo)
{
	u8 pin_value = 0;

	switch(PortNo)
	{
	case DIO_PORTA:
		pin_value = GET_BIT(PINA, PinNo );
		break;
	case DIO_PORTB:
		pin_value = GET_BIT(PINB, PinNo);
		break;
	case DIO_PORTC:
		pin_value = GET_BIT(PINC, PinNo );
		break;
	case DIO_PORTD:
		pin_value = GET_BIT(PIND, PinNo);
		break;
	}
	return pin_value;
}

void DIO_SetPinInputPULLUP(u8 PortNo, u8 PinNo)
{
	switch(PortNo)
	{
		case DIO_PORTA:
		DIO_SetPinDirection	(DIO_PORTA,PinNo,DIO_INPUT);
		DIO_SetPinValue		(DIO_PORTA,PinNo,DIO_HIGH);
		break;
		
		case DIO_PORTB:
		DIO_SetPinDirection	(DIO_PORTB,PinNo,DIO_INPUT);
		DIO_SetPinValue		(DIO_PORTB,PinNo,DIO_HIGH);
		break;
		
		case DIO_PORTC:
		DIO_SetPinDirection	(DIO_PORTC,PinNo,DIO_INPUT);
		DIO_SetPinValue		(DIO_PORTC,PinNo,DIO_HIGH);
		break;
		
		case DIO_PORTD:
		DIO_SetPinDirection	(DIO_PORTD,PinNo,DIO_INPUT);
		DIO_SetPinValue		(DIO_PORTD,PinNo,DIO_HIGH);
		break;
	}
}

void DIO_SetPortDirection(u8 PortNo, u8 direction)
{
	if(direction==DIO_INPUT)
	{

		switch(PortNo)
		{
		case DIO_PORTA:
			DDRA = 0x00 ;
			break;
		case DIO_PORTB:
			DDRB = 0x00 ;
			break;
		case DIO_PORTC:
			DDRC = 0x00 ;
			break;
		case DIO_PORTD:
			DDRD = 0x00 ;
			break;
		}

	}
	else if(direction==DIO_OUTPUT)
	{

		switch(PortNo)
		{
		case DIO_PORTA:
			DDRA = 0xFF ;
			break;
		case DIO_PORTB:
			DDRB = 0xFF ;
			break;
		case DIO_PORTC:
			DDRC = 0xFF ;
			break;
		case DIO_PORTD:
			DDRD = 0xFF ;
			break;
		}

	}
	else
	{
		switch(PortNo)
		{
			case DIO_PORTA:
			DDRA = direction ;
			break;
			case DIO_PORTB:
			DDRB = direction ;
			break;
			case DIO_PORTC:
			DDRC = direction ;
			break;
			case DIO_PORTD:
			DDRD = direction ;
			break;
		}
	}
}

void DIO_SetPortValue(u8 PortNo, u8 value)
{
	switch(PortNo)
	{
	case DIO_PORTA:
		PORTA = value ;
		break;
	case DIO_PORTB:
		PORTB = value ;
		break;
	case DIO_PORTC:
		PORTC = value ;
		break;
	case DIO_PORTD:
		PORTD = value ;
		break;
	}
}

u8   DIO_GetPortValue(u8 PortNo)
{
	u8 port_value = 0;

	switch(PortNo)
	{
	case DIO_PORTA:
		port_value = PINA ;
		break;
	case DIO_PORTB:
		port_value = PINB ;
		break;
	case DIO_PORTC:
		port_value = PINC ;
		break;
	case DIO_PORTD:
		port_value = PIND ;
		break;
	}

	return port_value;
}

void DIO_TogglePinValue(u8 PortNo,u8 PinNo)
{
	switch(PortNo)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA,PinNo);
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB,PinNo);
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC,PinNo);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD,PinNo);
		break;
	}
	}

