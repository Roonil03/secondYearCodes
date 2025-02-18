#  Lab Exercises
 1. Write twoseparate C programs (one for server and other for client) using socket APIs
 for TCP and UDP to perform the following. The user at the client side has an option
 to enter:  
    1. Registration Number  
    2. Name of the Student  
    3. Subject Code.  

    The Client sends the selected option along with the requisite details to the server.
    Based on the options received the parent process in the server assigns the task to
    respective child process.  
    (a) If registration number is sent then the first child process sends Name and
    Residential Address of the student along with the PID of the child process.  
    (b) If Name of the Student is received then the second child process sends student
    enrollment details (Dept., Semester, Section and Courses Registered) along
    with the PID of the child process.  
    (c) If Subject Code is entered then the third child process sends the corresponding
    marks obtained in that subject along with its PID.  
    (d) The details sent by the server have to be displayed at the client.
 2. Write two separate C programs (one for server and other for client) using UNIX
 socket APIs using connection oriented services to implement DNS Server. Accept
 suitable input messages from the user. Assume the server has access to database.txt
 (can be a structure too). Response is always displayed at the client side.  
 # Additional Exercise
 1. Create a Book database at the server side and store the following information: title,
 author, accession number, total pages, and the publisher. Write C programs to
 implement the following client-server model:  
 a. Insert new book information  
 b. Delete a book  
 c. Display all book information  
 d. Search a book (Based on Title or author)  
 e. Exit  
 At the client side, the user selects the required option and sends it along with the
 necessary information to the server and server will perform the requested operation.
 Server should send appropriate messages back to the client informing the success or
 failure of the requested operation. Client should continue to request the operation
 until user selects the option 'Exit'. To search the book by author name, the client
 program should send the name of the author to the server. The list of all book details
 for that author should be sent to the client. If the author name is not found, then
 server should send appropriate message to the client