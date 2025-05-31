	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001010
    DCD Reset_Handler
    ALIGN
    AREA MyCode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
		
Reset_Handler
    LDR SP, =0x10008000
    LDR R1, =a
    LDR R2, [R1]
    LDR R1, =b
    LDR R3, [R1]
    MOV R4, #1
loop
    MUL R5, R4, R2
    UDIV R6, R5, R3
    MLS R7, R6, R3, R5
    CMP R7, #0
    BEQ res
    ADD R4, R4, #1
    B loop
res
    LDR R1, =r
    STR R5, [R1]
STOP
    B STOP
a   DCD 15
b   DCD 20
r 	DCD 0
    ALIGN