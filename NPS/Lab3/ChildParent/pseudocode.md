# TCP Client-Server Program with Parallel Processing

## Client Side Pseudocode

1. **Socket Setup Phase**
   ```
   Create TCP socket using AF_INET and SOCK_STREAM
   IF socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_INET (IPv4)
       - Set port to 8080
       - Set IP address to localhost (127.0.0.1)
   
   Connect to server
   IF connection fails
       Close socket
       Exit with error
   ```

2. **Process Creation**
   ```
   Create child process using fork()
   IF fork fails
       Close socket
       Exit with error
   ```

3. **Child Process (Sending Data)**
   ```
   IF process is child (pid == 0):
       Print Child Process ID and Parent Process ID
       
       WHILE true:
           Clear send buffer
           Read input from user
           Remove newline character
           
           Send message to server
           IF send fails OR message is "STOP"
               Break loop
       
       Shutdown write end of socket
       Exit child process
   ```

4. **Parent Process (Receiving Data)**
   ```
   ELSE:
       Print Parent Process ID and Child Process ID
       
       WHILE true:
           Clear receive buffer
           Receive message from server
           IF receive fails
               Break loop
           
           Add null terminator to received message
           Print received message
           
           IF message is "STOP"
               Break loop
       
       Close socket
       Exit parent process
   ```

## Server Side Pseudocode

1. **Socket Setup Phase**
   ```
   Create TCP socket using AF_INET and SOCK_STREAM
   IF socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_INET (IPv4)
       - Set port to 8080
       - Set IP address to INADDR_ANY
   
   Bind socket to address
   IF binding fails
       Close socket
       Exit with error
   
   Listen for connections (queue size 5)
   IF listen fails
       Close socket
       Exit with error
   ```

2. **Connection Acceptance**
   ```
   Accept client connection
   IF accept fails
       Close server socket
       Exit with error
   ```

3. **Process Creation**
   ```
   Create child process using fork()
   IF fork fails
       Close client socket
       Close server socket
       Exit with error
   ```

4. **Child Process (Receiving Data)**
   ```
   IF process is child (pid == 0):
       Print Child Process ID and Parent Process ID
       
       WHILE true:
           Clear receive buffer
           Receive message from client
           IF receive fails
               Break loop
           
           Add null terminator
           Print received message
           
           IF message is "STOP"
               Break loop
       
       Shutdown read end of socket
       Exit child process
   ```

5. **Parent Process (Sending Data)**
   ```
   ELSE:
       Print Parent Process ID and Child Process ID
       
       WHILE true:
           Clear send buffer
           Read input from user
           Remove newline character
           
           Send message to client
           IF send fails OR message is "STOP"
               Break loop
       
       Close client socket
       Close server socket
       Exit parent process
   ```

## Communication Flow

1. Server starts and waits for connections
2. Client connects to server
3. Both client and server create child processes
4. Parallel communication occurs:
   - Client child process: Sends data to server
   - Client parent process: Receives data from server
   - Server child process: Receives data from client
   - Server parent process: Sends data to client
5. Communication continues until "STOP" message or connection terminates
