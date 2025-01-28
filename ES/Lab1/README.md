# Lab Exercise:
1. Application entry:<br>
The ENTRY directive declares an entry point to the program. It marks the first instruction to be executed. In applications using the C library, an entry point is also contained within the C library initialization code. Initialization code and exception handlers also contain entry points.
2. Application execution:<br>
The application code begins executing at the label start, where it loads the decimal values 10 and 3 into registers R0 and R1. These registers are added together and the result placed in R0.
3. Program end:<br>
The END directive instructs the assembler to stop processing the source file. Every assembly language source module must finish with an END directive on a last line. Any lines following the END directive are ignored by the assembler.