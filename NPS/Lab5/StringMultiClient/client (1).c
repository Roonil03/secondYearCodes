#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main(int argc, char *argv[]){
    int sock;
    struct sockaddr_in serv_addr, local_addr;
    char keyword[100];
    if(argc < 2) exit(1);
    if(strcmp(argv[1],"client1") == 0)
        strcpy(keyword, "Institute Of");
    else if(strcmp(argv[1],"client2") == 0)
        strcpy(keyword, "Technology");
    else exit(1);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    socklen_t len = sizeof(local_addr);
    getsockname(sock, (struct sockaddr*)&local_addr, &len);
    char addrstr[50];
    sprintf(addrstr, "%s:%d", inet_ntoa(local_addr.sin_addr), ntohs(local_addr.sin_port));
    send(sock, keyword, strlen(keyword), 0);
    send(sock, addrstr, strlen(addrstr), 0);
    char buf[100];
    int n = recv(sock, buf, sizeof(buf) - 1, 0);
    if(n > 0){
        buf[n] = '\0';
        printf("%s\n", buf);
    }
    close(sock);
    return 0;
}