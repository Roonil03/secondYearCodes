#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) exit(EXIT_FAILURE);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) exit(EXIT_FAILURE);
    int choice;
    char input[100];
    printf("Select option:\n1. Registration Number\n2. Name of the Student\n3. Subject Code\nEnter choice: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Enter Registration Number: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
    } else if (choice == 2) {
        printf("Enter Name of the Student: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
    } else if (choice == 3) {
        printf("Enter Subject Code: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
    } else {
        printf("Invalid choice\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    char sendbuf[200];
    sprintf(sendbuf, "%d:%s", choice, input);
    sendto(sockfd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    char buffer[1024] = {0};
    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr *)&servaddr, &len);
    if(n >= 0) {
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }
    close(sockfd);
    return 0;
}