/*
 * puttingTogether1.c
 *
 * Created: 3/29/2018 12:54:21 PM
 *  Author: Lamees
 */ 


#include "puttingTogether1.h"
#define BLACK 0
#define WHITE 1

int main(void)
{
	init();
	CLEAR_BIT(DDRA,PA5);  //sets PA5 input IR
	
	/* LINE TRACKING
	CLEAR_BIT(DDRD, PD6); 
	CLEAR_BIT(DDRD, PD5); //PD5 INPUT
	CLEAR_BIT(DDRD, PD4);
	
	volatile uint8 currState=FORWARD;
	volatile float32 speedNow=30,degreeNow=0.1;
	
	*/ 

	volatile float distance = 1;
	volatile float distanceSoFar = 0;
	volatile char lastState = 0;
	volatile char newState;
	volatile float circum = 0.06;
	volatile float angle=360;
	volatile float angleSoFar=0;
	volatile float angleInc=42;
	volatile char mode = 1;
	while(1)
	{	
		//AccMov
		if(mode==0)
		{
			_delay_ms(1000);
			Forward(90);
			while(distanceSoFar < distance)
			{
				if(IS_BIT_SET(PINA, PA5))
				{
					newState = 1;	
				}
				else
				{
					newState = 0;
				}
			
				if(newState != lastState && lastState == BLACK)
				{
					distanceSoFar += circum;
				}
				lastState = newState;
			}
			Break();
			_delay_ms(99999999);
		}
		else
		{
			_delay_ms(1000);
			RotateInPlace(35,CW,ACW);
			while(angleSoFar < angle)
			{
				if(IS_BIT_SET(PINA, PA5))
				{
					newState = 1;
				}
				else
				{
					newState = 0;
				}
				
				if(newState != lastState && lastState == BLACK)
				{
					angleSoFar += angleInc;
				}
				lastState = newState;
			}
			Break();
			_delay_ms(99999999);
			
		}
		//AccMoveEnd
		
		
		
		//PD4 = right
		//PD5 = mid
		//PD6 = left
		
		//REAL line follower mode code starts here
		/*
		if(((IS_BIT_CLEAR(PIND, right))&&( IS_BIT_CLEAR(PIND, left))&&(IS_BIT_CLEAR(PIND, mid)))||((IS_BIT_CLEAR(PIND, mid))&&(IS_BIT_SET(PIND, right))&&(IS_BIT_SET(PIND, left))))
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
		
		*/
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
		
		/*
		//Remote control mode code starts here
		
		
		 
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
		
	
	//RC bluetooth ends here
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



//Other Infinity 
/*ForwardRightWithDegree(90, 0.3);
_delay_ms(1000);
Break();
RotatePls(70);
moveForward(1);
RotatePlsOtherDir(70);
ForwardLeftWithDegree(90,0.3);
_delay_ms(1000);
Break();
RotatePls(40);
moveForward(1.5);*/