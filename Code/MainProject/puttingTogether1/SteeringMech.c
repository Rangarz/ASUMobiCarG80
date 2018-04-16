/*
 * SteeringMech.c
 *
 * Created: 4/7/2018 3:37:22 AM
 *  Author: Lamees
 */ 

#include "SteeringMech.h"

void Forward(float32 speed)
{
	set_speed_ML(speed);
	set_speed_MR(speed);
	set_direction_ML(CW);
	set_direction_MR(CW);
}
void Backward(float32 speed)
{
	set_speed_ML(speed);
	set_speed_MR(speed);
	set_direction_ML(ACW);
	set_direction_MR(ACW);
}
void ForwardRight(float32 speed)
{
	
	set_speed_ML(speed);
	set_speed_MR(0.5*speed);
	set_direction_ML(CW);
	set_direction_MR(CW);
	
}
void ForwardLeft(float32 speed)
{
	
	set_speed_MR(speed);
	set_speed_ML(speed*0.5);
	set_direction_MR(CW);
	set_direction_ML(CW);

}
void BackwardRight(float32 speed)
{
	
	set_speed_ML(speed);
	set_speed_MR(0.5*speed);
	set_direction_ML(ACW);
	set_direction_MR(ACW);
	
}
void BackwardLeft(float32 speed)
{
	
	set_speed_MR(speed);
	set_speed_ML(speed*0.5);
	set_direction_MR(ACW);
	set_direction_ML(ACW);

}
void RotateInPlace (float32 speed, uint8 direction)
{
	set_speed_ML(speed);
	set_speed_MR(speed);
	set_direction_ML(direction);
	set_direction_MR(direction);
}
void Break()
{
	set_speed_ML(0);
	set_speed_MR(0);
	/*
	set_direction_MR(0);
	set_direction_ML(0);
	*/
	
	/*
	CLEAR_BIT(PORTB, PB3);
	CLEAR_BIT(PORTD, PD7);
	*/
	
}


