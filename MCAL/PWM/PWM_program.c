/*
 * PWM_program.c
 *
 * Created: 17/03/2024 10:47:06 am
 *  Author: Ismail
 */ 

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "PWM_config.h"
#include "PWM_interface.h"
#include "PWM_private.h"

static PWM0_WGM_SEL		PWM0_WGM;
static PWM0_PIN_MODE	PWM0_MODE;

static PWM1_WGM_SEL		PWM1_WGM;
static PWM1_PIN_MODE	PWM1_MODE;

static PWM2_WGM_SEL		PWM2_WGM;
static PWM2_PIN_MODE	PWM2_MODE;


void PWM_voidInitChannel_0		(PWM0_WGM_SEL copy_EnumWGM0,PWM0_PIN_MODE copy_EnumPIN0_MODE)
{
	switch(copy_EnumWGM0)
	{
		case PWM0_WGM_FAST_PWM:
		//choose fast PWM mode
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		PWM0_WGM=PWM0_WGM_FAST_PWM;
		break;
		
		case PWM0_WGM_PHASE_CORRECT:
		//choose phase correct mode
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		PWM0_WGM=PWM0_WGM_PHASE_CORRECT;
		break;
	}
	
	switch(copy_EnumPIN0_MODE)
	{
		case PWM0_NON_INV:
		//choose non inverting mode
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		PWM0_MODE=PWM0_NON_INV;
		break;
		
		case PWM0_INV:
		//choose non inverting mode
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		PWM0_MODE=PWM0_INV;
		break;
	}
	
}

ErrState PWM_ErrStateGenerateChannel_0(u8 copy_u8DutyCycle)
{
	
	u8 local_u8ErrState=PASS;
	if (copy_u8DutyCycle<=100)
	{
		if (PWM0_WGM==PWM0_WGM_FAST_PWM)
		{
			switch(PWM0_MODE)
			{
				case PWM0_NON_INV:
				OCR0=(((u16)copy_u8DutyCycle*256)/100);
				break;
				
				case PWM0_INV:
				OCR0=255-(256*copy_u8DutyCycle/100);
				break;
			}
		}
		
		else if (PWM0_WGM==PWM0_WGM_PHASE_CORRECT)
		{
			switch(PWM0_MODE)
			{
				case PWM0_NON_INV:
				OCR0=(255*copy_u8DutyCycle/100)-1;
				break;
				
				case PWM0_INV:
				OCR0=255-(255*copy_u8DutyCycle/100)-1;
				break;
			}
		}
		

	}
	else
	{
		local_u8ErrState=FAIL;
		//error
	}
	return local_u8ErrState;
}


void PWM_voidStart_Channel_0(u8 copy_u8Prescaler)
{
			TCCR0&=PWM_STOP_TIMER_MSK;
			TCCR0|=copy_u8Prescaler;
}


