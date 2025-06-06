#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
int main(){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        exit(1);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    char buffer[1024];
    socklen_t addr_len = sizeof(serv_addr);
    while(1){
        printf("Enter string: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serv_addr, addr_len);
        if(strcmp(buffer, "BYE") == 0){
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serv_addr, &addr_len);
        printf("Received: %s\n", buffer);
    }
    close(sockfd);
    return 0;
}