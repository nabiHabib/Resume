///
// Lab3.c
//
// Created: 06/09/2021 6:29 PM
// Author : Nabi Habib
//
#define F_CPU 16000000UL					// 16MHz clock from the debug processor used to match the micro controller frequency speed
#define BAUD 9600							// define baud
#define BAUDRATE (((F_CPU)/(BAUD*16UL))-1)	// set UBRR value for baud rate

#include <avr/io.h>
#include <util/delay.h>

unsigned char keychar[4][4] = {{'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','B'}, {'*','0','#','D'}};
											
void uart_init()							// function to initialize UART
{
	UBRR0H  = (BAUDRATE>>8);				// shift the register right by 8 bits
	UBRR0L  = BAUDRATE;						// set baud rate
	UCSR0B |= (1<<TXEN0)|(1<<RXEN0);		// enable receiver and transmitter
	UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);		// 8bit data format
	UCSR0C |= (0 << USBS0);					// stop bit
}

void PortPin_init()
{
	DDRD |= (1<<4|1<<5|1<<6|1<<7);          // sets rows as output 
	DDRB &= ~(1<<0|1<<1|1<<2|1<<3);         // sets column PB0 as input

	PORTD |= (1<<4|1<<5|1<<6|1<<7);         // sets rows as high
	PORTB |= (1<<0|1<<1|1<<2|1<<3);			// set column as pull up
}


// function to send data void
unsigned char UART_Tx(unsigned char data)
{
	_delay_ms(50);
	while(!(UCSR0A & (1 << UDRE0)));       // wait while register is free
	UDR0 = data;						   // load data in the register
}

unsigned char check()
{
	unsigned char keypad;
	for (int i = 0; i < 4; ++i)
	{
		PORTD &= ~(1<<(i+4));                   // Set row(k) low - one at a time (and check each column)
		for(int j = 0; j < 4; ++j)
		{
			while (!(PINB & (1 << j)))			// Check each column(j) to see which is pulled Low
			{
				_delay_ms(50);
				keypad = keychar[i][j];
				UART_Tx(keypad);
				_delay_ms(200);
			}
		}
		PORTD |= (1<<(i+4)); 					// Set row(i) high
	}
}

	
int main()
{
	uart_init();
	PortPin_init();

	while (1)
	{
		check();		
	}
}
// questions
// Can most of these functions be void functions?