	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000
    DCD Reset_Handler
    ALIGN
    AREA linearsearch, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR R0, =array
    LDR R1, =key
    LDR R1, [R1]
    MOV R2, #0
    MOV R3, #10
SEARCH
    LDR R4, [R0, R2]
    CMP R4, R1
    BEQ FOUND
    ADD R2, R2, #4
    SUBS R3, R3, #1
    BNE SEARCH
    MOV R5, #0
    B STORE
FOUND
    MOV R5, #1
    LSR R2, #2
STORE
    LDR R0, =res
    STR R5, [R0]
    LDR R0, =pos
    STR R2, [R0]
STOP
    B STOP
array DCD 15, 24, 37, 41, 52, 68, 73, 86, 92, 100
key DCD 73
    AREA data1, DATA, READWRITE
res DCD 0
pos DCD 0
    ALIGN
    END