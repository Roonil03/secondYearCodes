# TCP Student Information System Pseudocode

## Client Side Logic

```plaintext
1. INITIALIZE TCP socket connection:
   - Create TCP socket
   - Configure server address:
     * IP: localhost (127.0.0.1)
     * Port: 8080
   
2. ESTABLISH connection:
   - Connect to server using configured address
   - If connection fails:
     * Display error
     * Exit program
   
3. USER INTERACTION:
   DISPLAY menu options:
   - Option 1: Search by Registration Number
   - Option 2: Search by Student Name
   - Option 3: Search by Subject Code
   
   GET user choice:
   - Read numeric choice (1-3)
   - Based on choice:
     CASE 1:
       - Prompt for Registration Number
     CASE 2:
       - Prompt for Student Name
     CASE 3:
       - Prompt for Subject Code
     DEFAULT:
       - Display "Invalid choice"
       - Close socket and exit
   
4. PREPARE AND SEND query:
   - Format message as "choice:searchkey"
   - Send formatted message to server
   
5. RECEIVE AND DISPLAY:
   - Wait for server response
   - Display received response
   
6. CLEANUP:
   - Close socket connection
   - Exit program
```

## Server Side Logic

```plaintext
1. DATA STRUCTURES:
   Define Student Record:
   - Registration number (string)
   - Name (string)
   - Address (string)
   - Department (string)
   - Semester (integer)
   - Section (string)
   - Courses (string)
   - Subject code (string)
   - Marks (integer)
   
   Initialize Database:
   - Create array of Student Records
   - Populate with sample data

2. SEARCH FUNCTIONS:
   find_by_reg(registration_number):
   - Loop through database
   - Return matching student record or NULL
   
   find_by_name(student_name):
   - Loop through database
   - Return matching student record or NULL
   
   find_by_subject(subject_code):
   - Loop through database
   - Return matching student record or NULL

3. SERVER INITIALIZATION:
   - Create TCP socket
   - Configure server address:
     * IP: INADDR_ANY (accept connections from any interface)
     * Port: 8080
   - Bind socket to address
   - Listen for connections (queue size: 3)

4. MAIN SERVER LOOP:
   WHILE true:
       - Accept new client connection
       IF connection accepted:
           - Read client message
           - Parse message into option and search key
           
           CREATE new child process (fork):
           IF child process:
               BASED ON option:
               CASE "1" (Registration Number):
                   - Search by registration number
                   - If found:
                     * Return name and address
                   - Else:
                     * Return "not found" message
                     
               CASE "2" (Student Name):
                   - Search by name
                   - If found:
                     * Return department, semester, section, courses
                   - Else:
                     * Return "not found" message
                     
               CASE "3" (Subject Code):
                   - Search by subject code
                   - If found:
                     * Return marks
                   - Else:
                     * Return "not found" message
                     
               - Format response with child PID and found data
               - Send response to client
               - Close client socket
               - Exit child process
               
           IF parent process:
               - Close client socket
               - Clean up any zombie child processes
               - Continue listening for new connections
```

## Communication Flow

```plaintext
1. Client-Server Interaction:

   CLIENT                              SERVER
     |                                   |
     |-- Create Socket ---------------->|-- Create Socket
     |                                   |-- Bind to port 8080
     |                                   |-- Listen for connections
     |-- Connect to server ------------>|
     |                                   |-- Accept connection
     |-- Send query (choice:key) ------>|
     |                                   |-- Fork new process
     |                                   |-- Process query
     |                                   |-- Search database
     |<---- Send response --------------|
     |-- Display result                  |
     |-- Close connection               |-- Clean up child process
     |                                   |-- Wait for next client
     
2. Message Formats:
   - Client to Server: "option:searchkey"
     Examples:
     * "1:101" (search registration number 101)
     * "2:Alice" (search name Alice)
     * "3:MATH123" (search subject code MATH123)
   
   - Server to Client: "Child PID: [pid], [relevant data]"
     Examples:
     * "Child PID: 1234, Name: Alice, Address: 123 Main St"
     * "Child PID: 1235, Dept: CS, Semester: 1, Section: A, Courses: Math,Physics"
     * "Child PID: 1236, Marks: 85"
```