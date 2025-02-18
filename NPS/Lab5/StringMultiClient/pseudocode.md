# Socket Programming Communication Flow: Multi-Client Keyword Concatenation Server

## Overview
This program implements a multi-threaded server that accepts connections from two specific clients ("client1" and "client2") to assemble the phrase "Manipal Institute Of Technology". The server maintains synchronization using mutex locks and manages client connections in a thread-safe manner.

## System Architecture
```
[Client 1]                  [Multi-threaded Server]                  [Client 2]
"Institute Of"      ─────►     Concatenates Parts    ◄─────     "Technology"
    │                              │                                  │
    └──────────────────► Creates server.txt ◄─────────────────┘
```

## Communication Flow Pseudocode

### Server Initialization Phase
```
// Server startup: 2025-02-18 15:04:16 UTC
1. Initialize socket (server_fd)
2. Configure server parameters:
   - PORT: 8080
   - IP: INADDR_ANY
   - Max clients: 10
   - Listen queue: 3
3. Initialize thread synchronization:
   - pthread_mutex_t lock
   - clientCount = 0
   - file_done = 0
   - terminated = 0
```

### Client Initialization Phase
```
1. Validate command-line argument:
   IF argv[1] == "client1":
       keyword = "Institute Of"
   ELSE IF argv[1] == "client2":
       keyword = "Technology"
   ELSE:
       exit(1)

2. Setup socket connection:
   - Create socket
   - Connect to localhost:8080
   - Get local address info
```

### Data Exchange Flow
```
CLIENT                                SERVER
---------------------------------------
1. Client Connection:
send(keyword)        ───►    receive(keyword)
send(address)        ───►    receive(address)

2. Server Processing (Thread-Safe):
                            LOCK mutex
                            store client info
                            increment clientCount
                            UNLOCK mutex

3. When clientCount == 2:
                            LOCK mutex
                            write to server.txt
                            print confirmation
                            set file_done = 1
                            UNLOCK mutex

4. Server Response:
receive(response)    ◄───    send("terminate session")
```

## Technical Implementation Details

### Thread-Safe Client Management
```c
void *handle_client(void *arg) {
    // Critical section start
    pthread_mutex_lock(&lock);
    {
        // Store client information
        clients[clientCount].sock = sock;
        strncpy(clients[clientCount].keyword, buf, ...);
        strncpy(clients[clientCount].addr, addrbuf, ...);
        clientCount++;
    }
    pthread_mutex_unlock(&lock);
    // Critical section end
}
```

### File Operations
```c
if(clientCount == 2 && file_done == 0) {
    FILE *fp = fopen("server.txt", "a+");
    // Append format: " [keyword1] [keyword2]"
    fputs(" ", fp);
    fputs(clients[0].keyword, fp);
    fputs(" ", fp);
    fputs(clients[1].keyword, fp);
    fclose(fp);
    
    // Console output
    printf("Manipal %s %s\n", 
           clients[0].keyword, 
           clients[1].keyword);
    printf("%s %s\n", 
           clients[0].addr, 
           clients[1].addr);
}
```

### Connection Termination Protocol
```
void broadcast_terminate() {
    For each connected client i:
        1. send(clients[i].sock, "terminate session")
        2. close(clients[i].sock)
}
```