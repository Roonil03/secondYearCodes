# Lab exercises:
1.	Create an Account class that stores customers name, acc-no and type of account. From this derive class current account and savings bank account. Include necessary methods in order to achieve following tasks:-<br>
a)	Accept the deposit from a customer and update the balance<br>
b)	Display the balance<br>
c)	Compute and deposit interest<br>
d)	Permit withdraw and update the balance<br>
e)	Check for minimum balance impose penalty if necessary and update the balance<br>
For savings bank account the facilities given are computing interest, withdraw facility. No interest on current bank account and should maintain a minimum balance and if balance is less than this level, service tax is imposed.

2.	Create a base class for student having registration number, name and age. From this class create two new class UG and PG student with semester and fees as its data members. Use proper member function for demonstrating inheritance. <br>Display the details of students who took admission to UG course and PG course separately, total number of UG admissions and PG admissions.

3.	Create a base class called Bank that provides functionality to get rate of interest. But, rate of interest varies according to banks. For example, SBI, ICICI and AXIS banks could provide 8%, 7% and 9% rate of interest. <br>Write a Java program to calculate the interest for SBI, ICICI and AXIS banks, by demonstrating the concept of method overriding and dynamic method dispatch.

# Additional exercises:

1.	Create a base class “Game” with method called “type” that prints “indoor & outdoor games”. Create a subclass cricket with a method called “type” that prints “cricket is an outdoor game”. Create one more subclass of “Game” called “chess” with a method “type” that prints “chess is an indoor game”. Write a complete Java program for the above, to understand the Dynamic method dispatch concept.

2.	Create two classes Bike and Splendar. Splendar class extends Bike class and overrides its run() method. Write a complete Java program to implement the runtime polymorphism. Include a member called “speedlimit” in both the classes with different values. The run() method should give the information of speed limit. Check whether the runtime polymorphism can be achieved through the data members.
