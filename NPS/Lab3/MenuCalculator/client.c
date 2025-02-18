#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 9090
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
    char sendbuf[4096], recvbuf[4096];
    int option;
    while(1){
        printf("\nMenu:\n1. Add/Subtract two integers\n2. Find the value of x in a linear equation (ax+b=c)\n3. Multiply two matrices\n4. Exit\nEnter option: ");
        scanf("%d", &option);
        getchar();
        if(option == 4){
            sprintf(sendbuf, "4\n");
            send(sockfd, sendbuf, strlen(sendbuf), 0);
            break;
        }
        if(option == 1){
            int a, b;
            printf("Enter first integer: ");
            scanf("%d", &a);
            printf("Enter second integer: ");
            scanf("%d", &b);
            getchar();
            sprintf(sendbuf, "1 %d %d\n", a, b);
        }
        else if(option == 2){
            int a, b, c;
            printf("For equation ax+b=c, enter a: ");
            scanf("%d", &a);
            printf("Enter b: ");
            scanf("%d", &b);
            printf("Enter c: ");
            scanf("%d", &c);
            getchar();
            sprintf(sendbuf, "2 %d %d %d\n", a, b, c);
        }
        else if(option == 3){
            int r1, c1, r2, c2;
            printf("Enter rows and columns for matrix 1: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns for matrix 2: ");
            scanf("%d %d", &r2, &c2);
            getchar();
            sprintf(sendbuf, "3 %d %d %d %d\n", r1, c1, r2, c2);
            send(sockfd, sendbuf, strlen(sendbuf), 0);
            if(c1 != r2){
                printf("Invalid matrix dimensions for multiplication.\n");
                continue;
            }
            char temp[4096];
            memset(sendbuf, 0, sizeof(sendbuf));
            int total1 = r1 * c1, total2 = r2 * c2;
            printf("Enter %d elements for matrix 1 separated by space: ", total1);
            for (int i = 0; i < total1; i++){
                int num;
                scanf("%d", &num);
                char numStr[20];
                sprintf(numStr, "%d ", num);
                strcat(sendbuf, numStr);
            }
            strcat(sendbuf, "\n");
            send(sockfd, sendbuf, strlen(sendbuf), 0);
            memset(sendbuf, 0, sizeof(sendbuf));
            printf("Enter %d elements for matrix 2 separated by space: ", total2);
            for (int i = 0; i < total2; i++){
                int num;
                scanf("%d", &num);
                char numStr[20];
                sprintf(numStr, "%d ", num);
                strcat(sendbuf, numStr);
            }
            strcat(sendbuf, "\n");
            getchar();
        }
        else{
            printf("Invalid option\n");
            continue;
        }
        if(option != 3){
            send(sockfd, sendbuf, strlen(sendbuf), 0);
        }
        memset(recvbuf, 0, sizeof(recvbuf));
        int n = recv(sockfd, recvbuf, sizeof(recvbuf)-1, 0);
        if(n <= 0) break;
        recvbuf[n] = '\0';
        printf("Result:\n%s\n", recvbuf);
    }
    close(sockfd);
    return 0;
}