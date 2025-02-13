#  Lab Exercises
 1. Write two separate C programs (one for server and other for client) using UNIX socket APIs for both TCP and UDP to implement the following: The user at the client side sends name of the file to the server. If the file is not present, the server
 sends “File not present” to the client and terminates. Otherwise the following menu
 is displayed at the client side.
    1. Search 
    2. Replace 
    3. Reorder 
    4. Exit
    - If the user at the client side wants to search a string in file, the users sends to
 the server option ‘1’ along with the string to be searched. The server searches
 for the string in the file. If present, it sends the number of times the string has
 occurred to the client, else the server sends ‘String not found’ message to the
 client.
    - If the user wants to replace a string, along with option 2, the two strings ‘str1’
 and ‘str2’ are sent to the server. The Server searches for str1 in the file and
 replaces it with ‘str2’. After replacing the string, ‘String replaced’ message is
 sent to the client. If it is not found ‘String not found’ command is sent to the
 client.
    - Option 3 rearranges the entire text in the file in increasing order order of their
 ASCII value.
    - To terminate the application option ‘4’ is selected
 # Additional Exercise:
 1. Write twoseparate C programs (one for server and other for client) using socket APIs
 for TCP and UDP, to implement the File Server. The client program will send the
 name of the text file to the server. If the file is present at the server side, the server
 should send the contents of the file to the client along with the file size, number of
 alphabets number of lines, number of spaces, number of digits, and number of other
 characters present in the text file to the client. If the file is not present, then the
 server should send the proper message to the client. Note that the results are always
 displayed at the client side. Client should continue to send the filenames until the
 user enters the string ‘stop’