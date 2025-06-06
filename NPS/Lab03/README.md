#  Lab Exercises
 1. Write two separate C programs using UNIX socket APIs illustrate full duplex mode chat application between a single client and server using connection oriented service. Display PID and PPID of both parent and child processes.
 2. Write two separate C programs using UNIX socket APIs illustrate half duplex mode chat application between a single client and server connection less service in which
 the server estimates and prints all permutations of a string sent by the client.
 3. Write two separate C programs (one for server and other for client) using socket APIs, to implement the following connection-oriented client-server model.
    - The user at the client side sends an alphanumeric string to the server.
    - The child process at the server sorts the numbers of the alphanumeric string in ascending order. The parent process at the server sorts the characters of the
 alphanumeric string in descending order.
    - Both the processes send the results to the client along with its corresponding process ID.

Sample Output: 
```
At the client side:
 Input string: hello451bye7324
 At the server side:
 Output at the child process of the server: 1234457
 Output at the parent process of the server: yollheeb
```
# Additional Exercises
 1. Write a C program to simulate a menu driven calculator using client server
 architecture that performs the following. The client prompts the user with the
 options as listed below 
    - Add/Subtract two integers
    - Find the value of '`x`' in a linear equation
    - Multiply two matrices
    - Exit
    
 Based on the user input the client prompts the user to enter required data. The client
 sends the option chosen and the relevant data to the server. The server performs the
 required operation and sends the result to the client. Note that if option 1 is selected,
 the server provides result of both addition and subtraction of the two integers.