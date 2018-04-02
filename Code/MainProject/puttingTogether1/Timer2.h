/*
 * Timer1.h
 *
 * Created: 3/29/2018 4:04:07 PM
 *  Author: Lamees
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "MICROCONFIG.h"
#include "STD_TYPES.h"
#include "MACROS.h"

void Timer2_PC_PWMinit(void); //phase correct pwm initialization
void set_speed_MR(uint8 duty_cycle); //duty cycle to be used (0->1) /*Outputs on PD7*/ 
// the right motor --> PD7





#endif /* TIMER2_H_ */