	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000
    DCD Reset_Handler
    ALIGN
    AREA sort, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR R0, =0x67
    LDR R1, =0x45
    LDR R2, =0x23
    LDR R3, =0x89
    LDR R4, =0x12
    LDR R5, =0x34
    LDR R6, =0x90
    LDR R7, =0x56
    LDR R8, =0x78
    LDR R9, =0x11
    STMFD SP!, {R0-R9}
    MOV R10, #36
OUTER
    MOV R11, #0
INNER
    LDR R0, [SP, R11]
    ADD R12, R11, #4
    LDR R1, [SP, R12]
    CMP R0, R1
    STRGT R1, [SP, R11]
    STRGT R0, [SP, R12]
    ADD R11, R11, #4
    CMP R11, R10
    BLT INNER
    SUB R10, R10, #4
    CMP R10, #0
    BGT OUTER
    LDMFD SP!, {R0-R9}
STOP
    B STOP
    END