#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }
    
    while (1) {
        printf("\nEnter filename (or 'stop' to exit): ");
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (send(sock, buffer, strlen(buffer), 0) < 0) {
            printf("Send failed\n");
            break;
        }
        
        if (strcmp(buffer, "stop") == 0) break;
        
        memset(buffer, 0, BUFFER_SIZE);
        int total_bytes = 0;
        while ((total_bytes = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
            buffer[total_bytes] = '\0';
            printf("%s", buffer);
            if (strstr(buffer, "File not found")) break;
            memset(buffer, 0, BUFFER_SIZE);
        }
    }
    
    close(sock);
    return 0;
}
