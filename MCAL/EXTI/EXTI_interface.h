/*
 * EXTI_interface.h
 *
 * Created: 03/03/2024 12:31:14 pm
 *  Author: Ismail
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_INT0,		//PD2
	EXTI_INT1,		//PD3
	EXTI_INT2
	
	}EXTI_SRC_t;
	
typedef enum
{
	EXTI_RISEING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
	
	}EXTI_SenseCTRL;

void EXTI_voidEnable	(EXTI_SRC_t copy_enumInterruptSRC,EXTI_SenseCTRL copy_enumSenseCTRL);

void EXTI_voidDisable	(EXTI_SRC_t copy_enumInterruptSRC);

void EXTI_void_SetINT0_callback_func(void (*INT0_callback)(void));
void EXTI_void_SetINT1_callback_func(void (*INT1_callback)(void));
void EXTI_void_SetINT2_callback_func(void (*INT2_callback)(void));

#endif /* EXTI_INTERFACE_H_ */