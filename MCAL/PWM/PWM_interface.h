/*
 * PWM_interface.h
 *
 * Created: 17/03/2024 10:46:38 am
 *  Author: Ismail
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#define PWM_PRESCALER_1				0b00000001
#define PWM_PRESCALER_8				0b00000010
#define PWM_PRESCALER_64			0b00000011
#define PWM_PRESCALER_256			0b00000100
#define PWM_PRESCALER_1024			0b00000101

typedef enum{
	PWM_CHANNEL1_A=1,
	PWM_CHANNEL1_B
	}PWM1_CHANNEL_SEL;

typedef enum{
	PWM1_WGM_FAST_PWM=1,
	PWM1_WGM_PHASE_CORRECT
}PWM1_WGM_SEL;

typedef enum{
	PWM1_NON_INV=1,
	PWM1_INV
}PWM1_PIN_MODE;


	
typedef enum{
	PWM0_WGM_FAST_PWM=1,
	PWM0_WGM_PHASE_CORRECT
}PWM0_WGM_SEL;

typedef enum{
	PWM0_NON_INV=1,
	PWM0_INV
}PWM0_PIN_MODE;

typedef enum{
	PWM2_WGM_FAST_PWM=1,
	PWM2_WGM_PHASE_CORRECT
}PWM2_WGM_SEL;

typedef enum{
	PWM2_NON_INV=1,
	PWM2_INV
}PWM2_PIN_MODE;

typedef enum{
	PWM2_PRESCALER_1=1,
	PWM2_PRESCALER_8,
	PWM2_PRESCALER_32,
	PWM2_PRESCALER_64,
	PWM2_PRESCALER_128,
	PWM2_PRESCALER_256,
	PWM2_PRESCALER_1024
	}PWM2_PRESCALER;

void PWM_voidInitChannel_0		(PWM0_WGM_SEL copy_EnumWGM0,PWM0_PIN_MODE copy_EnumPIN0_MODE)						;
ErrState PWM_ErrStateGenerateChannel_0	(u8 copy_u8DutyCycle)		;
void PWM_voidStart_Channel_0	(u8 copy_u8Prescaler)		;

void PWM_voidInitChannel_1		(PWM1_CHANNEL_SEL copy_EnumChannel,PWM1_WGM_SEL copy_EnumWGM1,PWM1_PIN_MODE copy_EnumPIN1_MODE)											;
void PWM_voidGenerateChannel_1	(f32 copy_f32DutyCycle,u16 copy_u16FrequencyHZ,PWM1_CHANNEL_SEL copy_EnumChannel)	;
void PWM_voidStopPWMsignalChannel_1		(void)								;


void PWM_voidInitChannel_2		(PWM2_WGM_SEL copy_EnumWGM2,PWM2_PIN_MODE copy_EnumPIN2_MODE)						;
void PWM_voidGenerateChannel_2	(u8 copy_u8DutyCycle)		;
void PWM_voidStart_Channel_2	(PWM2_PRESCALER copy_EnumPrescaler)		;

#endif /* PWM_INTERFACE_H_ */