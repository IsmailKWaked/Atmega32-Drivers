/*
 * TIMER_program.c
 *
 * Created: 16/03/2024 10:31:22 am
 *  Author: Ismail
 */
#include "../../STD_TYPES.h" 
#include "../../BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

//static u16 PRV_CTCcounter=0;
static void (*PRV_pFunCallBackOVF_TMR0)(void)=NULL;
static void (*PRV_pFunCallBackCTC_TMR0)(void)=NULL;

static void (*PRV_pFunCallBackOVF_TMR1)(void)=NULL;
static void (*PRV_pFunCallBackCTC_TMR1)(void)=NULL;

static void (*PRV_pFunCallBackOVF_TMR2)(void)=NULL;
static void (*PRV_pFunCallBackCTC_TMR2)(void)=NULL;


void TMR0_voidInit(void)	
{
	#if TMR0_MODE	==	TMR0_OVF_MODE
	//select timer normal mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	//load the preload value
	TCNT0=TMR0_PRELOAD_VAL;
	
	//enable the timer0 interrupt
	SET_BIT(TIMSK,TOIE0);
	
	#elif TMR0_MODE	==	TMR0_CTC_MODE
	//select timer CTC Mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//apply the Compare match value
	OCR0=TMR0_COMPARE_VAL;
	
	//enable the CTC interrupt source
	SET_BIT(TIMSK,OCIE0);
	#endif
}

void TMR0_voidSetTimerPreloadVAL(u8 copy_u8LoadedVal)
{
	TCNT0=copy_u8LoadedVal;
}

u8 TMR0_u8GetTimerCNTR(void)
{
	return TCNT0;
}

void	TMR0_voidStart			(TMR0_PRESCALER copy_EnumPrescaler)	
{
	TCCR0&=STOP_TIMER_MSK;
	TCCR0|=copy_EnumPrescaler;
}

void TMR0_voidStop(void)	
{
	TCCR0&=STOP_TIMER_MSK;
}


void TMR0_voidSetCallBack(TMR0_MODES copy_EnumIntSource,void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!=NULL)
	{
		switch(copy_EnumIntSource)
		{
			case TMR0_NORMAL_OVF_MODE:
			PRV_pFunCallBackOVF_TMR0=copy_pFunAction;
			break;
			case TMR0_NORMAL_CTC_MODE:
			PRV_pFunCallBackCTC_TMR0=copy_pFunAction;
			break;		
		}
	}
	else
	{
		//return error state
	}
}





void TMR1_voidInit(void)
{
	#if TMR1_MODE	==	TMR1_CTC_MODE
	//activate CTC mode for timer 1
	CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM11);
	SET_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM13);
	
	TMR1_REG->OCR1AL=TMR1_COMPARE_VAL;
	
	SET_BIT(TIMSK,OCIE1A);
	
	#elif	TMR1_MODE	==	TMR1_OVF_MODE
	//activate CTC mode for timer 1
	CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM13);
	
	TMR1_REG->TCNT1L=TMR1_PRELOAD_VAL;
	
	SET_BIT(TIMSK,TOIE1);
	
	#endif
}

void	TMR1_voidSetTimerPreloadVAL	(u16 copy_u16LoadedVal)
{
	TMR1_REG->TCNT1L=copy_u16LoadedVal;
}
void	TMR1_voidSetOutputCMPVAL	(u16 copy_u16OutputCMPVal)
{
	TMR1_REG->OCR1AL=copy_u16OutputCMPVal;
}
u16		TMR1_u16GetTimerCNTR(void)
{
	return TMR1_REG->TCNT1L;
}

void	TMR1_voidStart(TMR1_PRESCALER copy_EnumPrescaler)
{
	TMR1_REG->TCCR1B&=STOP_TIMER_MSK;
	TMR1_REG->TCCR1B|=copy_EnumPrescaler;
}

void TMR1_voidStop(void)
{
	TMR1_REG->TCCR1B&=STOP_TIMER_MSK;
}

void TMR1_voidSetCallBack(TMR1_MODES copy_EnumIntSource,void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!=NULL)
	{
		switch(copy_EnumIntSource)
		{
			case TMR1_NORMAL_CTC_MODE:
			PRV_pFunCallBackCTC_TMR1=copy_pFunAction;
			break;
			
			case TMR1_NORMAL_OVF_MODE:
			PRV_pFunCallBackOVF_TMR0=copy_pFunAction;
			break;
			
		}
	}
	else
	{
		
	}
}

