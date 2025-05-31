	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    ALIGN
    AREA MyCode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler	
		
Reset_Handler
		LDR	R0, =n
		LDR R3,=res
		LDRB R1,[R0]
		AND R2,R1,#0x0F
		CMP R2,#09
		BLO DOWN
		ADD R2,#07
DOWN
	ADD R2,#0x30
	STRB R2,[R3]
	AND R4,R1,#0xF0
	MOV R4,R4,LSR#04
	CMP R4,#09
	BLO nwod
	ADD R4,#07
	
nwod
	ADD R4,#0x30
	STRB R4,[R3,#1]
		
STOP 	
		B STOP
		
n		DCD 0x3A
	AREA data, DATA, READWRITE
res DCD 0
        END