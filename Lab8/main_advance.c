#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	CLKPR=(1<<CLKPCE);
	CLKPR=0b00000011; // set clk to 1Mhz
	DDRD=0xFF;
	DDRB=0xFF;

	TCCR0A = 0b10100011;
	TCCR0B = 0b00000101;
	TCCR2A = 0b10100011;
	TCCR2B = 0b00000101;

	OCR0A = 0;          //left wheel
	OCR0B = 0;
	OCR2A = 0;        //right wheel
	OCR2B = 0;
	//_delay_ms(1000);

	while(1){
		OCR0A = 3;          //left wheel
		OCR0B = 250;
		OCR2A = 94;        //right wheel
		OCR2B = 159;
		_delay_ms(3000);     //straight
	
		OCR0A = 0;          //left wheel
		OCR0B = 0;
		OCR2A = 94;        //right wheel
		OCR2B = 159;
		_delay_ms(1000);     //turn left
		
	}
}
