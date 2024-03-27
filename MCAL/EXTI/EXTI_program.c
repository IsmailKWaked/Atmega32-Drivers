/*
 * EXTI_program.c
 *
 * Created: 03/03/2024 12:55:50 pm
 *  Author: Ismail
 */ 

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"



static	void (*PRV_EXTI_0_callBack)(void);
static	void (*PRV_EXTI_1_callBack)(void);
static	void (*PRV_EXTI_2_callBack)(void);



void EXTI_voidEnable	(EXTI_SRC_t copy_enumInterruptSRC,EXTI_SenseCTRL copy_enumSenseCTRL)
{
	switch(copy_enumInterruptSRC)
	{
		case EXTI_INT0:
		
		switch(copy_enumSenseCTRL)
		{
			case EXTI_RISEING_EDGE:
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR_REG,ISC01);
			CLR_BIT(MCUCR_REG,ISC00);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			CLR_BIT(MCUCR_REG,ISC01);
			SET_BIT(MCUCR_REG,ISC00);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC01);
			CLR_BIT(MCUCR_REG,ISC00);
			break;
		}
		
		SET_BIT(GICR_REG,INT0);
		
		break;
		
		case EXTI_INT1:
		
		switch(copy_enumSenseCTRL)
		{
			case EXTI_RISEING_EDGE:
			SET_BIT(MCUCR_REG,ISC11);
			SET_BIT(MCUCR_REG,ISC10);
			break;
			
			case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR_REG,ISC11);
			CLR_BIT(MCUCR_REG,ISC10);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			CLR_BIT(MCUCR_REG,ISC11);
			SET_BIT(MCUCR_REG,ISC10);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC11);
			CLR_BIT(MCUCR_REG,ISC10);
			break;
		}
		
		SET_BIT(GICR_REG,INT1);
		break;
		
		
		case EXTI_INT2:
		
		switch(copy_enumSenseCTRL)
		{
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR_REG,ISC2);
			break;
			
			case EXTI_RISEING_EDGE:
			SET_BIT(MCUCSR_REG,ISC2);
			break;
			
			default:
			break;
		}
		
		SET_BIT(GICR_REG,INT2);
		break;
	}
}

void EXTI_voidDisable	(EXTI_SRC_t copy_enumInterruptSRC)
{
	switch(copy_enumInterruptSRC)
	{
		case EXTI_INT0:
		CLR_BIT(GICR_REG,INT0);
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR_REG,INT1);
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR_REG,INT2);
		break;
	}
}




void EXTI_void_SetINT0_callback_func(void (*INT0_callback)(void))
{
	if (INT0_callback!=NULL)
	{		
		PRV_EXTI_0_callBack=INT0_callback;
	}
}

void EXTI_void_SetINT1_callback_func(void (*INT1_callback)(void))
{
	if (INT1_callback!=NULL)
	{
		PRV_EXTI_1_callBack=INT1_callback;
	}
}

void EXTI_void_SetINT2_callback_func(void (*INT2_callback)(void))
{
	if (INT2_callback!=NULL)
	{
		PRV_EXTI_2_callBack=INT2_callback;
	}
}



void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	PRV_EXTI_0_callBack();
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	PRV_EXTI_1_callBack();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	PRV_EXTI_2_callBack();
}