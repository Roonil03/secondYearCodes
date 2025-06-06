#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

#define MAXSIZE 150

int main() {
    char buff[MAXSIZE];
    int sockfd, retval, sentbytes, recedbytes;
    struct sockaddr_in serveraddr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket Creation Error\n");
        return -1;
    }
    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3388);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    retval = connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Connection error\n");
        close(sockfd);
        return -1;
    }
    
    memset(buff, '\0', sizeof(buff));
    printf("Enter filename: ");
    scanf("%s", buff);
    sentbytes = send(sockfd, buff, strlen(buff), 0);
    if (sentbytes == -1) {
        printf("Error sending filename\n");
        close(sockfd);
        return -1;
    }
    
    memset(buff, '\0', sizeof(buff));
    recedbytes = recv(sockfd, buff, sizeof(buff), 0);
    printf("%s\n", buff);
    
    if(strcmp(buff, "File not present") == 0) {
        close(sockfd);
        return EXIT_SUCCESS;
    }
    
    while (1) {
        printf("\n1. Search\n2. Replace\n3. Reorder\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", buff);
        
        sentbytes = send(sockfd, buff, strlen(buff), 0);
        if (sentbytes == -1) {
            printf("Error sending choice\n");
            close(sockfd);
            return -1;
        }

        if (buff[0] == '1') {
            char word[MAXSIZE];
            printf("Enter word to search: ");
            scanf("%s", word);
            sentbytes = send(sockfd, word, strlen(word), 0);
            if (sentbytes == -1) {
                printf("Error sending search word\n");
                close(sockfd);
                return -1;
            }
            memset(buff, '\0', sizeof(buff));
            recedbytes = recv(sockfd, buff, sizeof(buff), 0);
            printf("%s\n", buff);
        }
        else if (buff[0] == '2') {
            char str1[MAXSIZE], str2[MAXSIZE];
            printf("Enter string to replace: ");
            scanf("%s", str1);
            printf("Enter replacement string: ");
            scanf("%s", str2);
            
            snprintf(buff, sizeof(buff), "%s %s", str1, str2);
            sentbytes = send(sockfd, buff, strlen(buff), 0);
            if (sentbytes == -1) {
                printf("Error sending replace strings\n");
                close(sockfd);
                return -1;
            }
            memset(buff, '\0', sizeof(buff));
            recedbytes = recv(sockfd, buff, sizeof(buff), 0);
            printf("%s\n", buff);
        }
        else if (buff[0] == '3') {
            memset(buff, '\0', sizeof(buff));
            recedbytes = recv(sockfd, buff, sizeof(buff), 0);
            printf("%s\n", buff);
        }
        else if (buff[0] == '4') {
            memset(buff, '\0', sizeof(buff));
            recedbytes = recv(sockfd, buff, sizeof(buff), 0);
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
