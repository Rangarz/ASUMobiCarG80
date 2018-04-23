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
	SET_BIT(DDRA,PA5);  //sets PA4 as output
	
	//
	CLEAR_BIT(DDRD, PD6); 
	CLEAR_BIT(DDRD, PD5); //PD5 INPUT
	CLEAR_BIT(DDRD, PD4);
	
	volatile uint8 currState=FORWARD;
	volatile float32 speedNow=30,degreeNow=0.1;
	
	//
	   
	while(1)
	{	
		//PD4 = right
		//PD5 = mid
		//PD6 = left
		
		//REAL line follower mode code starts here
		if(((IS_BIT_CLEAR(PIND, right))&&( IS_BIT_CLEAR(PIND, left))&&(IS_BIT_CLEAR(PIND, mid)))/*||((IS_BIT_SET(PIND, right))&&(IS_BIT_SET(PIND, left))&&(IS_BIT_SET(PIND, mid)))*/||((IS_BIT_CLEAR(PIND, mid))&&(IS_BIT_SET(PIND, right))&&(IS_BIT_SET(PIND, left))))
		{
			currState= FORWARD;
			Forward(speedNow);
		}
		if(((IS_BIT_CLEAR(PIND, mid))&&(IS_BIT_CLEAR(PIND, left))&&(IS_BIT_SET(PIND, right))) || ((IS_BIT_SET(PIND, mid))&&(IS_BIT_CLEAR(PIND, left))&&(IS_BIT_SET(PIND, right))))
		{
			currState= FORWARDLEFT;
			ForwardLeftLF(speedNow,degreeNow);
		}
		if(((IS_BIT_CLEAR(PIND, mid))&&(IS_BIT_CLEAR(PIND, right))&&(IS_BIT_SET(PIND, left))) || ((IS_BIT_SET(PIND, mid))&&(IS_BIT_CLEAR(PIND, right))&&(IS_BIT_SET(PIND, left))))	
		{
			currState= FORWARDRIGHT;
			ForwardRightLF(speedNow,degreeNow);
		}
		if(IS_BIT_SET(PIND, mid) && IS_BIT_CLEAR(PIND, right) && IS_BIT_CLEAR(PIND, left))
		{
			Break();
		}
		if((IS_BIT_SET(PIND, right))&&(IS_BIT_SET(PIND, left))&&(IS_BIT_SET(PIND, mid)))
		{
			if(currState==FORWARD)
			{
				Forward(speedNow);
			}
			if(currState==FORWARDLEFT)
			{
				ForwardLeftLF(speedNow,degreeNow);
			}
			if(currState==FORWARDRIGHT)
			{
				ForwardRightLF(speedNow,degreeNow);
			}
		}
		//REAL END
		
		
		//Line follower mode code starts here
		/*
		if(IS_BIT_CLEAR(PIND, PD5) && IS_BIT_SET(PIND, PD4) && IS_BIT_SET(PIND, PD6))
		{
			currState = FORWARD;
			Forward(70);
		}
		//Left on, right off
		else if(IS_BIT_CLEAR(PIND, PD6) && IS_BIT_SET(PIND, PD4))
		{
			if(currState != FORWARDLEFT)
			{
				currState = FORWARDLEFT;
				turnLeftSpeed = 0.5;
			}
			ForwardLeftLF(70, turnLeftSpeed);
			if(turnLeftSpeed > 0.3)
			{
				turnLeftSpeed -= 0.05; 
			}
		}
		else if(IS_BIT_SET(PIND, PD6) && IS_BIT_CLEAR(PIND, PD4))
		{
			if(currState != FORWARDRIGHT)
			{
				currState = FORWARDRIGHT;
				turnRightSpeed = 0.5;
			}
			ForwardRightLF(70, turnRightSpeed);
			if(turnRightSpeed > 0.3)
			{
				turnRightSpeed -= 0.05;
			}
		}
		
		else if(IS_BIT_SET(PIND, PD6) && IS_BIT_SET(PIND, PD5) && IS_BIT_SET(PIND, PD4))
		{
			Break();
		}
		else
		{
			 Break();
		}
		*/
		
		//Remote control mode code starts here
		
		
	/*	 
		uint8 cmd = UART_receive();
		switch(cmd)
		{
			case FORWARD:
			Forward(90);
			break;
			case BACK:
			Backward(90);
			break;
			case FORWARDLEFT:
			ForwardLeft(90);
			break;
			case FORWARDRIGHT:
			ForwardRight(90);
			break;
			case BACKLEFT:
			BackwardLeft(90);
			break;
			case BACKRIGHT:
			BackwardRight(90);
			break;
			case STOP:
			Break();
			break;
		}
		*/
		
	}
}

void init()
{
	Timer0_PC_PWMinit();
	Timer2_PC_PWMinit();
	driver_init();	
	UART_init(9600);
}