void PWM_voidInitChannel_1		(PWM1_CHANNEL_SEL copy_EnumChannel,PWM1_WGM_SEL copy_EnumWGM1,PWM1_PIN_MODE copy_EnumPIN1_MODE)
{
	switch(copy_EnumWGM1)
	{
		case PWM1_WGM_FAST_PWM:
		//Fast PWM mode with ICR1 Top value
		CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM10);
		SET_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM11);
		SET_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM12);
		SET_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM13);
		PWM1_WGM=PWM1_WGM_FAST_PWM;
		break;
		
		case PWM1_WGM_PHASE_CORRECT:
		//Phase correct mode with ICR1 Top value
		CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM10);
		SET_BIT(TMR1_REG->TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM12);
		SET_BIT(TMR1_REG->TCCR1B,TCCR1B_WGM13);
		PWM1_WGM=PWM1_WGM_PHASE_CORRECT;
		break;
	}
	
	if (copy_EnumPIN1_MODE==PWM1_NON_INV)
	{
		PWM1_MODE=PWM1_NON_INV;
		switch (copy_EnumChannel)
		{	
			case PWM_CHANNEL1_A:
			//choose non inverting mode on OC1A pin
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1A1);
			CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1A0);
			break;
			case PWM_CHANNEL1_B:
			//choose non inverting mode on OC1B pin
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1B1);
			CLR_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1B0);
			break;
		}
	}
	else if (copy_EnumPIN1_MODE==PWM1_INV)
	{
		PWM1_MODE=PWM1_INV;
		switch(copy_EnumChannel)
		{
			case PWM_CHANNEL1_A:
			//choose inverting mode on OC1A pin
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1A1);
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1A0);
			break;
			case PWM_CHANNEL1_B:
			//choose inverting mode on OC1B pin
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1B1);
			SET_BIT(TMR1_REG->TCCR1A,TCCR1A_COM1B0);
			break;
		}
	}
	

	
}
void PWM_voidGenerateChannel_1	(f32 copy_f32DutyCycle,u16 copy_u16FrequencyHZ,PWM1_CHANNEL_SEL copy_EnumChannel)
{
	if (copy_f32DutyCycle<=100)
	{
		
		TMR1_REG->ICR1L=((1000000UL/(copy_u16FrequencyHZ*4))-1);
		
		if (PWM1_WGM==PWM1_WGM_FAST_PWM)
		{
			if (PWM1_MODE==PWM1_NON_INV)
			{
				switch(copy_EnumChannel)
				{
					case PWM_CHANNEL1_A:
					TMR1_REG->OCR1AL=((copy_f32DutyCycle*(TMR1_REG->ICR1L+1))/100);
					break;
					
					case PWM_CHANNEL1_B:
					TMR1_REG->OCR1BL=((copy_f32DutyCycle*(TMR1_REG->ICR1L+1))/100);
					break;
				}
			}
			else if (PWM1_MODE==PWM1_INV)
			{
				switch(copy_EnumChannel)
				{
					case PWM_CHANNEL1_A:
					TMR1_REG->OCR1AL=(TMR1_REG->ICR1L)-((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100);
					break;
					
					case PWM_CHANNEL1_B:
					TMR1_REG->OCR1BL=(TMR1_REG->ICR1L)-((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100);
					break;
				}
			}
		}
		else if (PWM1_WGM==PWM1_WGM_PHASE_CORRECT)
		{
			if (PWM1_MODE==PWM1_NON_INV)
			{
				switch(copy_EnumChannel)
				{
					case PWM_CHANNEL1_A:
					TMR1_REG->OCR1AL=((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100)+1;
					break;
					
					case PWM_CHANNEL1_B:
					TMR1_REG->OCR1BL=((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100)+1;
					break;
				}
			}
			else if (PWM1_MODE==PWM1_INV)
			{
				switch(copy_EnumChannel)
				{
					case PWM_CHANNEL1_A:
					TMR1_REG->OCR1AL=(TMR1_REG->ICR1L)-((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100);
					break;
					
					case PWM_CHANNEL1_B:
					TMR1_REG->OCR1BL=(TMR1_REG->ICR1L)-((copy_f32DutyCycle*(TMR1_REG->ICR1L))/100);
					break;
				}
			}
		}
		
		//set prescaler to 64
		TMR1_REG->TCCR1B&=PWM_STOP_TIMER_MSK;
		TMR1_REG->TCCR1B|=PWM_PRESCALER_64;	
	}
}


void PWM_voidStopPWMsignalChannel_1		(void)
{
		TMR1_REG->TCCR1B&=PWM_STOP_TIMER_MSK;
		
}




void PWM_voidInitChannel_2		(PWM2_WGM_SEL copy_EnumWGM2,PWM2_PIN_MODE copy_EnumPIN2_MODE)		 
{
	switch(copy_EnumWGM2)
	{
		case PWM2_WGM_FAST_PWM:
		//choose fast PWM mode
		SET_BIT(TMR2_REG->TCCR2,TCCR2_WGM20);
		SET_BIT(TMR2_REG->TCCR2,TCCR2_WGM21);
		PWM2_WGM=PWM2_WGM_FAST_PWM;
		break;
		
		case PWM2_WGM_PHASE_CORRECT:
		//choose phase correct mode
		SET_BIT(TMR2_REG->TCCR2,TCCR2_WGM20);
		CLR_BIT(TMR2_REG->TCCR2,TCCR2_WGM21);
		PWM2_WGM=PWM2_WGM_PHASE_CORRECT;
		break;
	}
	
	switch(copy_EnumPIN2_MODE)
	{
		case PWM2_NON_INV:
		//choose non inverting mode
		CLR_BIT(TMR2_REG->TCCR2,TCCR2_COM20);
		SET_BIT(TMR2_REG->TCCR2,TCCR2_COM21);
		PWM2_MODE=PWM2_NON_INV;
		break;
		
		case PWM2_INV:
		//choose non inverting mode
		SET_BIT(TMR2_REG->TCCR2,TCCR2_COM20);
		SET_BIT(TMR2_REG->TCCR2,TCCR2_COM21);
		PWM2_MODE=PWM2_INV;
		break;
	}
}

void PWM_voidGenerateChannel_2	(u8 copy_u8DutyCycle)
{
	if (copy_u8DutyCycle<=100)
	{
		if (PWM2_WGM==PWM2_WGM_FAST_PWM)
		{
			switch(PWM2_MODE)
			{
				case PWM2_NON_INV:
				TMR2_REG->OCR2=(((u16)copy_u8DutyCycle*256)/100)-1;
				break;
				
				case PWM2_INV:
				TMR2_REG->OCR2=255-(256*copy_u8DutyCycle/100);
				break;
			}
		}
		
		else if (PWM2_WGM==PWM2_WGM_PHASE_CORRECT)
		{
			switch(PWM2_MODE)
			{
				case PWM2_NON_INV:
				TMR2_REG->OCR2=(255*copy_u8DutyCycle/100)-1;
				break;
				
				case PWM2_INV:
				TMR2_REG->OCR2=255-(255*copy_u8DutyCycle/100)-1;
				break;
			}
		}
	}
}

void PWM_voidStart_Channel_2	(PWM2_PRESCALER copy_EnumPrescaler)
{
	TMR2_REG->TCCR2&=PWM_STOP_TIMER_MSK;
	TMR2_REG->TCCR2|=copy_EnumPrescaler;
}