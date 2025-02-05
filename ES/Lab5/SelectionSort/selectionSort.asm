	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000
    DCD Reset_Handler
    ALIGN

    AREA ascend, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    MOV R4, #0
    MOV R1, #10
    LDR R0, =array
    LDR R2, =res
COPY
    LDR R3, [R0,R4]
    STR R3, [R2,R4]
    ADD R4, #4
    SUB R1, #1
    CMP R1, #0
    BHI COPY
    LDR R0, =res
    MOV R1, #10
    MOV R2, #0
OUT
    MOV R3, R2
    MOV R4, R2
    ADD R5, R2, #4
IN
    CMP R5, R1, LSL #2
    BGE swap
    LDR R6, [R0, R4]
    LDR R7, [R0, R5]
    CMP R7, R6
    MOVLT R4, R5
    ADD R5, R5, #4
    B IN
swap
    CMP R3, R4
    BEQ nSwap
    LDR R6, [R0, R3]
    LDR R7, [R0, R4]
    STR R7, [R0, R3]
    STR R6, [R0, R4]
nSwap
    ADD R2, R2, #4
    CMP R2, R1, LSL #2
    BLT OUT
STOP    
    B STOP

array    DCD 0x10,0x05,0x33,0x24,0x56,0x77,0x21,0x04,0x87,0x01

    AREA data1, DATA, READWRITE
res     DCD 0,0,0,0,0,0,0,0,0,0
    ALIGN
    END