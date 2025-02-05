	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000
    DCD Reset_Handler
    ALIGN
    AREA factorial, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R0, =n
    LDR R0, [R0]
    BL FACT
    LDR R1, =res
    STR R0, [R1]
STOP
    B STOP

FACT
    PUSH {R4, LR}
    MOV R4, R0
    CMP R0, #0
    BEQ BASE
    SUB R0, R0, #1
    BL FACT
    MOV R1, R4
    MUL R0, R0, R1
    B DONE
BASE
    MOV R0, #1
DONE
    POP {R4, LR}
    BX LR
n DCD 5
    AREA data1, DATA, READWRITE
res DCD 0
    ALIGN
    END