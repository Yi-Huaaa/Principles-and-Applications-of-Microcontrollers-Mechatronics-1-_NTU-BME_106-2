#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void pccout(int t ){
	TCNT0=t;
	TCCR0A=0;
	TCCR0B=0b00000101;
	while((TIFR0&(1<<TOV0))==0);
	TCCR0B = 0;
	TIFR0 = (1<<TOV0);
	PORTC = PORTC^0b00100000; //用於控制是否輸出 ,開跟關
	//Time delay = n*p*T 不要取1024 prescaler 太大
}
//	unsigned char tone []= {262, 294,330,350,392,440,494};

int main(void)
{
	DDRB=0x7F; //0x7F=0b01111111
	DDRD=0x0;  //pinmode
	DDRC=0b00100000;
	PORTC=0xFF; //digitalwrrite
	PORTD=0xFF;
	PORTB=0Xff;

	
	while (1){
		
		if( ~PIND & 0b00000001){
			PORTB = 0b11000110;//C
			pccout (241);
		}
		else if( ~PIND & 0b00000010){
			PORTB = 0b11000000;//D
			pccout (243);
		}
		else if( ~PIND & 0b00000100){
			PORTB = 0b10000110;//E
			pccout (244);
		}
		else if( ~PIND & 0b00001000){
			PORTB = 0b10001110;//F
			pccout (245);
		}
		else if( ~PIND & 0b00010000){
			PORTB = 0b10000010;//G
			pccout (246);
		}
		else if( ~PIND & 0b00100000){
			PORTB = 0b10001000;//A
			pccout (247);	
		}
		else if( ~PIND & 0b01000000){
			PORTB = 0b10000000;//B
			pccout (248);
		}
		else if( ~PINB & 0b10000000){
			PORTB = 0b11000110;//C'
			pccout (249);
		}
	
	}
}