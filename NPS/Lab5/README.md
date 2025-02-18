#    Lab Exercises
 1. Write a single server and multiple client program to illustrate multiple clients
 communicating with a concurrent server. The client1 on establishing successful
 connection sends ”Institute Of” string to the server along with its socket address.
 The client2 on establishing successful connection sends ”Technology” string to the
 server along with its socket address. The server opens a text file having the keyword
 ”Manipal”, append the keywords ”Institute of” and ”Technology” and displays
 ”Manipal Institute of Technology” along with the socket addresses of the clients . If
 the number of clients connected exceeds 2, the server sends ”terminate session” to
 all clients and the program terminates.
 2. Write a single server multiple client program to illustrate multiple clients
 communicating with a single iterative server. The client on establishing successful
 connection prompts the user to enter 2 strings which is sent to the server along with
 client socket address. The server checks whether the strings are anagrams or not and
 sends an appropriate message to the client. The result obtained is then displayed on
 the client side. The server displays the date and time along with client socket
 address that it is connected to it at any instant.
 # Additional Exercise
 1. Write C program to simulate travel ticket reservation system. Where the server
 displays the number of seats available and the number of seats booked of two
 different source and destination locations. Multiple clients try to connect to server
 and sends the number of seats to be booked as entered by the user. The server
 database has to be updated and the client should terminate its session after
 successful seat reservation. Note that if the requested number of seats are
 unavailable the server sends appropriate message to the client and the client
 program terminates. Price of ticket need not be taken into consideration.