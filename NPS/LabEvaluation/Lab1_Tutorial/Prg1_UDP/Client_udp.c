#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345  // Port to send data to
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char *message = "Hello Server!";

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // Fill server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address

    // Send message to the server
    sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Message sent to server: %s\n", message);

    // Receive response from the server
    int n = recvfrom(sockfd, (char *)buffer, BUF_SIZE, MSG_WAITALL, NULL, NULL);
    buffer[n] = '\0';  // Null-terminate the received data
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}
