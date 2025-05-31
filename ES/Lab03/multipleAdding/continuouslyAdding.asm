	AREA MyCode, CODE, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001010
    DCD Reset_Handler
    ALIGN
    AREA MyCode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR R0, =n1
    LDR R1, [R0]
	LDR R10, [R0]
    SUBS R10, R10, #1
    ;MOV R2, #0x213
    LDR R2, =n2
	LDR R3, [R2]
loop
    CMP R1, #0
    BEQ mon
    ADDS R3, R3, R1
	ADCS R5, R5
    BCC ytt
    ;ADD R2, R2, #1
	
ytt
    SUBS R10, R10, #1
    BNE loop
mon
    MOV R4, R2
    MOV R6, R3
	ADD R6, R6, R5

STOP
    B STOP
	
n1		DCD 16
n2		DCD 16
    ALIGN

    END