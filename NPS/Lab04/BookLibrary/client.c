#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 2048
int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    while(1){
        printf("\nMenu:\n1. Insert new book information\n2. Delete a book\n3. Display all book information\n4. Search a book\n5. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();
        char message[BUFFER_SIZE];
        memset(message, 0, sizeof(message));
        if(choice == 1){
            char title[100], author[100], accession[50], pages[10], publisher[100];
            printf("Enter title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            printf("Enter author: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = '\0';
            printf("Enter accession number: ");
            fgets(accession, sizeof(accession), stdin);
            accession[strcspn(accession, "\n")] = '\0';
            printf("Enter total pages: ");
            fgets(pages, sizeof(pages), stdin);
            pages[strcspn(pages, "\n")] = '\0';
            printf("Enter publisher: ");
            fgets(publisher, sizeof(publisher), stdin);
            publisher[strcspn(publisher, "\n")] = '\0';
            sprintf(message, "1:%s:%s:%s:%s:%s", title, author, accession, pages, publisher);
        } else if(choice == 2){
            char accession[50];
            printf("Enter accession number to delete: ");
            fgets(accession, sizeof(accession), stdin);
            accession[strcspn(accession, "\n")] = '\0';
            sprintf(message, "2:%s", accession);
        } else if(choice == 3){
            sprintf(message, "3");
        } else if(choice == 4){
            int searchOption;
            printf("Search by:\n1. Title\n2. Author\nEnter your choice: ");
            scanf("%d", &searchOption);
            getchar();
            char key[100];
            if(searchOption == 1){
                printf("Enter title: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';
                sprintf(message, "4:title:%s", key);
            } else if(searchOption == 2){
                printf("Enter author: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';
                sprintf(message, "4:author:%s", key);
            } else {
                printf("Invalid search option\n");
                continue;
            }
        } else if(choice == 5){
            sprintf(message, "5");
        } else {
            printf("Invalid option\n");
            continue;
        }
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) continue;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);
        inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
        if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
            close(sockfd);
            continue;
        }
        send(sockfd, message, strlen(message), 0);
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));
        int n = read(sockfd, buffer, sizeof(buffer));
        if(n > 0){
            buffer[n] = '\0';
            printf("Server response:\n%s\n", buffer);
        }
        close(sockfd);
        if(choice == 5) break;
    }
    return 0;
}