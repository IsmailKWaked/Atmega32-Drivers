/*
 * TIMER_interface.h
 *
 * Created: 16/03/2024 10:30:41 am
 *  Author: Ismail
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef enum
{
	TMR0_NORMAL_OVF_MODE=1,
	TMR0_NORMAL_CTC_MODE
	}TMR0_MODES;


typedef enum
{
	TMR0_PRESCALER_1=1,
	TMR0_PRESCALER_8,
	TMR0_PRESCALER_64,
	TMR0_PRESCALER_256,
	TMR0_PRESCALER_1024
	}TMR0_PRESCALER;

typedef enum
{
	TMR1_NORMAL_OVF_MODE=1,
	TMR1_NORMAL_CTC_MODE
}TMR1_MODES;

typedef enum
{
	TMR1_PRESCALER_1=1,
	TMR1_PRESCALER_8,
	TMR1_PRESCALER_64,
	TMR1_PRESCALER_256,
	TMR1_PRESCALER_1024
}TMR1_PRESCALER;

typedef enum
{
	TMR2_NORMAL_OVF_MODE=1,
	TMR2_NORMAL_CTC_MODE
}TMR2_MODES;

typedef enum
{
	TMR2_PRESCALER_1=1,
	TMR2_PRESCALER_8,
	TMR2_PRESCALER_32,
	TMR2_PRESCALER_64,
	TMR2_PRESCALER_128,
	TMR2_PRESCALER_256,
	TMR2_PRESCALER_1024
}TMR2_PRESCALER;





void	TMR0_voidInit			(void)	;
void	TMR0_voidSetTimerPreloadVAL	(u8 copy_u8LoadedVal);
void	TMR0_voidSetOutputCMPVAL(u8 copy_u8OutputCMPVal);
u8		TMR0_u8GetTimerCNTR		(void);
void	TMR0_voidStart			(TMR0_PRESCALER copy_EnumPrescaler)	;
void	TMR0_voidStop			(void)	;
void	TMR0_voidSetCallBack	(TMR0_MODES copy_EnumIntSource,void(*copy_pFunAction)(void));

void	TMR1_voidInit				(void);
void	TMR1_voidSetTimerPreloadVAL	(u16 copy_u16LoadedVal);
void	TMR1_voidSetOutputCMPVAL	(u16 copy_u16OutputCMPVal);
u16		TMR1_u16GetTimerCNTR			(void);
void	TMR1_voidStart				(TMR1_PRESCALER copy_EnumPrescaler)	;
void	TMR1_voidStop				(void)	;
void	TMR1_voidSetCallBack		(TMR1_MODES copy_EnumIntSource,void(*copy_pFunAction)(void));

void	TMR2_voidInit				(void);
void	TMR2_voidSetTimerPreloadVAL	(u8 copy_u8LoadedVal);
void	TMR2_voidSetOutputCMPVAL	(u8 copy_u8OutputCMPVal);
u8		TMR2_u8GetTimerCNTR			(void);
void	TMR2_voidStart				(TMR2_PRESCALER copy_EnumPrescaler)	;
void	TMR2_voidStop				(void)	;
void	TMR2_voidSetCallBack		(TMR2_MODES copy_EnumIntSource,void(*copy_pFunAction)(void));


#endif /* TIMER_INTERFACE_H_ */