	AREA	RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA MyCode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	LDR R2, = DST
	LDR R0, = Src
	MOV R5 , #10
UP LDR R1, [R0], #4
	STR R1, [r2], #4
	SUBS R5, #1
	BNE UP ; if(z= 0)
STOP B STOP ; while(1)

Src DCD 1,2,3,4,5,6,7,8,9,10;

	AREA DATASEG, DATA, READWRITE
;Src DCD 1,2,3,4,5,6,7,8,9,10;
DST DCD 0;
	END