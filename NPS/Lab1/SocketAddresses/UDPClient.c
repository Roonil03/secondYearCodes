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
    int sock = 0;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in serv_addr;
    
    // Create UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("\nUDP Socket creation error\n");
        return -1;
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 address from text to binary
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }
    
    // Send message to server
    char *message = "Hello from UDP client";
    sendto(sock, message, strlen(message), MSG_CONFIRM,
           (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    // Receive server's response
    socklen_t len = sizeof(serv_addr);
    int n = recvfrom(sock, buffer, BUFFER_SIZE, MSG_WAITALL,
                     (struct sockaddr *)&serv_addr, &len);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);
    
    close(sock);
    return 0;
}
