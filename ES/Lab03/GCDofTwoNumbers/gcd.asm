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
    LDR R1, =a
    LDR R2, [R1]
    LDR R1, =b
    LDR R3, [R1]
loop
    CMP R2, R3
    BEQ e
    BGT l1
    SUB R3, R3, R2
    B loop
l1
    SUB R2, R2, R3
    B loop
e
    LDR R1, =result
    STR R2, [R1]
STOP
    B STOP
	
a   DCD 48
b   DCD 18
    AREA MyData, DATA, READWRITE
result DCD 0
    ALIGN

    END