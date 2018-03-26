/*
 * IncFile1.h
 *
 * Created: 3/27/2018 1:07:48 AM
 *  Author: Lamees
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include "MICROCONFIG.h"
#include "STD_TYPES.h"
#include "MACROS.h"

void Timer0_PC_PWMinit(void); //phase correct pwm initialization
void set_dutyCycle_Timer0(uint8 duty_cycle); //duty cycle to be used (in percentage)

#endif /* TIMER0_H_*/