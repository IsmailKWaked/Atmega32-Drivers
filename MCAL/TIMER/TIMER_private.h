/*
 * TIMER_private.h
 *
 * Created: 16/03/2024 10:30:58 am
 *  Author: Ismail
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0   *((volatile u8*)(0x53))

#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0


#define TCNT0   *((volatile u8*)(0x52))

#define OCR0	*((volatile u8*)(0x5C))

#define TIMSK   *((volatile u8*)(0x59))

#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define OCIE0	1
#define TOIE0	0


#define TIFR	*((volatile u8*)(0x58))


typedef struct
{
	u16 ICR1L;
	u16 OCR1BL;
	u16 OCR1AL;
	u16 TCNT1L;
	u8 TCCR1B;
	u8 TCCR1A;
	}TMR1;
	
#define TMR1_REG	((volatile TMR1*)(0x46))

//TCCR1A bits
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1A_FOC1B		2
#define TCCR1A_FOC1A		3
#define TCCR1A_COM1B0		4
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1A1		7

//TCCR1B bits
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4
#define TCCR1B_ICES1		6
#define TCCR1B_ICNC1		7

typedef struct
{
	u8	OCR2;
	u8	TCNT2;
	u8	TCCR2;
}TMR2;

#define TMR2_REG	((volatile TMR2*)(0x43))

//TCCR2 bits
#define TCCR2_FOC2	7
#define TCCR2_WGM20	6
#define TCCR2_COM21	5
#define TCCR2_COM20	4
#define TCCR2_WGM21	3
#define TCCR2_CS22	2
#define TCCR2_CS21	1
#define TCCR2_CS20	0

//Timer0 available Mode
#define TMR0_OVF_MODE	3
#define TMR0_CTC_MODE	4


#define TMR1_CTC_MODE	34
#define TMR1_OVF_MODE	78

#define TMR2_CTC_MODE	21
#define TMR2_OVF_MODE	32

#define STOP_TIMER_MSK			0b11111000

#endif /* TIMER_PRIVATE_H_ */