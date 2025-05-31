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
    MOV R2, #10
    MOV R3, #10
    MOV R4, R0
    MOV R5, R1

loop
    CMP R5, #0
    BEQ done
    ADDS R3, R3, R4
    ADC R2, R2, #0
    SUBS R5, R5, #1
    B loop

done
    MOV R6, #10
    MOV R7, #0
convert
    CMP R3, R6
    BLT skip
    SUBS R3, R3, R6
    ADDS R7, R7, #1
    B convert
skip
    MOV R3, R7

STOP
    B STOP

    END