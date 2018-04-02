/*
 * MotorDriver.c
 *
 * Created: 3/30/2018 1:43:55 PM
 *  Author: Lamees
 */ 

#include "MotorDriver.h"

void driver_init()
{
	CLEAR_BIT(DDRA,ML_IN1);
	CLEAR_BIT(DDRA,ML_IN2);
	CLEAR_BIT(DDRA,MR_IN1);
	CLEAR_BIT(DDRA,MR_IN2);
}
void set_direction_ML(uint8 direction)
{
	if(direction == CW)
	{
		CLEAR_BIT(PORTA, ML_IN1);
		SET_BIT(PORTA, ML_IN2);
	}
	else if (direction == ACW)
	{
		SET_BIT(PORTA, ML_IN1);
		CLEAR_BIT(PORTA, ML_IN2);
	} 
}
void set_direction_MR(uint8 direction)
{
	if(direction == CW)
	{
		CLEAR_BIT(PORTA, MR_IN1);
		SET_BIT(PORTA, MR_IN2);
	}
	else if (direction == ACW)
	{
		
		SET_BIT(PORTA, MR_IN1);
		CLEAR_BIT(PORTA, MR_IN2);
	}
}