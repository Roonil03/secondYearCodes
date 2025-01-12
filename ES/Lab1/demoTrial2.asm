	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001010
	DCD Reset_Handler
	ALIGN
	AREA MyCode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, = Src
	LDR R1, = DST
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1
	LDRB R2, [R0], # 1
	STRB R2, [R1], # 1	
STOP 	B	STOP
Src DCB 0x12, 0x34, 0x56, 0x78, 0xAB, 0xCD, 0xEF, 0x12, 0x75
	AREA Datacode, DATA, READWRITE
DST DCB 0, 0