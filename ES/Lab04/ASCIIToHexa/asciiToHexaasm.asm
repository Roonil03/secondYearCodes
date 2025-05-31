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
    LDR R0, =HexASCII    
    LDRB R1, [R0]        
    LDRB R2, [R0, #1]   
    SUB R1, R1, #0x30    
    CMP R1, #9           
    SUBHI R1, R1, #7     
    SUB R2, R2, #0x30    
    CMP R2, #9           
    SUBHI R2, R2, #7     
    LSL R1, R1, #4       
    ORR R3, R1, R2       
    LDR R0, =Result      
    STRB R3, [R0]        
STOP
    B STOP
HexASCII DCB "4A"    
    AREA MyData, DATA, READWRITE    
Result DCB 0
    ALIGN

    END