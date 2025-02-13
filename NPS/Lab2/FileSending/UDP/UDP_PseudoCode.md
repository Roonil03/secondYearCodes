# Client Side:

1.     Initialize UDP Socket:
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

printf("\n1. Search\n2. Replace\n3. Reorder\n4. Exit\n");
scanf("%s", buff);  // Get user choice
sentbytes = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Send choice to server

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
This client-side program allows the user to interact with the server by sending a filename, requesting operations like search, replace, and reorder, and receiving appropriate responses from the server.

# Server Side:
  1. Initialize UDP Socket:
        Create a UDP socket for communication with clients.
```
sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // Create UDP socket
```
2. Setup Server Address:
 
    Set up the server's address to accept requests on any available IP address (INADDR_ANY) and the specified port (3388).
```
serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(PORT);  // Set server port
serveraddr.sin_addr.s_addr = INADDR_ANY;  // Accept from any address
```
3. Bind Socket:

    Bind the socket to the server address and port.
```
bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  // Bind socket to address and port
```
4. Wait for Client Request:

    Listen for incoming requests from clients.
```
int n = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&clientaddr, &client_len);  // Receive client request
```
5. Open File:

    When the client sends a filename, attempt to open the file for reading and writing.
```
FILE* f = fopen(buff, "r+");  // Open file in read-write mode
```
6. Handle File Not Found:

    If the file does not exist, send an error message to the client and continue to the next request.
```
sendto(sockfd, "File not present", 15, 0, (struct sockaddr*)&clientaddr, client_len);  // Send file not found error
```
7. Handle File Found:

    If the file exists, send a confirmation message to the client that the file was found.
```
sendto(sockfd, "File found", 9, 0, (struct sockaddr*)&clientaddr, client_len);  // Send file found confirmation
```
8. Client Command Loop:

   Continuously process commands from the client:
       - Search Command (buff[0] == '1'): Search for a word in the file and send the count of occurrences back to the client.
```
if(buff[0] == '1') {
    recvfrom(sockfd, word, sizeof(word), 0, (struct sockaddr*)&clientaddr, &client_len);  // Receive search word
    count = countInLine(line, word);  // Count occurrences of the word
    sendto(sockfd, result_message, strlen(result_message), 0, (struct sockaddr*)&clientaddr, client_len);  // Send result to client
}
```
    - Replace Command (buff[0] == '2'): Replace occurrences of a word with another word and send the result to the client.
```
else if(buff[0] == '2') {
    recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&clientaddr, &client_len);  // Receive replace strings
    sscanf(buff, "%s %s", str1, str2);  // Extract strings
    int result = replace(f, str1, str2);  // Replace in file
    sendto(sockfd, result ? "String replaced" : "String not found", 15, 0, (struct sockaddr*)&clientaddr, client_len);  // Send result to client
}
```
    - Reorder Command (buff[0] == '3'): Sort the lines in the file and send a success message to the client.
```
else if(buff[0] == '3') {
    sort(f);  // Sort file lines
    sendto(sockfd, "File reordered", 13, 0, (struct sockaddr*)&clientaddr, client_len);  // Send success message
}
```
    - Exit Command (buff[0] == '4'): Send a goodbye message to the client and close the file.
```
    else if(buff[0] == '4') {
        sendto(sockfd, "Goodbye", 7, 0, (struct sockaddr*)&clientaddr, client_len);  // Send goodbye message
        fclose(f);  // Close file
        break;  // Exit loop
    }
```
9. Handle Multiple Requests:

    The server continuously listens for new requests from clients and processes them.
```
while(1) {  // Infinite loop to handle multiple client requests
    // Process commands
}
```
10. Close Socket:

    After processing all client requests, close the socket.
```
    close(sockfd);  // Close socket when server is done
```


