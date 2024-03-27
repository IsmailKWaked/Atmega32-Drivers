/*
 * EXTI_private.h
 *
 * Created: 03/03/2024 1:00:37 pm
 *  Author: Ismail
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

//		MCU ctrl register
#define MCUCR_REG		*((volatile u8*)(0x55))

#define ISC11			3
#define ISC10			2
#define ISC01			1
#define ISC00			0

//		MCU ctrl & status register
#define MCUCSR_REG		*((volatile u8*)(0x54))

#define ISC2			6

//		General Interrupt ctrl register
#define GICR_REG		*((volatile u8*)(0x5B))

#define INT1			7
#define INT0			6
#define INT2			5

//		General Interrupt flag register
#define GIFR_REG		*((volatile u8*)(0x5A))

#define INTF1			7
#define INTF0			6
#define INTF2			5



#endif /* EXTI_PRIVATE_H_ */