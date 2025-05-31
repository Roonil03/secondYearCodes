	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    ALIGN
    AREA MyCode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler	
		
Reset_Handler
	LDR 	R0, =n0
	LDR		R3, [r0]
    AND     R1, R3, #0xF0
    LSR     R1, R1, #4    
    ;MOV     R2, R1
    AND     R2, R3, #0x0F    
    ;ORR     R1, R1, R2
	MOV		R0, #0xA
	MUL 	R1, R1, R0
	ADD		R2, R2, R1
	LDR		R5, =res
	STRB 	R2, [r5]
STOP B STOP
n0 	DCD 0x31
	AREA MyData, DATA, READWRITE
res	DCD 0
	END