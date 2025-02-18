#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <ctype.h>
int main(){
    int serverFd, clientFd;
    struct sockaddr_un serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[256];
    serverFd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(serverFd < 0){
        exit(1);
    }
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sun_family = AF_UNIX;
    strncpy(serverAddr.sun_path, "/tmp/unix_socket", sizeof(serverAddr.sun_path) - 1);
    unlink("/tmp/unix_socket");
    if(bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        close(serverFd);
        exit(1);
    }
    if(listen(serverFd,5) < 0){
        close(serverFd);
        exit(1);
    }
    printf("Server PID: %d, PPID: %d\n", getpid(), getppid());
    clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if(clientFd < 0){
        close(serverFd);
        exit(1);
    }
    memset(buffer, 0, sizeof(buffer));
    read(clientFd, buffer, sizeof(buffer));
    pid_t pid = fork();
    if(pid < 0){
        close(clientFd);
        close(serverFd);
        exit(1);
    }
    if(pid == 0){
        char nums[256];
        int j = 0;
        for(int i = 0; buffer[i] != '\0'; i++){
            if(buffer[i] >= '0' && buffer[i] <= '9'){
                nums[j++] = buffer[i];
            }
        }
        nums[j] = '\0';
        for(int i = 0; i < j - 1; i++){
            for(int k = i + 1; k < j; k++){
                if(nums[i] > nums[k]){
                    char t = nums[i];
                    nums[i] = nums[k];
                    nums[k] = t;
                }
            }
        }
        char out[256];
        sprintf(out, "Child (PID: %d): Sorted numbers ascending: %s", getpid(), nums);
        write(clientFd, out, strlen(out));
        close(clientFd);
        exit(0);
    }
    else{
        char letters[256];
        int j = 0;
        for(int i = 0; buffer[i] != '\0'; i++){
            if((buffer[i] >= 'A' && buffer[i] <= 'Z')||(buffer[i] >= 'a' && buffer[i] <= 'z')){
                letters[j++] = buffer[i];
            }
        }
        letters[j] = '\0';
        for(int i = 0; i < j - 1; i++){
            for(int k = i + 1; k < j; k++){
                if(letters[i] < letters[k]){
                    char t = letters[i];
                    letters[i] = letters[k];
                    letters[k] = t;
                }
            }
        }
        char out[256];
        sprintf(out, "Parent (PID: %d): Sorted letters descending: %s", getpid(), letters);
        write(clientFd, out, strlen(out));
    }
    close(clientFd);
    close(serverFd);
    return 0;
}