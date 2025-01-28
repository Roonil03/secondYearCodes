# Lab Exercises:
1. Write a program to add ten 32 bit numbers stored in code segment and store the result in data segment
2. Write a program to add two 128 bit numbers stored in code segment and store the result in data segment. <br>
Hint: Use indexed addressing mode.
3. Write a program to subtract two 128 bit numbers
4. Write an assembly language program to find LCM of two numbers <br>
Hint: 
```
i=1
do{
remainder= i*a mod b;
If (remainder==0)
Exit;
Else
i++;
} while(remainder!=0);
Return (i*a);
```
# Additional Exercise questions
1. Write a program to subtract two 32 bit numbers
2. Find the sum of ‘n’ natural numbers using MLA instruction.
3. Write an assembly language program to find GCD of two numbers<br>
Hint:
```
While(a!=b)
{
If(a>b)
a=a-b;
else
b=b-a;
} Return (a);
```
4. Write a program to multiply two 32 bit numbers using repetitive addition<br>
Hint: <br>
If two numbers are in R0 and R1 Registers then use following algorithm
```
Sum=0;
do { 
    sum=sum+R0; R1--; ;Use ADS instruction for addition and use ADD
                        ;instruction to increment a register by 1
    if carry then
    R2++; ;Increment carry value by one.
} while(R1!=0); ;Use Compare instruction to check greater
                ;than or not. And Brach instructions for loop
```
Result= R2 and R0
5. Write a program for BCD multiplication