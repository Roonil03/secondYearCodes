# TCP DNS Lookup Service Pseudocode

## Client Side Logic

```plaintext
1. INITIALIZE TCP socket connection:
   - Create TCP socket
   - Configure server address (localhost:8080)
   
2. ESTABLISH connection:
   - Connect to server using configured address
   - If connection fails, exit program
   
3. USER INTERACTION:
   - Prompt user for domain name input
   - Read domain name from standard input
   - Remove newline character from input
   
4. COMMUNICATE with server:
   - Send domain name to server
   - Wait for response from server
   - Receive and display server's response
   
5. CLEANUP:
   - Close socket connection
   - Exit program
```

## Server Side Logic

```plaintext
1. DATA STRUCTURE:
   DATABASE_FILE format:
   - Each line contains: domain_name IP_address
   - Example: "example.com 192.168.1.1"

2. INITIALIZE server:
   - Create TCP socket
   - Configure server address:
     * Use INADDR_ANY for IP
     * Use port 8080
   - Bind socket to configured address
   - Listen for incoming connections (queue size: 5)
   
3. DOMAIN LOOKUP function:
   lookup_domain(domain_name):
   - Open database file
   - IF file open fails:
     * Return NULL
   - FOR each line in file:
     * Parse line into domain and IP
     * IF domain matches input:
       - Return IP address
     * ELSE:
       - Continue to next line
   - IF no match found:
     * Return NULL
   - Close file

4. MAIN SERVER LOOP:
   WHILE true:
       - Accept new client connection
       - IF connection accepted:
           - Read domain name from client
           - Search for domain in database
           - IF domain found:
               * Format response: "Domain [domain] resolved to [IP]"
           - ELSE:
               * Format response: "Domain [domain] not found"
           - Send response to client
           - Close client connection
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
     |-- Send domain name ------------->|
     |                                   |-- Look up domain in database
     |                                   |-- Prepare response
     |<---- Send response --------------|
     |-- Display result                  |
     |-- Close connection               |-- Close client connection
     |                                   |-- Wait for next client
     
2. Message Format:
   - Client to Server: "domain_name"
     Example: "example.com"
   
   - Server to Client: "Domain [domain_name] resolved to [ip_address]"
     Example: "Domain example.com resolved to 192.168.1.1"
     Or: "Domain example.com not found"
```