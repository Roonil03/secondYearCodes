	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000
    DCD Reset_Handler
    ALIGN    
    AREA Program, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    MOV R0, #10          
    MOV R1, #3           
    ADD R0, R0, R1     
STOP
    B STOP
    END