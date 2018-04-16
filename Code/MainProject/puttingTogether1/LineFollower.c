/*
 * LineFollower.c
 *
 * Created: 4/16/2018 3:09:41 PM
 *  Author: Matt
 */
#include "LineFollower.h" 

void ForwardRightLF(float32 speed, float32 degree)
{
	set_speed_ML(speed);
	set_speed_MR(degree*speed);
	set_direction_ML(CW);
	set_direction_MR(CW);
}
void ForwardLeftLF(float32 speed, float32 degree)
{
	set_speed_MR(speed);
	set_speed_ML(speed*degree);
	set_direction_MR(CW);
	set_direction_ML(CW);
}
