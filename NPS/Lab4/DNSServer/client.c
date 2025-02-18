#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024
int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) exit(1);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) exit(1);
    char domain[BUFFER_SIZE];
    printf("Enter domain name: ");
    fgets(domain, sizeof(domain), stdin);
    domain[strcspn(domain, "\n")] = 0;
    write(sockfd, domain, strlen(domain));
    char response[BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    read(sockfd, response, sizeof(response));
    printf("%s\n", response);
    close(sockfd);
    return 0;
}