/*
 * SteeringMech.h
 *
 * Created: 4/7/2018 3:36:58 AM
 *  Author: Lamees
 */ 


#ifndef STEERINGMECH_H_
#define STEERINGMECH_H_


#include <avr/io.h>
#include "MACROS.h"
#include "MICROCONFIG.h"
#include "STD_TYPES.h"
#include "Timer0.h"
#include "Timer2.h"
#include "USART_AVR.h"
#include "Commands.h"
#include "MotorDriver.h"

void Forward(float32 speed);
void Backward(float32 speed);
void ForwardRight(float32 speed);
void ForwardLeft(float32 speed);
void BackwardRight(float32 speed);
void BackwardLeft(float32 speed);
void RotateInPlace (float32 speed, uint8 direction);
void Break();




#endif /* STEERINGMECH_H_ */