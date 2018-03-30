/*
 * MotorDriver.h
 *
 * Created: 3/30/2018 1:36:03 PM
 *  Author: Lamees
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

#include "STD_TYPES.h"
#include "MACROS.h"
#include "MICROCONFIG.h"

#define ML_IN1 PA0
#define ML_IN2 PA1
#define MR_IN1 PA2
#define MR_IN2 PA3
#define CW 1
#define ACW 0


void set_direction_ML(uint8 direction);
void set_direction_MR(uint8 direction);
void driver_init();





#endif /* MOTORDRIVER_H_ */