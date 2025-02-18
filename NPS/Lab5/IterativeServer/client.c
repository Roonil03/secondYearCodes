#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main(){
    int sock;
    struct sockaddr_in serv_addr, local_addr;
    char str1[100], str2[100], clientAddrStr[100];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    socklen_t len = sizeof(local_addr);
    getsockname(sock,(struct sockaddr*)&local_addr,&len);
    sprintf(clientAddrStr, "%s:%d", inet_ntoa(local_addr.sin_addr), ntohs(local_addr.sin_port));
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1,"\n")]=0;
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2,"\n")]=0;
    send(sock, str1, strlen(str1)+1, 0);
    send(sock, str2, strlen(str2)+1, 0);
    send(sock, clientAddrStr, strlen(clientAddrStr)+1, 0);
    char res[100];
    recv(sock, res, sizeof(res), 0);
    printf("%s\n", res);
    close(sock);
    return 0;
}