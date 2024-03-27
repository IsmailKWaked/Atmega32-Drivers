/*
 * DIO_interface.h
 *
 *  Created on: 29/02/2024
 *      Author: Ismail
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_



#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define DIO_OUTPUT  1
#define DIO_INPUT   0


#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7


#define DIO_HIGH	1
#define DIO_LOW		0



void DIO_SetPinDirection(u8 PortNo, u8 PinNo, u8 direction);
void DIO_SetPinValue(u8 PortNo, u8 PinNo, u8 value);

u8   DIO_GetPinValue(u8 PortNo, u8 PinNo);

void DIO_SetPinInputPULLUP(u8 PortNo, u8 PinNo);

void DIO_SetPortDirection(u8 PortNo, u8 direction);
void DIO_SetPortValue(u8 PortNo, u8 value);
u8   DIO_GetPortValue(u8 PortNo);


void DIO_TogglePinValue(u8 PortNo,u8 PinNo);


#endif /* DIO_DIO_INTERFACE_H_ */
