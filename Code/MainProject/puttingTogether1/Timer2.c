/*
 * Timer1.c
 *
 * Created: 3/29/2018 4:04:28 PM
 *  Author: Lamees
 */ 

#include "Timer2.h"
void Timer2_PC_PWMinit(void)
{
	TCNT2=0;	//count = 0 initially
	OCR2=0;		//compare match value = 0 initially
	/*PC PWM Settings*/
	SET_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	/* PC PWM Non-inverting Mode*/
	SET_BIT(TCCR2,COM21);
	CLEAR_BIT(TCCR2,COM20);
	/*Set prescalar to 8*/
	SET_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
	CLEAR_BIT(TCCR2,CS20);
	/*Setting pin OC2 to be input*/
	SET_BIT(DDRD, PD7);
}
void set_speed_MR(uint8 duty_cycle) //set_dutyCycle_Timer2 // takes decimal
{
	OCR2 = (uint8)  ( (duty_cycle/100.0) *255.0 + 0.5);
}


