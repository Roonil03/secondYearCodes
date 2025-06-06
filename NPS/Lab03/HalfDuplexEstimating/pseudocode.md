# UDP Client-Server Program for String Permutations

## Client Side Pseudocode

1. **Setup Phase**
   ```
   Create a UDP socket using AF_INET and SOCK_DGRAM
   If socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_INET (IPv4)
       - Set port to 8080
       - Set IP address to localhost (127.0.0.1)
   ```

2. **Main Communication Loop**
   ```
   WHILE true:
       Prompt user for input string
       Read string from user
       Remove newline character from input
       
       Send string to server using sendto()
       
       IF input string is "BYE"
           Break loop
       
       Clear buffer
       Receive response from server
       Display received message
   ```

3. **Cleanup**
   ```
   Close socket
   Exit program
   ```

## Server Side Pseudocode

1. **Permutation Function**
   ```
   FUNCTION permute(string, left, right, count):
       IF left equals right:
           Print current permutation
           Increment count
       ELSE:
           FOR i from left to right:
               Swap characters at positions left and i
               Recursively call permute with left+1
               Swap back characters (backtrack)
   ```

2. **Setup Phase**
   ```
   Create UDP socket using AF_INET and SOCK_DGRAM
   If socket creation fails
       Exit with error
   
   Initialize server address structure:
       - Set family to AF_INET (IPv4)
       - Set port to 8080
       - Set IP address to INADDR_ANY (accept connections from any interface)
   
   Bind socket to address and port
   If binding fails
       Close socket and exit with error
   ```

3. **Main Communication Loop**
   ```
   WHILE true:
       Clear buffer
       Receive data from client
       
       IF received string is "BYE"
           Break loop
       
       Initialize count to 0
       Calculate all permutations of received string using permute function
       
       Create response message with total count of permutations
       Send response back to client
   ```

4. **Cleanup**
   ```
   Close socket
   Exit program
   ```

## Communication Flow

1. Client connects and sends a string to server
2. Server receives string and generates all possible permutations
3. Server counts total permutations and sends count back to client
4. Client displays the received count
5. Process continues until client sends "BYE"