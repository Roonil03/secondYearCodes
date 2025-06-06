#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Create TCP socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("TCP socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                   &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("TCP bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("TCP Server listening on port %d...\n", PORT);
    
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, 
                                &client_len)) < 0) {
            perror("accept failed");
            continue;
        }
        
        // Display client information
        printf("\n=== New TCP Client Connected ===\n");
        printf("Client IP Address: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Client Port: %d\n", ntohs(client_addr.sin_port));
        printf("Socket Address Family: AF_INET (IPv4)\n");
        printf("Socket Descriptor: %d\n", new_socket);
        printf("============================\n\n");
        
        // Send confirmation to client
        char *message = "Connection established with server";
        send(new_socket, message, strlen(message), 0);
        
        // Close the connection
        close(new_socket);
    }
    
    return 0;
}
