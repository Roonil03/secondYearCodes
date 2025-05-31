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
    LDR R1, =n1
    LDR R2, [R1]
    LDR R1, =n2
    LDR R3, [R1]
    SUB R4, R2, R3 
    LDR R1, =res
    STR R4, [R1]
STOP
	B STOP
n1	 	DCD 0x12345678 
n2 	 	DCD 0x0ABCDEF0 
    AREA MyData, DATA, READWRITE
res 	DCD 0  
    ALIGN