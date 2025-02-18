#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
int main(){
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd < 0){
        exit(1);
    }
    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if(bind(serverfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        close(serverfd);
        exit(1);
    }
    if(listen(serverfd, 5) < 0){
        close(serverfd);
        exit(1);
    }
    socklen_t clilen = sizeof(cli_addr);
    int clientfd = accept(serverfd, (struct sockaddr *)&cli_addr, &clilen);
    if(clientfd < 0){
        close(serverfd);
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0){
        close(clientfd);
        close(serverfd);
        exit(1);
    }
    if(pid == 0){
        printf("Child Process: PID=%d PPID=%d\n", getpid(), getppid());
        char recvbuf[1024];
        while(1){
            memset(recvbuf, 0, sizeof(recvbuf));
            int n = recv(clientfd, recvbuf, sizeof(recvbuf)-1, 0);
            if(n <= 0) break;
            recvbuf[n] = '\0';
            printf("Client: %s\n", recvbuf);
            if(strcmp(recvbuf, "STOP") == 0) break;
        }
        shutdown(clientfd, SHUT_RD);
        exit(0);
    } else {
        printf("Parent Process: PID=%d ChildPID=%d\n", getpid(), pid);
        char sendbuf[1024];
        while(1){
            memset(sendbuf, 0, sizeof(sendbuf));
            fgets(sendbuf, sizeof(sendbuf), stdin);
            sendbuf[strcspn(sendbuf, "\n")] = '\0';
            if(send(clientfd, sendbuf, strlen(sendbuf), 0) <= 0) break;
            if(strcmp(sendbuf, "STOP") == 0) break;
        }
        close(clientfd);
        close(serverfd);
        exit(0);
    }
    return 0;
}