	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    ALIGN

    AREA Program, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR R0, =HEXNUM     
    LDRB R1, [R0]       
    
    MOV R2, #0          ; Initialize result
    MOV R3, #0          ; Counter for divisions
    MOV R4, #10         ; Divisor

DIV_LOOP
    MOV R5, #0          ; Initialize quotient
SUBTRACT
    CMP R1, R4          
    BCC STORE           ; If number < 10, branch to store
    SUB R1, R1, R4      ; Subtract 10
    ADD R5, R5, #1      ; Increment quotient
    B SUBTRACT          

STORE
    LSL R2, #4          ; Shift left by 4 bits
    ORR R2, R1          ; Store remainder in lower nibble
    MOV R1, R5          ; Move quotient for next iteration
    ADD R3, R3, #1      ; Increment counter
    CMP R3, #2          ; Check if two divisions done
    BNE DIV_LOOP        

    LDR R0, =BCDNUM     
    STR R2, [R0]        

STOP
    B STOP

HEXNUM DCB 0x20         ; Example: Hex number 4A (74 in decimal)

    AREA DATA, DATA, READWRITE
BCDNUM DCD 0
    END