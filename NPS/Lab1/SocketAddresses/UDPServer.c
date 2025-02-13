#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in address, client_addr;
    
    // Create UDP socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("UDP socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&address, 0, sizeof(address));
    memset(&client_addr, 0, sizeof(client_addr));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("UDP bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Server listening on port %d...\n", PORT);
    
    while(1) {
        socklen_t client_len = sizeof(client_addr);
        
        // Receive message from client
        int n = recvfrom(server_fd, buffer, BUFFER_SIZE, MSG_WAITALL,
                        (struct sockaddr *)&client_addr, &client_len);
        buffer[n] = '\0';
        
        // Display client information
        printf("\n=== New UDP Client Message ===\n");
        printf("Client IP Address: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Client Port: %d\n", ntohs(client_addr.sin_port));
        printf("Socket Address Family: AF_INET (IPv4)\n");
        printf("Socket Descriptor: %d\n", server_fd);
        printf("Client Message: %s\n", buffer);
        printf("============================\n\n");
        
        // Send response to client
        char *message = "Message received by server";
        sendto(server_fd, message, strlen(message), MSG_CONFIRM,
               (const struct sockaddr *)&client_addr, client_len);
    }
    
    return 0;
}
