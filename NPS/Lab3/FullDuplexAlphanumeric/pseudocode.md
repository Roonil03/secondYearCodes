# Unix Domain Socket Client-Server Program with Character Sorting

## Client Side Pseudocode

1. **Socket Setup Phase**
   ```
   Create Unix domain socket using AF_UNIX and SOCK_STREAM
   IF socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_UNIX
       - Set socket path to "/tmp/unix_socket"
   
   Connect to server
   IF connection fails
       Close socket
       Exit with error
   ```

2. **Communication Phase**
   ```
   Print Client's PID and Parent PID
   
   Prompt user for alphanumeric string
   Read input string
   Remove newline character
   
   Send string to server
   
   Clear response buffer
   Read first response from server (sorted numbers)
   Print first response
   
   Clear second response buffer
   Read second response from server (sorted letters)
   Print second response
   ```

3. **Cleanup**
   ```
   Close client socket
   Exit program
   ```

## Server Side Pseudocode

1. **Socket Setup Phase**
   ```
   Create Unix domain socket using AF_UNIX and SOCK_STREAM
   IF socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_UNIX
       - Set socket path to "/tmp/unix_socket"
   
   Remove existing socket file if any (unlink)
   
   Bind socket to address
   IF binding fails
       Close socket
       Exit with error
   
   Listen for connections (queue size 5)
   IF listen fails
       Close socket
       Exit with error
   ```

2. **Connection Handling**
   ```
   Print Server's PID and Parent PID
   
   Accept client connection
   IF accept fails
       Close server socket
       Exit with error
   
   Clear buffer
   Read client's message
   ```

3. **Process Creation**
   ```
   Create child process using fork()
   IF fork fails
       Close client socket
       Close server socket
       Exit with error
   ```

4. **Child Process (Number Sorting)**
   ```
   IF process is child (pid == 0):
       Initialize empty numbers array
       
       FOR each character in input buffer:
           IF character is digit (0-9)
               Add to numbers array
       
       Sort numbers in ascending order using bubble sort
       
       Create output message:
           "Child (PID: <pid>): Sorted numbers ascending: <sorted_numbers>"
       
       Write output to client
       Close client socket
       Exit child process
   ```

5. **Parent Process (Letter Sorting)**
   ```
   ELSE:
       Initialize empty letters array
       
       FOR each character in input buffer:
           IF character is letter (A-Z or a-z)
               Add to letters array
       
       Sort letters in descending order using bubble sort
       
       Create output message:
           "Parent (PID: <pid>): Sorted letters descending: <sorted_letters>"
       
       Write output to client
       Close client and server sockets
   ```


## Communication Flow

1. Server creates Unix domain socket and waits for connections
2. Client connects to server using the socket file path
3. Client sends alphanumeric string to server
4. Server creates child process:
   - Child process extracts and sorts numbers (ascending)
   - Parent process extracts and sorts letters (descending)
5. Both processes send their results back to client
6. Client receives and displays both sorted results
7. Connection is closed
