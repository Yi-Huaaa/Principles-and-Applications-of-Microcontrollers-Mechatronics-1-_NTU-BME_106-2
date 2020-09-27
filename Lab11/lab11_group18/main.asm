ldi  r16, 0x00
out DDRD, r16 //make port D input
ldi r16, 0xff
out DDRB, r16 //make port B output

//全開 全暗
ldi r16, 0xff
ldi r17, 0b11000110 //C
ldi r18, 0b11000000 // D
ldi r19, 0b10000110 //E
ldi r20, 0b10001110 //F
ldi r21, 0b10000010 //G
ldi r22, 0b10001000 //A
ldi r23, 0b10000000 //B

ldi r24, 0b11111110 //C
ldi r25, 0b11111101 //D
ldi r26, 0b11111011 //E
ldi r27, 0b11110111 //F
ldi r28, 0b11101111 //G
ldi r29, 0b11011111 //A
ldi r30, 0b10111111 //B

out portD, R16
l1: out PORTB, r16 // 全案//C
	in r31, PIND // cin pind's information
	sub r31, r24 //
	brne l2 // dx
	out PORTB, r17
l2: out PORTB, r16 //D
	in r31, PIND
	sub r31, r25
	brne l3
	out PORTB, r18
l3: out PORTB, r16 //E
	in r31, PIND
	sub r31, r26
	brne l4
	out PORTB, r19
l4: out PORTB, r16 //F
	in r31, PIND
	sub r31, r27
	brne l5
	out PORTB, r20
l5: out PORTB, r16 //G
	in r31, PIND
	sub r31, r28
	brne l6
	out PORTB, r21
l6: out PORTB, r16 //A
	in r31, PIND
	sub r31, r29
	brne l7
	out PORTB, r22
l7: out PORTB, r16 //B
	in r31, PIND
	sub r31, r30
	brne l8
	out PORTB, r23
l8:
	jmp l1