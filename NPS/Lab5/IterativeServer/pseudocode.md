# Socket Programming Communication Flow: Client-Server Anagram Checker

## Overview
This program implements a client-server architecture where the client sends two strings to the server, and the server checks if they are anagrams.

## Communication Flow Pseudocode

### Server Side Initialize
```
1. Create a TCP socket (server_fd)
2. Configure server address:
   - Set port to 8080
   - Set IP to INADDR_ANY (accept connections from any interface)
3. Bind socket to configured address
4. Start listening for connections (queue up to 3 clients)
5. Enter infinite loop to handle client connections
```

### Client Side Initialize
```
1. Create a TCP socket (sock)
2. Configure connection to server:
   - Set port to 8080
   - Set IP to 127.0.0.1 (localhost)
3. Establish connection to server
4. Get local address information (for client identification)
```

### Data Flow
```
CLIENT                                              SERVER
------                                              ------
1. Input two strings                               1. Wait for client connection
   - Read str1 from user                              (accept() blocks until client connects)
   - Read str2 from user

2. Send data to server:                            2. Receive data from client:
   → Send str1                                        ← Receive str1
   → Send str2                                        ← Receive str2
   → Send client address                              ← Receive client address

3. Wait for response                               3. Process data:
                                                      - Check if strings are anagrams
                                                      - Prepare response message

4. Receive result:                                 4. Send result:
   ← Receive response                                 → Send "Strings are anagrams" or
                                                       "Strings are not anagrams"

5. Display result and close                        5. Close client connection
   connection                                         (but keep server running)
```

## Technical Details

### Client-Side Steps
1. Creates socket using AF_INET (IPv4) and SOCK_STREAM (TCP)
2. Connects to server at 127.0.0.1:8080
3. Gets its own address information using getsockname()
4. Takes two string inputs from user
5. Sends three pieces of information:
   - First string
   - Second string
   - Client's address information
6. Waits for and receives server's response
7. Displays result and closes connection

### Server-Side Steps
1. Creates socket using AF_INET (IPv4) and SOCK_STREAM (TCP)
2. Binds to port 8080 on all interfaces
3. Listens for incoming connections
4. For each client connection:
   - Accepts connection
   - Records connection time and client details
   - Receives two strings and client address
   - Checks if strings are anagrams using isAnagram()
   - Sends result back to client
   - Closes client connection
5. Continues listening for new connections

### Anagram Check Algorithm
```
1. Compare lengths of both strings
   - If different lengths, return false

2. Create frequency counter array (size 256 for ASCII)
   - Increment count for each character in first string
   - Decrement count for each character in second string

3. Check if all counts are zero
   - If yes: strings are anagrams
   - If no: strings are not anagrams
```