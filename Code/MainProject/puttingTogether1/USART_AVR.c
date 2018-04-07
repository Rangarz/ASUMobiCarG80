
	#include "USART_AVR.h"


	void UART_init(uint32 Buad_Rate)
	{
		 unsigned short  UBR = ((F_CPU /( 8.0 * Buad_Rate)) -1);
		 
		 /* enable the double speed mode */
		 UCSRA |=  (1<<U2X);
		 /* Enable Rx , TX */
		 UCSRB |= (1<<RXEN) | (1<<TXEN);
		 
		 UCSRC |= (1<<UCSZ1)  | (1<<URSEL) | (1<<UCSZ0);
		 UCSRB &=~(1<<UCSZ2);
		 
		 UBRRL = (uint8) UBR;
		 UBRRH = (uint8) ( UBR >> 8);
	}

	void UART_send(uint8 data)
	{
		while (!( UCSRA & (1<<UDRE))){}
		UDR = data;	
	}
	
	
	unsigned char  UART_receive(void)
	{
		while ( ! ( UCSRA & (1<<RXC))){}
			
			return UDR;
	}
	
	
	void UART_SendArr(const uint8 * ptr_c , uint16 size)
	{
		uint16 i=0;
		while(i<size)
		{
			UART_send(ptr_c[i]);
			i++;
		}	
	}
	
	void UART_RcvArr( uint8  * ptr_c , uint16 size)
	{
		uint16 i=0;
		while(i<size)
		{
			ptr_c[i]=UART_receive();
			i++;
		}
	}