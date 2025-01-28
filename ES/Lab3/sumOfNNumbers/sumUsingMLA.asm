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
    LDR R1, =n
    LDR R2, [R1]     
    MOV R3, #0  
    MOV R4, #1  
loop
    CMP R4, R2             
    BGT r
	MOV R5, #1
    MLA R3, R4, R5, R3    
    ADD R4, R4, #1         
    B loop
r
    LDR R1, =res
    STR R3, [R1]
STOP
    B STOP
n   DCD 10   
    AREA MyData, DATA, READWRITE
res DCD 0
    ALIGN