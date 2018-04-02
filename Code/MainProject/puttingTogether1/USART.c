/*
* USART.c
*
* Created: 3/5/2018 7:05:04 PM
*  Author: Lamees
*/

#include "USART.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "MICROCONFIG.h"

void USART_init()
{
	/* Turn on transmission and reception */
	SET_BIT(UCSRB,RXEN);	
	SET_BIT(UCSRB,TXEN);	
	SET_BIT(UCSRC,URSEL);	
	/* Use 8-bit char size */  
	CLEAR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ0);	
	SET_BIT(UCSRC,UCSZ1);
	/* Load lower 8-bits of the baud rate */
	UBRRL = (uint8)BAUD_PRESCALE;	
	/* Load upper 8-bits*/
	UBRRH = (uint8)(BAUD_PRESCALE >> 8);
}

uint8 receive()
{
	while (IS_BIT_CLEAR(UCSRA,RXC));        /* Wait till data is received */
	return(UDR);		/* Return the byte */
}
void send(uint8 ch)
{
	while (IS_BIT_CLEAR(UCSRA,UDRE));  /* Wait for empty transmit buffer */
	UDR = ch ;
}
