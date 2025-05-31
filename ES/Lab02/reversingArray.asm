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
	LDR R8, = Src0
	LDR R7, = Src1
	MOV R5, N
Up1
	LDR R1, [r8], #4
	STR r1, [r7], #4
	SUBS R5, #1
	BNE Up1
	
	LDR R0, = Src1
	LDR R2, = Src1 + (N - 1) * 4
	MOV R5 , N / 2
UP 	
	LDR R4, [R2]
	LDR R1, [R0]
	STR R1, [r2], #-4
	MOV R1, r4
	STR R1, [r0], #4
	SUBS R5, #1
	BNE UP ; if(z= 0)
STOP B STOP ; while(1)

N EQU 10
Src0 DCD 1,2,3,4,5,6,7,8,9,10;

	AREA DATASEG, DATA, READWRITE
Src1 DCD 0;
	END