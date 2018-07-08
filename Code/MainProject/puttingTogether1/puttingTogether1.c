/*
 * puttingTogether2.c
 *
 * Created: 7/6/2018 1:48:24 PM
 *  Author: Matt
 */ 
#include "puttingTogether1.h"
void moveForward(float);
void RotatePls(float angleReq);
void RotatePlsOtherDir(float angleReq);
int main(void)
{
	//Initialize general AVR
	init();
	
	uint8 mode_g = UART_receive();
	while (1)
	{
		//Choose mode
		switch(mode_g)
		{
			//RC Driving
			case '1':
			while(1)
			{
				uint8 rc_cmd = UART_receive();
				switch(rc_cmd)
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
					default:
					mode_g = rc_cmd;
				}
				if(mode_g == rc_cmd)
					break;
			}
			break;
			//Tracking
			case '2':
			Break();
			//Line follower mode code starts here
			
			//PD4 = right
			//PD5 = mid
			//PD6 = left
			
			CLEAR_BIT(DDRD, PD6);
			CLEAR_BIT(DDRD, PD5); //PD5 INPUT
			CLEAR_BIT(DDRD, PD4);
			
			volatile uint8 currState=FORWARD;
			volatile float32 speedNow=45,degreeNow=0.1;
			while(1)
			{
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
				}
			}
			break;
			//AccMove
			case '3':
			Break();
			CLEAR_BIT(DDRA,PA5);  //sets PA5 input IR
			volatile float distance = 0;
			volatile float distanceSoFar = 0;
			volatile char lastState = 0;
			volatile char newState;
			volatile float circum = 0.06;
			volatile float angle = 0;
			volatile float angleSoFar=0;
			volatile float angleInc=60;
			volatile char temp =  0;
			
			uint8 acc_cmd = UART_receive();
			while (1)
			{
				switch(acc_cmd)
				{
					case 'D':
						;
						temp = UART_receive();
						while(temp >= '0' && temp <= '9')
						{
							distance *= 10;
							distance += temp - '0';
							temp = UART_receive();
						}
						acc_cmd = temp;
						Forward(90);
						while(distanceSoFar < distance/100)
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
						distanceSoFar = 0;
						distance = 0;
						Break();
					break;
					case 'B':
					;
					temp = UART_receive();
					while(temp >= '0' && temp <= '9')
					{
						distance *= 10;
						distance += temp - '0';
						temp = UART_receive();
					}
					acc_cmd = temp;
					Backward(90);
					while(distanceSoFar < distance/100)
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
					distanceSoFar = 0;
					distance = 0;
					Break();
					break;
					case 'A':
						;
						temp = UART_receive();
						while(temp >= '0' && temp <= '9')
						{
							angle *= 10;
							angle += temp - '0';
							temp = UART_receive();
						}
						acc_cmd = temp;
						RotateInPlace(60,CW,ACW);
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
						angle = 0;
						angleSoFar = 0;
						Break();
					break;
					case 'H':
					//Infinity
					ForwardLeftWithDegree(70,0.5);
					_delay_ms(2500);
					ForwardRightWithDegree(70,0.4);
					_delay_ms(3000);
					Break();
					_delay_ms(5*1000);
					//Rectangle
					moveForward(1);
					
					RotatePls(90);
					moveForward(1);
					RotatePls(90);
					moveForward(1);
					RotatePls(90);
					moveForward(1);
					RotatePls(90);
					_delay_ms(5*1000);
					
					//Circle
					
					ForwardRightWithDegree(70, 0.5);
					_delay_ms(5000);
					Break();
					acc_cmd = UART_receive();
					break;
					case '/':
						acc_cmd= UART_receive();
					break;
					default:
					mode_g = acc_cmd;
				}
				if(mode_g == acc_cmd)
				break;
			}
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
void moveForward(float disReq)
{
	float disCov = 0;
	char newState;
	char lastState = 0;
	float circum = 0.06;
	
	Forward(90);
	while(disCov < disReq)
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
			disCov += circum;
		}
		lastState = newState;
	}
	Break();
}
void RotatePls(float angleReq)
{
	float angleCov = 0;
	char lastState = 0;
	char newState;
	char angInc = 38;
	RotateInPlace(60,CW,ACW);
	while(angleCov < angleReq)
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
			angleCov += angInc;
		}
		lastState = newState;
	}

	Break();
}
void RotatePlsOtherDir(float angleReq)
{
	float angleCov = 0;
	char lastState = 0;
	char newState;
	char angInc = 38;
	RotateInPlace(60,ACW,CW);
	while(angleCov < angleReq)
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
			angleCov += angInc;
		}
		lastState = newState;
	}

	Break();
}