void	TMR2_voidInit				(void)
{
	#if	TMR2_MODE	==	TMR2_CTC_MODE
	//set Timer 2 mode to CTC
	SET_BIT(TMR2->TCCR2,TCCR2_WGM21);
	CLR_BIT(TMR2->TCCR2,TCCR2_WGM20);
	//assign the output compare value 
	TMR2->OCR2=TMR2_COMPARE_VAL;
	//enable the OCR interrupt for timer 2
	SET_BIT(TIMSK,OCIE2);
	#elif	TMR2_MODE	==	TMR2_OVF_MODE
	//set Timer 2 mode to CTC
	CLR_BIT(TMR2->TCCR2,TCCR2_WGM21);
	CLR_BIT(TMR2->TCCR2,TCCR2_WGM20);
	//assign the output compare value
	TMR2->TCNT2=TMR2_PRELOAD_VAL;
	//enable the OCR interrupt for timer 2
	SET_BIT(TIMSK,TOIE2);
	#endif
}
void	TMR2_voidSetTimerPreloadVAL	(u8 copy_u8LoadedVal)
{
	TMR2->TCNT2=copy_u8LoadedVal;
}
void	TMR2_voidSetOutputCMPVAL	(u8 copy_u8OutputCMPVal)
{
	TMR2->OCR2=copy_u8OutputCMPVal;
}
u8		TMR2_u8GetTimerCNTR			(void)
{
	return TMR2->TCNT2;
}
void	TMR2_voidStart				(TMR2_PRESCALER copy_EnumPrescaler)
{
	TMR2->TCCR2&=STOP_TIMER_MSK;
	TMR2->TCCR2|=copy_EnumPrescaler;
	
}
void	TMR2_voidStop				(void)
{
	TMR2->TCCR2&=STOP_TIMER_MSK;
}
void	TMR2_voidSetCallBack		(TMR2_MODES copy_EnumIntSource,void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!=NULL)
	{
		switch(copy_EnumIntSource)
		{
			case TMR2_NORMAL_CTC_MODE:
			PRV_pFunCallBackCTC_TMR2=copy_pFunAction;
			break;
			case TMR2_NORMAL_OVF_MODE:
			PRV_pFunCallBackOVF_TMR2=copy_pFunAction;
			break;
		}
	}
	else
	{
		//ERROR
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16OVFcnt=0;
	local_u16OVFcnt++;
	if (TMR0_OVF_COUNTER==local_u16OVFcnt)
	{
		local_u16OVFcnt=0;
		//TCNT0=TMR0_PRELOAD_VAL;
		if (PRV_pFunCallBackOVF_TMR0!=NULL)
		{
			PRV_pFunCallBackOVF_TMR0();
		}
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16CTCcnt=0;
	local_u16CTCcnt++;
	if (TMR0_CTC_COUNTER==local_u16CTCcnt)
	{
		local_u16CTCcnt=0;
		if (PRV_pFunCallBackCTC_TMR0!=NULL)
		{					   
			PRV_pFunCallBackCTC_TMR0();
		}
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u16 local_u16CTCcnt=0;
	local_u16CTCcnt++;
	if (TMR1_CTC_COUNTER==local_u16CTCcnt)
	{
		local_u16CTCcnt=0;
		if (PRV_pFunCallBackCTC_TMR1!=NULL)
		{
			PRV_pFunCallBackCTC_TMR1();
		}
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	static u16 local_u16CTCcnt=0;
	local_u16CTCcnt++;
	if (TMR1_OVF_COUNTER==local_u16CTCcnt)
	{
		local_u16CTCcnt=0;
		if (PRV_pFunCallBackOVF_TMR1!=NULL)
		{
			PRV_pFunCallBackOVF_TMR1();
		}
	}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u16 local_u16CTCcnt=0;
	local_u16CTCcnt++;
	if (TMR2_CTC_COUNTER==local_u16CTCcnt)
	{
		local_u16CTCcnt=0;
		if (PRV_pFunCallBackCTC_TMR2!=NULL)
		{
			PRV_pFunCallBackCTC_TMR2();
		}
	}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 local_u16CTCcnt=0;
	local_u16CTCcnt++;
	if (TMR2_OVF_COUNTER==local_u16CTCcnt)
	{
		local_u16CTCcnt=0;
		if (PRV_pFunCallBackOVF_TMR2!=NULL)
		{
			PRV_pFunCallBackOVF_TMR2();
		}
	}
}