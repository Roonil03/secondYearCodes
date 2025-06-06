#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 150
#define SERVER_PORT 3388

int main() {
    int sockfd, sentbytes, recedbytes;
    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    socklen_t server_len = sizeof(serveraddr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Socket Creation Error\n");
        return -1;
    }
    
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    printf("Enter filename: ");
    scanf("%s", buff);
    
    sentbytes = sendto(sockfd, buff, strlen(buff), 0,
                      (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (sentbytes == -1) {
        printf("Error sending filename\n");
        close(sockfd);
        return -1;
    }
    
    memset(buff, '\0', sizeof(buff));
    recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0,
                         (struct sockaddr*)&serveraddr, &server_len);
    printf("%s\n", buff);
    
    if(strcmp(buff, "File not present") == 0) {
        close(sockfd);
        return EXIT_SUCCESS;
    }
    
    while(1) {
        printf("\n1. Search\n2. Replace\n3. Reorder\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", buff);
        
        sentbytes = sendto(sockfd, buff, strlen(buff), 0,
                          (struct sockaddr*)&serveraddr, sizeof(serveraddr));
        if(sentbytes == -1) {
            printf("Error sending choice\n");
            close(sockfd);
            return -1;
        }

        if(buff[0] == '1') {
            char word[MAXSIZE];
            printf("Enter word to search: ");
            scanf("%s", word);
            
            sentbytes = sendto(sockfd, word, strlen(word), 0,
                             (struct sockaddr*)&serveraddr, sizeof(serveraddr));
            if(sentbytes == -1) {
                printf("Error sending search word\n");
                close(sockfd);
                return -1;
            }
            
            memset(buff, '\0', sizeof(buff));
            recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0,
                                (struct sockaddr*)&serveraddr, &server_len);
            printf("%s\n", buff);
        }
        else if(buff[0] == '2') {
            char str1[MAXSIZE], str2[MAXSIZE];
            printf("Enter string to replace: ");
            scanf("%s", str1);
            printf("Enter replacement string: ");
            scanf("%s", str2);
            
            snprintf(buff, sizeof(buff), "%s %s", str1, str2);
            sentbytes = sendto(sockfd, buff, strlen(buff), 0,
                             (struct sockaddr*)&serveraddr, sizeof(serveraddr));
            if(sentbytes == -1) {
                printf("Error sending replace strings\n");
                close(sockfd);
                return -1;
            }
            
            memset(buff, '\0', sizeof(buff));
            recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0,
                                (struct sockaddr*)&serveraddr, &server_len);
            printf("%s\n", buff);
        }
        else if(buff[0] == '3') {
            memset(buff, '\0', sizeof(buff));
            recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0,
                                (struct sockaddr*)&serveraddr, &server_len);
            printf("%s\n", buff);
        }
        else if(buff[0] == '4') {
            memset(buff, '\0', sizeof(buff));
            recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0,
                                (struct sockaddr*)&serveraddr, &server_len);
            printf("%s\n", buff);
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }
    
    close(sockfd);
    return EXIT_SUCCESS;
}
