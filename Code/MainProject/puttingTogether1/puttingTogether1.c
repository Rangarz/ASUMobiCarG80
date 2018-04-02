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
	/*
	set_speed_ML(speed);
	set_speed_MR(0.5*speed);
	set_direction_ML(CW);
	set_direction_MR(CW);
	*/
}
void ForwardLeft(float32 speed)
{
	/*
	set_speed_MR(speed);
	set_speed_ML(speed*0.5);
	set_direction_MR(CW);
	set_direction_ML(CW);
	*/
}
void BackwardRight(float32 speed)
{
	/*
	set_speed_ML(speed);
	set_speed_MR(0.5*speed);
	set_direction_ML(ACW);
	set_direction_MR(ACW);
	*/
}
void BackwardLeft(float32 speed)
{
	/*
	set_speed_MR(speed);
	set_speed_ML(speed*0.5);
	set_direction_MR(ACW);
	set_direction_ML(ACW);
	*/
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
	/*
	set_speed_ML(0);
	set_speed_MR(0);
	set_direction_MR(0);
	set_direction_ML(0);
	*/
	
	/*
	CLEAR_BIT(PORTB, PB3);
	CLEAR_BIT(PORTD, PD7);
	*/
	
	TOGGLE_BIT(PORTA, PA4);
}


int main(void)
{
	/*Adjust char size please*/
	init();
	//
	CLEAR_BIT(DDRA,PA4);
	 
	while(1)
	{				
		uint8 cmd = receive();
		
		switch(cmd)
		{
			case FORWARD:
				Forward(100);
				break;
			case BACK:
				Backward(100);
				break;
			case FORWARDLEFT:
				ForwardLeft(100);
				break;
			case FORWARDRIGHT:
				ForwardRight(100);
				break;
			case BACKLEFT:
				BackwardLeft(100);
				break;
			case BACKRIGHT:
				BackwardRight(100);
				break;
				
			default:
				Break();
		}
		
    }
}

void init()
{
	USART_init();
	Timer0_PC_PWMinit();
	Timer2_PC_PWMinit();
	driver_init();	
}