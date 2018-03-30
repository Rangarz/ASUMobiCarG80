/*
 * puttingTogether1.c
 *
 * Created: 3/29/2018 12:54:21 PM
 *  Author: Lamees
 */ 

#include "puttingTogether1.h"

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
	set_direction_MR(0);
}


int main(void)
{
	/*Adjust char size please*/
	init();
    while(1)
    {
		uint8 cmd = receive();
		switch(cmd)
		{
			case FORWARD:
				Forward(1);
				break;
			case BACK:
				Backward(1);
				break;
			case FORWARDLEFT:
				ForwardLeft(1);
				break;
			case FORWARDRIGHT:
				ForwardRight(1);
				break;
			case BACKLEFT:
				BackwardLeft(1);
				break;
			case BACKRIGHT:
				BackwardRight(1);
				break;
			case STOP:
				Break();
				break;
		}
		
    }
}

void init()
{
	USART_init(USART_BAUDRATE);
	Timer0_PC_PWMinit();
	driver_init();	
}