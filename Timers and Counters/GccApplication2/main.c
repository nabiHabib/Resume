///
// Lab4.c
//
// Author: Nabi Habib
//
#define F_CPU 16000000UL                       // 16MHz clock from the debug processor used to match the micro controller frequency speed
#define BAUD 9600                              // Define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)       // Set UBRR value for baud rate

#include <avr/io.h>

// Use PORTB because that is where the LED resides
void init()												// normal time steps = 256, 1/16^6= 16 us, time steps*16us*prescaler >= the value we are trying to achieve. Change time steps to achieve wanted number
{
	TCCR0A |= (1 << WGM01);								// Set the Timer Mode to CTC
	TCCR0B |= (1 << CS02) | (1 << CS00);				// Set prescaler 1024 in order to achieve 10 ms and start timer
	OCR0A = 0x9B;										// Set value you want to count to (10 ms needs an N = 156.25 = 156 - 1 = 155 ) 
	OCR0B = 0x00;										// Duty cycle increments from 0 to 100%
	
	DDRB |= (1 << 5);									// Set output
	DDRB &= ~(1 << 7);									// Set input
	PORTB |= (1 << 7);									// Pin B7 set high
}

int main(void)
{
	init();
	
	while(1)
	{
		if(OCR0B != 0x00)
		{
			PORTB |= (1 << 5);							// Turns on and keeps the LED on when incrementing or decrementing
		}
		if(!(PINB & (1 << 7)) && (OCR0B < OCR0A))		// If the button is pushed and OCR0B hasnt equated to OCR0A, increment OCR0B. button pushed = 0 
		{
			++OCR0B;									// Increments LED
		}
		else if((PINB & (1 << 7)) && (OCR0B > 0))	// If buttons not pushed and OCR0B isnt zero, decrement OCR0B. button not pushed = 1
		{
			--OCR0B;									// Decrements LED
		}
		
		while( (TIFR0 & (1 << OCF0B) ) == 0){}			// wait for OCR0B overflow event
		TIFR0 |= (1 << OCF0B);							// reset the overflow flag between timer and the data in OCRoB
		PORTB &= ~(1 << 5);								// Turns off LED
		while ((TIFR0 & (1 << OCF0A)) == 0){}			// Wait for the overflow event
		TIFR0 |= (1 << OCF0A);							// reset the overflow flag between timer and the data in OCRoA
		
	}
}
