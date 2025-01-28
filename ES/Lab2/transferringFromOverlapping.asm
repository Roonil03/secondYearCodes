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
	LDR R0, = Src +(N - 1)*4
	LDR R2, = Src + (N+SHIFTS - 1) * 4
	MOV R5 , N
UP 	LDR R1, [R0], #-4
	STR R1, [r2], #-4
	SUBS R5, #1
	BNE UP ; if(z= 0)
STOP B STOP ; while(1)
N EQU 5
SHIFTS EQU 3
;Src DCD 1,2,3,4,5,6,7,8,9,10;

	AREA DATASEG, DATA, READWRITE
Src DCD 0;
	END