#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
int8_t segB[10] = {0b00000001, 0b01100111, 0b00010010, 0b01000010, 0b01100100, 0b01001000, 0b00001000, 0b01100011, 0x00, 0b01000000};
int8_t segD[10] = {0b00000001, 0b11001101, 0b00100100, 0b10000100, 0b11001000, 0b10010000, 0b00010000, 0b11000101, 0x00, 0b10000000};
void display(int n)
{
	n = n / 10;
	int t = n % 10;
	if (n > 40)
		n = 0;
	else if(n > 30)
		n = 10;
	else if(n < 10 || n > 20)
		n = 20;
	else
		n = 30;
}
int main(void)
{
	CLKPR=(1<<CLKPCE);
	CLKPR=0b00000011;
	DDRB = 0xff;
	DDRC = 0x00;
	DDRD = 0xff;
	for(int i; i<10 ; i++){
		PORTD = segB[i];
		PORTB = segB[i];
	}
	

	ADCSRA=0b10000111; // enable + prescaler
	ADMUX=0b01000000; // ref volt + channel
	
	int output;
	while (1) {
		
		ADCSRA |= (1<<ADIF); // clear ADIF
		ADCSRA |= (1<<ADSC); // start ADC
		while((ADCSRA & (1<<ADIF))==0); // wait for ADC done
		output = 0;
		output += ADCL;
		output += (0x03 & ADCH) * 256;
		display(output);
		_delay_ms(200);
	}
}                                                                                                                                                                                                                                                   