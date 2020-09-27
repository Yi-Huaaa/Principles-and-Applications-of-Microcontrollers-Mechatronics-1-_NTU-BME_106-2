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
int array []= {1,0,1,2,2,2,1,1,1,4,4,4,3,3,3,3,3,3,1,0,1,2,2,2,1,1,1,5,5,5,4,4,4,4,4,4,
	1,0,1,8,8,8,6,6,6,4,4,4,3,3,3,2,2,2,2,2,7,0,7,6,6,6,4,4,4,5,5,5,4,4,4,4,4,4};

int main(void)
{
	int stat = 0, idx = 0, count = 0;
	DDRB=0x7F; //0x7F=0b01111111
	DDRD=0x0;  //pinmode
	DDRC=0b00100000;
	PORTC=0xFF; //digitalwrrite
	//PORTD=0xFF;
	PORTB=0Xff;
	
	while (1){
		_delay_ms(1);
		count++;
		if (count > 150)
		{
			stat = array[idx++];
			count=0;
		}
		if(idx > 75)
			break;
		
		
		
		if(stat == 1){
			PORTB = 0b11000110;//C
			pccout (241);
		}
		else if(stat == 2){
			PORTB = 0b11000000;//D
			pccout (243);
		}
		else if(stat == 3){
			PORTB = 0b10000110;//E
			pccout (244);
		}
		else if(stat == 4){
			PORTB = 0b10001110;//F
			pccout (245);
		}
		else if(stat == 5){
			PORTB = 0b10000010;//G
			pccout (246);
		}
		else if(stat == 6){
			PORTB = 0b10001000;//A
			pccout (247);
		}
		else if(stat == 7){
			PORTB = 0b10000000;//B
			pccout (248);
		}
		else if(stat == 8){
			PORTB = 0b11000110;//C'
			pccout (249);
		}
		else
		{
			PORTB = 0xFF;
			_delay_ms(4);
		}
		
	}
}