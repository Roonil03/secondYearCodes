#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8889
#define BUFFER_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    while (1) {
        printf("\nEnter filename (or 'stop' to exit): ");
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        
        socklen_t len = sizeof(server_addr);
        sendto(sock_fd, buffer, strlen(buffer), MSG_CONFIRM,
               (struct sockaddr *)&server_addr, sizeof(server_addr));
        
        if (strcmp(buffer, "stop") == 0) break;
        
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int n = recvfrom(sock_fd, buffer, BUFFER_SIZE, MSG_WAITALL,
                           (struct sockaddr *)&server_addr, &len);
            buffer[n] = '\0';
            
            if (strcmp(buffer, "EOF") == 0 || strstr(buffer, "File not found"))
                break;
            
            printf("%s", buffer);
        }
    }
    
    close(sock_fd);
    return 0;
}
