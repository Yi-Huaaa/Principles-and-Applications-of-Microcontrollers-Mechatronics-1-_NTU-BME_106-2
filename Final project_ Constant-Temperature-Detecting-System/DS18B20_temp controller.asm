#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "uart.h"
#include "avr-ds18b20/include/ds18b20/ds18b20.h"
//#include "lcd.h"

/* define CPU frequency in Hz in Makefile */
#ifndef F_CPU
#error "F_CPU undefined, please define CPU frequency in Hz in Makefile"
#endif

/* Define UART buad rate here */
#define UART_BAUD_RATE      9600   

void ONEs(int b){
    if (b == 0){
        PORTC |= (1<<PC2);
        _delay_ms(500);
    }
    else if (b == 1)
    {
        PORTC |= (1<<PC1);
        _delay_ms(500);
    }
    else if (b == 2)
    {
        PORTC |= (1<<PC0);
        _delay_ms(500);
    }
    else{
        PORTC =0xff;
        _delay_ms(500);
    }
    
}   

void TENs(int a){
    if (a == 3){
        PORTC |= (1<<PC3);
        _delay_ms(500);
    }
    else if (a == 4)
    {
        PORTC |= (1<<PC4);
        _delay_ms(500);
    }
    else if (a == 5)
    {
        PORTC |= (1<<PC5);
        _delay_ms(500);
    }
    else{
        PORTC =0xff;
        _delay_ms(500);
    }
    
}


int main(void)
{
    unsigned int c;
    char buffer[7];
    int  num=134;
    int temp;
    int a, b;

    DDRC = 0xff;
    DDRB = 0x0;
    PORTC = 0x0;
    PORTB = 0xff;

    uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) ); 
    
    sei();
    
    uart_puts("String stored in SRAM\n");
    
    uart_puts_P("String stored in FLASH\n");
         
    itoa( num, buffer, 10);   // convert interger into string (decimal format)         
    uart_puts(buffer);        // and transmit string to UART

    uart_putc('\r');
    
    for(;;)
    {
        c = uart_getc();
        if ( c & UART_NO_DATA )
        {
            PORTC = 0xff;
            _delay_ms(1000);
            PORTC = 0x0;
            _delay_ms(1000);
        }
        else
        {
            //PORTB = 0x0;
            PORTC = 0x0;
            if ( c & UART_FRAME_ERROR )
            {
                uart_puts_P("UART Frame Error: ");
            }
            if ( c & UART_OVERRUN_ERROR )
            {
                uart_puts_P("UART Overrun Error: ");
            }
            if ( c & UART_BUFFER_OVERFLOW )
            {
                uart_puts_P("Buffer overflow error: ");
            }
            /* 
             * send received character back
             */
            // PORTB |= (1<<PB0);    /* PB0 Turn ON LED */
        
            // _delay_ms(500);
            // PORTB = 0x0;
            // _delay_ms(500);
            
            uart_putc( (unsigned char)c );

            for(int i =0; i<3; i++){

                ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL );

            // //Delay (sensor needs time to perform conversion)
                _delay_ms( 1000 );
            // //Read temperature (without ROM matching)
                ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL, &temp );
                if (PINB != 0x0)
                {
                    if (temp < 368 && temp >= 320)
                {
                    a = 3;
                    b = 0;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 416 && temp >= 368)
                {
                    a = 3;
                    b = 1;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 480 && temp >= 416)
                {
                    a = 3;
                    b = 2;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 528 && temp >= 480)
                {
                    a = 4;
                    b = 0;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 576 && temp >= 528)
                {
                    a = 4;
                    b = 1;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 640 && temp >= 576)
                {
                    a = 4;
                    b = 2;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 688 && temp >= 640)
                {
                    a = 5;
                    b = 0;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp < 736 && temp >= 688)
                {
                    a = 5;
                    b = 1;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else if (temp <= 800 && temp >736)
                {
                    a = 5;
                    b = 2;
                    TENs(a);
                    ONEs(b);
                    _delay_ms(1000);
                    PORTC = 0x0;
                    _delay_ms(500);
                }
                else{
                    PORTC = 0x0;
                }
                
            }
            }
        }
    }
}