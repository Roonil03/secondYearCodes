# Server Side:

1. Socket Setup:
        Create a TCP socket, bind it to a port, and listen for incoming connections.
```
sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Create socket
bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Bind to port
listen(sockfd, 1);  // Listen for connections
```
2. Accept Client Connection:

    Accept a connection from a client to communicate.
```
newsockfd = accept(sockfd, (struct sockaddr*)&clientaddr, &actuallen);  // Accept connection
```
3. File Request:

    Receive the file name from the client.
```
recv(newsockfd, buff, sizeof(buff), 0);  // Receive file name from client
```
4. File Handling:

    Open the file if it exists, or send an error if not found.
```
FILE* f = fopen(buff, "r+");  // Open file
send(newsockfd, "File not present", 15, 0);  // File not found response
```
5. Process Commands:

    Loop to process client commands:
    - Command 1: Count occurrences of a word in the file.
        ```
        recv(newsockfd, word, sizeof(word), 0);  // Receive word
        countInLine(line, word);  // Count occurrences in file
        ```
    - Command 2: Replace one string with another in the file.
        ```
        recv(newsockfd, buff, sizeof(buff), 0);  // Receive strings
        replace(f, str1, str2);  // Replace string in file
        ```
    - Command 3: Sort the file lines.
        ```
        sort(f);  // Sort lines in file
        ```
    - Command 4: Close the connection.
        ```
        send(newsockfd, "Goodbye", 7, 0);  // Send exit message
        ```
6. Close Connections:

 Close the file and socket once done.
        ```
        fclose(f);  // Close file
        close(newsockfd);  // Close client socket
        close(sockfd);  // Close server socket
        ```

### Summary:
    TCP Functions: socket(), bind(), listen(), accept(), recv(), and send() manage connection setup, data exchange, and communication.
    Commands: Each client command is processed by receiving data (recv()), performing file operations, and responding with results (send()).

# Client Side:
1. Initialize UDP Socket:

    Create a UDP socket for communication with the server.
```
sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // Create UDP socket
```
2. Setup Server Address:

    Set the server's address and port (127.0.0.1 and 3388).
```
memset(&serveraddr, 0, sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(SERVER_PORT);  // Set server port
serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Set server IP
```
3. Send Filename to Server:

    Ask the user for a filename and send it to the server.
```
printf("Enter filename: ");
scanf("%s", buff);  // Get filename from user
sentbytes = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Send filename
```
4. Receive File Status from Server:

    Receive the server’s response indicating whether the file exists.
```
recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, &server_len);  // Receive server response
printf("%s\n", buff);  // Display file status
```
5. Handle Invalid File Response:

    If the file is not found, terminate the program.
```
if (strcmp(buff, "File not present") == 0) {
    close(sockfd);  // Close socket if file is not found
    return EXIT_SUCCESS;
}
```
6. Menu for Commands:

    Display a menu with options to search, replace, reorder, or exit.
```
printf("\n1. Search\n2. Replace\n3. Reorder\n4. Exit\n");
scanf("%s", buff);  // Get user choice
sentbytes = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Send choice to server
```
7. Handle Search Command:

    If the user selects search, prompt for a word to search, send it, and receive the result.
```
if(buff[0] == '1') {
    printf("Enter word to search: ");
    scanf("%s", word);  // Get search word
    sentbytes = sendto(sockfd, word, strlen(word), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Send search word
    recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, &server_len);  // Receive result
    printf("%s\n", buff);  // Display result
}
```
8. Handle Replace Command:

    If the user selects replace, prompt for strings to replace and their replacement, send them, and receive the result.
```
else if(buff[0] == '2') {
    printf("Enter string to replace: ");
    scanf("%s", str1);  // Get string to replace
    printf("Enter replacement string: ");
    scanf("%s", str2);  // Get replacement string
    snprintf(buff, sizeof(buff), "%s %s", str1, str2);  // Prepare replacement request
    sentbytes = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Send replace request
    recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, &server_len);  // Receive result
    printf("%s\n", buff);  // Display result
}
```
9. Handle Reorder Command:

    If the user selects reorder, just receive and display the response.
```
    else if(buff[0] == '3') {
        recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, &server_len);  // Receive result
        printf("%s\n", buff);  // Display result
    }
```
10. Handle Exit Command:

    If the user selects exit, receive the exit message and terminate.
```
else if(buff[0] == '4') {
    recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, &server_len);  // Receive goodbye message
    printf("%s\n", buff);  // Display goodbye message
    break;  // Exit loop
}
```
11. Handle Invalid Choice:

    If the user enters an invalid option, prompt to try again.
```
else {
    printf("Invalid choice, please try again.\n");  // Prompt for valid choice
}
```
12. Close Socket:

    Close the UDP socket after the communication is done.
```
close(sockfd);  // Close socket after all interactions
```
### Summary:

This client-side program allows the user to interact with the server, perform operations like search, replace, reorder file content, and receive appropriate responses.
