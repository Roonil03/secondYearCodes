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
typedef struct {
    char title[100];
    char author[100];
    char accession[50];
    int totalPages;
    char publisher[100];
} Book;
void insertBook(char *data) {
    FILE *fp = fopen("database.txt", "a");
    if(fp == NULL) return;
    fprintf(fp, "%s\n", data);
    fclose(fp);
}
void deleteBook(const char *accession) {
    FILE *fp = fopen("database.txt", "r");
    if(fp == NULL) return;
    FILE *temp = fopen("temp.txt", "w");
    char line[512];
    while(fgets(line, sizeof(line), fp)) {
        char record[512];
        strcpy(record, line);
        char *token = strtok(record, "|"); 
        token = strtok(NULL, "|"); 
        token = strtok(NULL, "|"); 
        if(token != NULL && strcmp(token, accession) == 0) continue;
        fputs(line, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("database.txt");
    rename("temp.txt", "database.txt");
}
void displayAll(int clientSocket) {
    FILE *fp = fopen("database.txt", "r");
    char buffer[BUFFER_SIZE];
    buffer[0] = '\0';
    if(fp == NULL) {
        strcpy(buffer, "No records found");
        send(clientSocket, buffer, strlen(buffer), 0);
        return;
    }
    char line[512];
    while(fgets(line, sizeof(line), fp)) {
        strcat(buffer, line);
    }
    fclose(fp);
    if(strlen(buffer) == 0) strcpy(buffer, "No records found");
    send(clientSocket, buffer, strlen(buffer), 0);
}
void searchBook(int clientSocket, const char *criteria, const char *searchKey) {
    FILE *fp = fopen("database.txt", "r");
    char buffer[BUFFER_SIZE];
    buffer[0] = '\0';
    int found = 0;
    if(fp != NULL) {
        char line[512];
        while(fgets(line, sizeof(line), fp)) {
            char rec[512];
            strcpy(rec, line);
            char *title = strtok(rec, "|");
            char *author = strtok(NULL, "|");
            if(title != NULL && author != NULL) {
                if(strcmp(criteria, "title") == 0 && strcmp(title, searchKey)==0) {
                    strcat(buffer, line);
                    found = 1;
                } else if(strcmp(criteria, "author") == 0 && strcmp(author, searchKey)==0) {
                    strcat(buffer, line);
                    found = 1;
                }
            }
        }
        fclose(fp);
    }
    if(!found) strcpy(buffer, "No matching records found");
    send(clientSocket, buffer, strlen(buffer), 0);
}
int main(){
    int server_fd, clientSocket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) exit(EXIT_FAILURE);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) exit(EXIT_FAILURE);
    listen(server_fd, 5);
    while(1){
        clientSocket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if(clientSocket < 0) continue;
        char buffer[BUFFER_SIZE];
        int n = read(clientSocket, buffer, sizeof(buffer));
        if(n <= 0){
            close(clientSocket);
            continue;
        }
        buffer[n] = '\0';
        char *token = strtok(buffer, ":");
        if(token == NULL){
            close(clientSocket);
            continue;
        }
        int option = atoi(token);
        char response[BUFFER_SIZE];
        response[0] = '\0';
        if(option == 1){
            char *title = strtok(NULL, ":");
            char *author = strtok(NULL, ":");
            char *accession = strtok(NULL, ":");
            char *pagesStr = strtok(NULL, ":");
            char *publisher = strtok(NULL, ":");
            if(title && author && accession && pagesStr && publisher){
                char record[512];
                sprintf(record, "%s|%s|%s|%s|%s", title, author, accession, pagesStr, publisher);
                insertBook(record);
                strcpy(response, "Book inserted successfully");
            } else {
                strcpy(response, "Invalid data for insertion");
            }
            send(clientSocket, response, strlen(response), 0);
        } else if(option == 2){
            char *accession = strtok(NULL, ":");
            if(accession){
                FILE *fp = fopen("database.txt", "r");
                int exists = 0;
                if(fp){
                    char line[512];
                    while(fgets(line, sizeof(line), fp)){
                        char rec[512];
                        strcpy(rec, line);
                        char *dummy = strtok(rec, "|");
                        dummy = strtok(NULL, "|");
                        char *acc = strtok(NULL, "|");
                        if(acc && strcmp(acc, accession)==0){
                            exists = 1;
                            break;
                        }
                    }
                    fclose(fp);
                }
                if(exists){
                    deleteBook(accession);
                    strcpy(response, "Book deleted successfully");
                } else {
                    strcpy(response, "Book not found");
                }
            } else {
                strcpy(response, "Invalid data for deletion");
            }
            send(clientSocket, response, strlen(response), 0);
        } else if(option == 3){
            displayAll(clientSocket);
        } else if(option == 4){
            char *criteria = strtok(NULL, ":");
            char *searchKey = strtok(NULL, ":");
            if(criteria && searchKey){
                searchBook(clientSocket, criteria, searchKey);
            } else {
                strcpy(response, "Invalid search criteria");
                send(clientSocket, response, strlen(response), 0);
            }
        } else if(option == 5){
            strcpy(response, "Exit");
            send(clientSocket, response, strlen(response), 0);
            close(clientSocket);
            break;
        } else {
            strcpy(response, "Invalid option");
            send(clientSocket, response, strlen(response), 0);
        }
        close(clientSocket);
    }
    close(server_fd);
    return 0;
}