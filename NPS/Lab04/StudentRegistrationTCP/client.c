#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) exit(EXIT_FAILURE);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) exit(EXIT_FAILURE);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) exit(EXIT_FAILURE);
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
        close(sock);
        exit(EXIT_FAILURE);
    }
    char sendbuf[200];
    sprintf(sendbuf, "%d:%s", choice, input);
    send(sock, sendbuf, strlen(sendbuf), 0);
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    printf("%s\n", buffer);
    close(sock);
    return 0;
}