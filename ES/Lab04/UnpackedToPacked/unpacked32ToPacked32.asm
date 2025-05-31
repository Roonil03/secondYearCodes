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
    LDR R0, =n
    MOV R2, #0          
    MOV R3, #8          
UP
    LDRB R1, [R0], #1   
    LSL R2, R2, #4      
    ORR R2, R2, R1      
    SUBS R3, R3, #1     
    BNE UP       
    LDR R0, =res
    STR R2, [R0]        
STOP
    B STOP
n   DCB 1, 2, 3, 4, 5, 6, 7, 8
    AREA MyData, DATA, READWRITE
res DCD 0
    ALIGN
    END