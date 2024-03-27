/*
 * GI_program.c
 *
 * Created: 03/03/2024 1:57:39 pm
 *  Author: Ismail
 */ 

#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "GI_interface.h"
#include "GI_register.h"

void GI_voidEnable	(void)
{
	SET_BIT(SREG_REG,I);
}

void GI_voidDisable	(void)
{
	CLR_BIT(SREG_REG,I);
}