#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>

struct student {
    char reg[10];
    char name[50];
    char address[100];
    char dept[50];
    int semester;
    char section[10];
    char courses[100];
    char subject_code[20];
    int marks;
};

struct student db[] = {
    {"101", "Alice", "123 Main St", "CS", 1, "A", "Math,Physics", "MATH123", 85},
    {"102", "Bob", "456 Oak Ave", "EE", 2, "B", "Circuits,Signals", "EE202", 90}
};
int db_size = sizeof(db) / sizeof(db[0]);

struct student* find_by_reg(char *key) {
    for (int i = 0; i < db_size; i++) {
        if (strcmp(db[i].reg, key) == 0) return &db[i];
    }
    return NULL;
}

struct student* find_by_name(char *key) {
    for (int i = 0; i < db_size; i++) {
        if (strcmp(db[i].name, key) == 0) return &db[i];
    }
    return NULL;
}

struct student* find_by_subject(char *key) {
    for (int i = 0; i < db_size; i++) {
        if (strcmp(db[i].subject_code, key) == 0) return &db[i];
    }
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) exit(EXIT_FAILURE);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) exit(EXIT_FAILURE);
    if (listen(server_fd, 3) < 0) exit(EXIT_FAILURE);
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) continue;
        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);
        char option[10], key[100];
        memset(option, 0, sizeof(option));
        memset(key, 0, sizeof(key));
        char *token = strtok(buffer, ":");
        if(token) {
            strcpy(option, token);
            token = strtok(NULL, ":");
            if(token) strcpy(key, token);
        }
        pid_t pid = fork();
        if (pid < 0) {
            close(new_socket);
            continue;
        }
        if (pid == 0) {
            char sendbuf[1024];
            memset(sendbuf, 0, sizeof(sendbuf));
            if (strcmp(option, "1") == 0) {
                struct student *s = find_by_reg(key);
                if (s) {
                    sprintf(sendbuf, "Child PID: %d, Name: %s, Address: %s", getpid(), s->name, s->address);
                } else {
                    sprintf(sendbuf, "Child PID: %d, Registration number not found", getpid());
                }
            }
            else if (strcmp(option, "2") == 0) {
                struct student *s = find_by_name(key);
                if (s) {
                    sprintf(sendbuf, "Child PID: %d, Dept: %s, Semester: %d, Section: %s, Courses: %s", getpid(), s->dept, s->semester, s->section, s->courses);
                } else {
                    sprintf(sendbuf, "Child PID: %d, Name not found", getpid());
                }
            }
            else if (strcmp(option, "3") == 0) {
                struct student *s = find_by_subject(key);
                if (s) {
                    sprintf(sendbuf, "Child PID: %d, Marks: %d", getpid(), s->marks);
                } else {
                    sprintf(sendbuf, "Child PID: %d, Subject code not found", getpid());
                }
            }
            else {
                sprintf(sendbuf, "Child PID: %d, Invalid option", getpid());
            }
            write(new_socket, sendbuf, strlen(sendbuf));
            close(new_socket);
            exit(0);
        } else {
            close(new_socket);
            waitpid(-1, NULL, WNOHANG);
        }
    }
    return 0;
}