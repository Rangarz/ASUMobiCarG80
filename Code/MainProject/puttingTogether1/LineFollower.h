/*
 * LineFollower.h
 *
 * Created: 4/16/2018 3:09:22 PM
 *  Author: Matt
 */ 



#ifndef LINEFOLLOWER_H_
#define LINEFOLLOWER_H_

#include "puttingTogether1.h"

#define mid PD5
#define left PD6
#define right PD4
//PD4 = right
//PD5 = mid
//PD6 = left

void ForwardRightLF(float32 speed, float32 degree); //degree between 0 and 1
void ForwardLeftLF(float32 speed, float32 degree);




#endif /* LINEFOLLOWER_H_ */