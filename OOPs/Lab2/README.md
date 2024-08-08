# Lab exercises:
1. Write a Java program to find whether a given year is leap or not using boolean data type. [Hint: leap year has 366 days;]
	Algorithm:
	if (year is not exactly divisible by 4) then (it is a common year)
	else
	if (year is not exactly divisible by 100) then (it is a leap year)
	else
	if (year is not exactly divisible by 400) then (it is a common year)
	else (it is a leap year)

2. Write a Java program to read an int number, double number and  a char from keyboard and perform the following conversions:-  int to byte, char to int, double to byte, double to int

3. Write a Java program to multiply and divide a number by 2 using bitwise operator. [Hint: use left shift and right shift bitwise operators]

4. Write a Java program to execute the following statements. Observe and analyze the outputs:
a. 	int x =10;		    
  	double y = x;		          
  	System.out.println(y);	          
b.  	double x = 10.5; 	
	int y = x;		     
	System.out.println(y);       
c. 	double x=10.5;
	int y = (int) x;
	System.out.println(y);

5.	Create the equivalent of a four-function calculator. The program should request the user to enter a number, an operator, and another number. (Use floating point.) It should then carry out the specified arithmetic operation: adding, subtracting, multiplying, or dividing the two numbers. Use a switch statement to select the operation. Finally, display the result. When it finishes the calculation, the program should ask if the user wants to do another calculation. The response can be 'y' or 'n'. [Hint: use do-while loop]

	Example 
	Enter first number, operator, second number: 10 / 3 
	Answer = 3.333333
	Do another (y/n)? n
# Additional exercises	
1. Write a Java program to find the result of the following expressions for various values of a & b:
	a. (a << 2) + (b >> 2)
	b. (b > 0)
	c. (a + b * 100) / 10
	d. a & b

2. Write a Java program to find largest and smallest among 3 numbers using ternary operator.

3. Write a Java program to execute the following statements. Observe and analyze the outputs
a. 	boolean x =true;   
	int y = x;
b.  	boolean x =true;		     
	int y =(int)x;
