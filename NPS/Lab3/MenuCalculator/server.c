#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 9090
void addSubtract(char* req, char* res){
    int a, b;
    sscanf(req, "1 %d %d", &a, &b);
    int sum = a + b, diff = a - b;
    sprintf(res, "Addition: %d\nSubtraction: %d", sum, diff);
}
void solveLinear(char* req, char* res){
    int a, b, c;
    sscanf(req, "2 %d %d %d", &a, &b, &c);
    if(a == 0){
        sprintf(res, "Invalid equation, a cannot be zero");
    } else {
        double x = (double)(c - b) / a;
        sprintf(res, "x = %lf", x);
    }
}
void multiplyMatrices(char* dims, char* mat1Str, char* mat2Str, char* res){
    int r1, c1, r2, c2;
    sscanf(dims, "3 %d %d %d %d", &r1, &c1, &r2, &c2);
    if(c1 != r2){
        sprintf(res, "Matrix multiplication not possible");
        return;
    }
    int *mat1 = malloc(r1 * c1 * sizeof(int));
    int *mat2 = malloc(r2 * c2 * sizeof(int));
    int *prod = malloc(r1 * c2 * sizeof(int));
    char *token;
    token = strtok(mat1Str, " ");
    for(int i = 0; i < r1*c1; i++){
        if(token == NULL) break;
        mat1[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    token = strtok(mat2Str, " ");
    for(int i = 0; i < r2*c2; i++){
        if(token == NULL) break;
        mat2[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            prod[i*c2+j] = 0;
            for(int k = 0; k < c1; k++){
                prod[i*c2+j] += mat1[i*c1+k] * mat2[k*c2+j];
            }
        }
    }
    char temp[4096] = "";
    char line[1024];
    for(int i = 0; i < r1; i++){
        line[0] = '\0';
        for(int j = 0; j < c2; j++){
            char num[20];
            sprintf(num, "%d ", prod[i*c2+j]);
            strcat(line, num);
        }
        strcat(line, "\n");
        strcat(temp, line);
    }
    sprintf(res, "Resultant matrix:\n%s", temp);
    free(mat1);
    free(mat2);
    free(prod);
}
int main(){
    int serverFD = socket(AF_INET, SOCK_STREAM, 0);
    if(serverFD < 0){
        exit(1);
    }
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(PORT);
    if(bind(serverFD, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){
        close(serverFD);
        exit(1);
    }
    if(listen(serverFD, 5) < 0){
        close(serverFD);
        exit(1);
    }
    int clientFD = accept(serverFD, NULL, NULL);
    if(clientFD < 0){
        close(serverFD);
        exit(1);
    }
    char buffer[4096], res[4096];
    while(1){
        memset(buffer, 0, sizeof(buffer));
        int n = recv(clientFD, buffer, sizeof(buffer)-1, 0);
        if(n <= 0) break;
        buffer[n] = '\0';
        int option;
        sscanf(buffer, "%d", &option);
        if(option == 4){
            break;
        }
        if(option == 1){
            addSubtract(buffer, res);
            send(clientFD, res, strlen(res), 0);
        }
        else if(option == 2){
            solveLinear(buffer, res);
            send(clientFD, res, strlen(res), 0);
        }
        else if(option == 3){
            char dims[256] = "", mat1Str[4096] = "", mat2Str[4096] = "";
            strcpy(dims, buffer);
            memset(buffer, 0, sizeof(buffer));
            n = recv(clientFD, buffer, sizeof(buffer)-1, 0);
            if(n <= 0) break;
            buffer[n] = '\0';
            strcpy(mat1Str, buffer);
            memset(buffer, 0, sizeof(buffer));
            n = recv(clientFD, buffer, sizeof(buffer)-1, 0);
            if(n <= 0) break;
            buffer[n] = '\0';
            strcpy(mat2Str, buffer);
            multiplyMatrices(dims, mat1Str, mat2Str, res);
            send(clientFD, res, strlen(res), 0);
        }
    }
    close(clientFD);
    close(serverFD);
    return 0;
}