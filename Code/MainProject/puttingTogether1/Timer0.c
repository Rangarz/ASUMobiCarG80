/*
 * Timer0.c
 *
 * Created: 3/27/2018 1:10:50 AM
 *  Author: Lamees
 */ 

#include "Timer0.h"
void Timer0_PC_PWMinit(void)
{
	TCNT0=0;	//count = 0 initially
	OCR0=0;		//compare match value = 0 initially
	/*TCCR0 |= (1<<WGM00) | (1<<COM01) | (1<<CS00);*/
	/*PC PWM Settings*/
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/* PC PWM Non-inverting Mode*/
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	/*Select prescalar=8*/
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS02);
	/*Setting pin OC0 to be input*/
	SET_BIT(DDRB,PB3);
}
void set_speed_ML(uint8 duty_cycle) //set_dutyCycle_Timer0 // takes decimal
{
	OCR0 = (uint8)  ( (duty_cycle/100.0) *255.0 + 0.5);
}



