#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1234  // Server port to connect to

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    int num1, num2, choice, result;
    char buffer[1024];  // Buffer to store server response

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);  // Convert to network byte order
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP (localhost)
    memset(server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Communicate with the server
    while(1) {
        printf("Choose an operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        scanf("%d", &choice);

        if (choice == 5) {
            send(sockfd, &choice, sizeof(choice), 0);  // Send choice to exit
            break;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        // Send the choice and numbers to the server
        send(sockfd, &choice, sizeof(choice), 0);
        send(sockfd, &num1, sizeof(num1), 0);
        send(sockfd, &num2, sizeof(num2), 0);

        // Receive the result from the server
        if (choice == 4) {  // Division might return an error message
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (strstr(buffer, "Error")) {
                printf("%s\n", buffer);
            } else {
                result = *((int *)buffer);  // Convert received data to result
                printf("Result: %d\n", result);
            }
        } else {
            recv(sockfd, &result, sizeof(result), 0);
            printf("Result: %d\n", result);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
