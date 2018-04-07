

#ifndef USART_AVR_H_
#define USART_AVR_H_

	#include "MICROCONFIG.h"
	#include "STD_TYPES.h"
	#include "MACROS.h"
	void UART_init(uint32 Buad_Rate);

	void UART_send(uint8 data);

	
	uint8 UART_receive(void);

#endif /* USART_AVR_H_ */