#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8888
#define BUFFER_SIZE 1024

struct FileStats {
    long filesize;
    int alphabets;
    int lines;
    int spaces;
    int digits;
    int others;
};

struct FileStats analyze_file(FILE *file) {
    struct FileStats stats = {0, 0, 0, 0, 0, 0};
    char ch;
    
    fseek(file, 0, SEEK_END);
    stats.filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) stats.alphabets++;
        else if (isdigit(ch)) stats.digits++;
        else if (isspace(ch)) {
            stats.spaces++;
            if (ch == '\n') stats.lines++;
        }
        else stats.others++;
    }
    
    if (stats.filesize > 0 && stats.lines == 0) stats.lines = 1;
    
    return stats;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(1);
    }
    
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    while (1) {
        socklen_t addrlen = sizeof(address);
        client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }
        
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0) break;
            
            if (strcmp(buffer, "stop") == 0) break;
            
            FILE *file = fopen(buffer, "r");
            if (file == NULL) {
                strcpy(response, "File not found");
                send(client_fd, response, strlen(response), 0);
                continue;
            }
            
            struct FileStats stats = analyze_file(file);
            
            fseek(file, 0, SEEK_SET);
            memset(response, 0, BUFFER_SIZE);
            sprintf(response, "File Statistics:\nSize: %ld bytes\nAlphabets: %d\nDigits: %d\nSpaces: %d\nLines: %d\nOther characters: %d\n\nFile Contents:\n", 
                    stats.filesize, stats.alphabets, stats.digits, 
                    stats.spaces, stats.lines, stats.others);
            
            send(client_fd, response, strlen(response), 0);
            
            while (fgets(buffer, BUFFER_SIZE, file)) {
                send(client_fd, buffer, strlen(buffer), 0);
            }
            
            fclose(file);
        }
        
        close(client_fd);
    }
    
    close(server_fd);
    return 0;
}
