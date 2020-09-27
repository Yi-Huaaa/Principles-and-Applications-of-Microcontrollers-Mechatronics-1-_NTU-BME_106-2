#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0xFF; //0xFF=0b11111111
	DDRD=0x0;  //pinmode
	DDRC=0x0;
	PORTC=0xFF; //digitalwrrite
	PORTD=0xFF;
	PORTB=0Xff;

	
	
	
	while (1){
		
		if( ~PIND & 0b00000001){
			PORTB = 0b11111001;//1
		}
		 if( ~PIND & 0b00000010){
			PORTB = 0b10010010;//2
		}
		 if( ~PIND & 0b00000100){
			PORTB = 0b10010001;//3
		}
		 if( ~PIND & 0b00001000){
			PORTB = 0b11001001;//4
		}
		 if( ~PIND & 0b00010000){
			PORTB = 0b10000101;//5
		}
		 if( ~PIND & 0b00100000){
			PORTB = 0b10000100;//6
		}
		 if( ~PIND & 0b01000000){
			PORTB = 0b11110001;//7
		}
		 if( !(PINC & 0b00001000)){
			PORTB = 0b00000000;//8
		}
		 if( !(PINC & 0b00010000)){
			PORTB = 0b00000001;//9   10000001
		}
		 if( !(PINC & 0b00100000)){
			PORTB = 0b00100000;//0
		}
	}
}