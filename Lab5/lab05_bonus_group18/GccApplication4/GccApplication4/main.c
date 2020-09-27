#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	 DDRB=0xff; //0xFF=0b11111111
	 DDRD=0x0f;  //pinmode
	 PORTB=0Xff;
	 unsigned char array[4][4]={{0b01111000,0b00011001,0b11111001,0b01000000},{0b00000000,0b00010010,0b00100100,0b00001000},{0b00010000,0b00000010,0b00110000,0b00000000},{0b01000110,0b01000000,0b00000110,0b00001110}};
	
	unsigned char one = 1;
	while (1){
		//PORTB=0Xff;
		for(int i = 0; i < 4; i++)//as i = 0, shift left 0, at this time is 1110
		{
			PORTD = (~(one << i)); //one shift left　要寫進　portD　的前四個 bit, as i = 1 become 1101 and so on
			for(int j = 0; j < 4; j++)
			{
				if((~PIND) & (one << (4 + j)))//輸出電流用 因為是左邊四個bit　所以要加四
				{
					PORTB = array[i][j];
					_delay_ms(500);
				}
			}
		}
		
	}
		
}
