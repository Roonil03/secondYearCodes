#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
void permute(char *str, int l, int r, int* count){
    if(l == r){
        printf("%s\n", str);
        (*count)++;
    } else {
        for(int i = l; i <= r; i++){
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;
            permute(str, l+1, r, count);
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}
int main(){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        exit(1);
    }
    struct sockaddr_in serv_addr, client_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        close(sockfd);
        exit(1);
    }
    char buffer[1024];
    socklen_t addr_len = sizeof(client_addr);
    while(1){
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &addr_len);
        if(strcmp(buffer, "BYE") == 0){
            break;
        }
        int count = 0;
        permute(buffer, 0, strlen(buffer) - 1, &count);
        char message[128];
        sprintf(message, "Done, %d combinations possible", count);
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&client_addr, addr_len);
    }
    close(sockfd);
    return 0;
}