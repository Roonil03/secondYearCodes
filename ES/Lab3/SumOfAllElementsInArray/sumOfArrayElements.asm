	AREA    RESET, DATA, READONLY
    EXPORT __Vectors

__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    ALIGN
    AREA MyCode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
    
Reset_Handler
    LDR R0, =Src0      
    MOV R1, #0         
    MOV R2, #10        
Up1
    LDR R3, [R0], #4   
    ADD R1, R1, R3     
    SUBS R2, R2, #1    
    BNE Up1           
    LDR R0, =res    
    STR R1, [R0]       
STOP 
    B STOP
Src0 DCD 1,2,3,4,5,6,7,8,9,10
    AREA DATASEG, DATA, READWRITE
res DCD 0
    END