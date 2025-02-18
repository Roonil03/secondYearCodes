# UDP Socket Program Pseudocode

## Client Side Logic

```plaintext
1. INITIALIZE socket connection:
   - Create UDP socket
   - Set up server address structure (localhost:8080)
   
2. DISPLAY menu to user:
   - Option 1: Search by Registration Number
   - Option 2: Search by Student Name
   - Option 3: Search by Subject Code
   
3. GET user input:
   - Read choice (1-3)
   - Based on choice, prompt for corresponding search key
   - Store input
   
4. PREPARE message:
   - Format message as "choice:searchkey"
   
5. SEND AND RECEIVE:
   - Send formatted message to server
   - Wait for response from server
   - Display received response
   
6. CLEANUP:
   - Close socket
   - Exit program
```

## Server Side Logic

```plaintext
1. DATA STRUCTURE:
   Define Student Record:
   - Registration number
   - Name
   - Address
   - Department
   - Semester
   - Section
   - Courses
   - Subject code
   - Marks

2. INITIALIZE server:
   - Create UDP socket
   - Bind to port 8080
   - Initialize student database with sample records
   
3. MAIN LOOP:
   WHILE true:
       - Wait for incoming client message
       - When message received:
           CREATE new child process (fork)
           
           IF child process:
               - Parse received message into option and search key
               - Based on option:
                   CASE 1 (Registration Number):
                       - Search database by registration number
                       - Return student name and address
                       
                   CASE 2 (Student Name):
                       - Search database by name
                       - Return department, semester, section, courses
                       
                   CASE 3 (Subject Code):
                       - Search database by subject code
                       - Return marks
                       
               - Format response with child PID and found data
               - Send response back to client
               - Exit child process
               
           IF parent process:
               - Clean up any completed child processes
               - Continue listening for new requests

4. SEARCH FUNCTIONS:
   find_by_reg(key):
       - Loop through database
       - Return matching student record or NULL
       
   find_by_name(key):
       - Loop through database
       - Return matching student record or NULL
       
   find_by_subject(key):
       - Loop through database
       - Return matching student record or NULL
```

## Communication Flow

```plaintext
1. Client-Server Interaction:
   
   CLIENT                              SERVER
     |                                   |
     |-- Initialize Socket ------------->|
     |                                   |-- Bind to port 8080
     |                                   |-- Wait for connections
     |                                   |
     |-- Send Query (choice:key) ------->|
     |                                   |-- Fork new process
     |                                   |-- Process query
     |                                   |-- Search database
     |<---- Send Response --------------|-- Format response
     |                                   |
     |-- Display Result                  |-- Clean up child process
     |-- Close Socket                    |-- Continue listening
     
2. Message Format:
   - Client to Server: "option:searchkey"
     Example: "1:101" (search registration number 101)
   
   - Server to Client: "Child PID: [pid], [relevant data]"
     Example: "Child PID: 1234, Name: Alice, Address: 123 Main St"
```