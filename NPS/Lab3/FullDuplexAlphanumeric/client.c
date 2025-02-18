#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
int main(){
    int clientFd;
    struct sockaddr_un serverAddr;
    char buffer[256], response[256], response2[256];
    clientFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(clientFd < 0){
        exit(1);
    }
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sun_family = AF_UNIX;
    strncpy(serverAddr.sun_path, "/tmp/unix_socket", sizeof(serverAddr.sun_path) - 1);
    if(connect(clientFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        close(clientFd);
        exit(1);
    }
    printf("Client PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Enter alphanumeric string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    write(clientFd, buffer, strlen(buffer));
    memset(response, 0, sizeof(response));
    read(clientFd, response, sizeof(response));
    printf("%s\n", response);
    memset(response2, 0, sizeof(response2));
    read(clientFd, response2, sizeof(response2));
    printf("%s\n", response2);
    close(clientFd);
    return 0;
}