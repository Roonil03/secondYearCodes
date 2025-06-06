#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        exit(1);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        close(sockfd);
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0){
        close(sockfd);
        exit(1);
    }
    if(pid == 0){
        printf("Child Process: PID=%d PPID=%d\n", getpid(), getppid());
        char sendbuf[1024];
        while(1){
            memset(sendbuf, 0, sizeof(sendbuf));
            fgets(sendbuf, sizeof(sendbuf), stdin);
            sendbuf[strcspn(sendbuf, "\n")] = '\0';
            if(send(sockfd, sendbuf, strlen(sendbuf), 0) <= 0){
                break;
            }
            if(strcmp(sendbuf, "STOP") == 0){
                break;
            }
        }
        shutdown(sockfd, SHUT_WR);
        exit(0);
    } else {
        printf("Parent Process: PID=%d ChildPID=%d\n", getpid(), pid);
        char recvbuf[1024];
        while(1){
            memset(recvbuf, 0, sizeof(recvbuf));
            int n = recv(sockfd, recvbuf, sizeof(recvbuf)-1, 0);
            if(n <= 0){
                break;
            }
            recvbuf[n] = '\0';
            printf("Received: %s\n", recvbuf);
            if(strcmp(recvbuf, "STOP") == 0){
                break;
            }
        }
        close(sockfd);
        exit(0);
    }
    return 0;
}