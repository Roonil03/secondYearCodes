#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>
#define PORT 8080
#define MAX 10
typedef struct { int sock; char keyword[100]; char addr[50]; } client_t;
client_t clients[MAX];
int clientCount = 0;
int file_done = 0;
int terminated = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *handle_client(void *arg) {
    int sock = *(int*)arg;
    free(arg);
    char buf[100];
    char addrbuf[50];
    int n;
    n = recv(sock, buf, sizeof(buf) - 1, 0);
    if(n <= 0) { close(sock); return NULL; }
    buf[n] = '\0';
    n = recv(sock, addrbuf, sizeof(addrbuf) - 1, 0);
    if(n <= 0) { close(sock); return NULL; }
    addrbuf[n] = '\0';
    pthread_mutex_lock(&lock);
    clients[clientCount].sock = sock;
    strncpy(clients[clientCount].keyword, buf, sizeof(clients[clientCount].keyword) - 1);
    strncpy(clients[clientCount].addr, addrbuf, sizeof(clients[clientCount].addr) - 1);
    clientCount++;
    pthread_mutex_unlock(&lock);
    return NULL;
}
void broadcast_terminate() {
    int i;
    for(i = 0; i < clientCount; i++) {
        send(clients[i].sock, "terminate session", strlen("terminate session"), 0);
        close(clients[i].sock);
    }
}
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t tid;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    while(1) {
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        pthread_mutex_lock(&lock);
        if(clientCount >= 2) {
            terminated = 1;
            pthread_mutex_unlock(&lock);
            send(new_socket, "terminate session", strlen("terminate session"), 0);
            close(new_socket);
            broadcast_terminate();
            break;
        }
        pthread_mutex_unlock(&lock);
        int *p = malloc(sizeof(int));
        *p = new_socket;
        pthread_create(&tid, NULL, handle_client, p);
        pthread_detach(tid);
        pthread_mutex_lock(&lock);
        if(clientCount == 2 && file_done == 0) {
            FILE *fp = fopen("server.txt", "a+");
            fseek(fp, 0, SEEK_END);
            fputs(" ", fp);
            fputs(clients[0].keyword, fp);
            fputs(" ", fp);
            fputs(clients[1].keyword, fp);
            fclose(fp);
            printf("Manipal %s %s\n", clients[0].keyword, clients[1].keyword);
            printf("%s %s\n", clients[0].addr, clients[1].addr);
            file_done = 1;
        }
        pthread_mutex_unlock(&lock);
    }
    close(server_fd);
    return 0;
}