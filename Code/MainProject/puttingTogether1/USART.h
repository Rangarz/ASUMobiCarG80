/*
 * USART_Module.c
 *
 * Created: 3/5/2018 6:53:16 PM
 *  Author: Lamees
 */ 

#ifndef USART_H
#define USART_H

#include "MACROS.h"
#include "MICROCONFIG.h"
#include "STD_TYPES.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (9600 * 16UL)) - 1)

void USART_init();
uint8 receive();
void send(uint8 ch);

#endif


