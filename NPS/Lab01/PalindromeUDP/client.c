#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char input[MAXLINE];
    struct sockaddr_in servaddr;
    
    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    // Server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    printf("UDP Client Started...\n");
    printf("Enter 'Halt' to exit\n\n");
    
    while(1) {
        printf("Enter a string: ");
        fgets(input, MAXLINE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        
        // Send message to server
        sendto(sockfd, input, strlen(input), 0,
               (const struct sockaddr *)&servaddr, sizeof(servaddr));
        
        // Check if client wants to halt
        if(strcmp(input, "Halt") == 0) {
            printf("Client shutting down...\n");
            break;
        }
        
        // Receive server's response
        int len = sizeof(servaddr);
        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0,
                        (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';
        
        // Display server's response
        printf("\nServer Response:\n%s\n\n", buffer);
    }
    
    close(sockfd);
    return 0;
}
