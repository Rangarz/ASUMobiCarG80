/*
 * puttingTogether1.c
 *
 * Created: 3/29/2018 12:54:21 PM
 *  Author: Lamees
 */ 


#include "puttingTogether1.h"

int main(void)
{
	init();
	SET_BIT(DDRA,PA4);
	while(1)
	{
		uint8 cmd = UART_receive();
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
			case STOP:
			Break();
			break;
		}
		
	}
}

void init()
{
	Timer0_PC_PWMinit();
	Timer2_PC_PWMinit();
	driver_init();	
	UART_init(9600);
}