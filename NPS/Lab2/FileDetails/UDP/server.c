#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8889
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
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }
    
    printf("UDP Server listening on port %d\n", PORT);
    
    while (1) {
        socklen_t len = sizeof(client_addr);
        memset(buffer, 0, BUFFER_SIZE);
        
        int n = recvfrom(server_fd, buffer, BUFFER_SIZE, MSG_WAITALL,
                        (struct sockaddr *)&client_addr, &len);
        buffer[n] = '\0';
        
        if (strcmp(buffer, "stop") == 0) continue;
        
        FILE *file = fopen(buffer, "r");
        if (file == NULL) {
            strcpy(response, "File not found");
            sendto(server_fd, response, strlen(response), MSG_CONFIRM,
                  (struct sockaddr *)&client_addr, len);
            continue;
        }
        
        struct FileStats stats = analyze_file(file);
        
        sprintf(response, "File Statistics:\nSize: %ld bytes\nAlphabets: %d\nDigits: %d\nSpaces: %d\nLines: %d\nOther characters: %d\n\nFile Contents:\n",
                stats.filesize, stats.alphabets, stats.digits,
                stats.spaces, stats.lines, stats.others);
        
        sendto(server_fd, response, strlen(response), MSG_CONFIRM,
               (struct sockaddr *)&client_addr, len);
        
        fseek(file, 0, SEEK_SET);
        while (fgets(buffer, BUFFER_SIZE, file)) {
            sendto(server_fd, buffer, strlen(buffer), MSG_CONFIRM,
                   (struct sockaddr *)&client_addr, len);
        }
        
        strcpy(buffer, "EOF");
        sendto(server_fd, buffer, strlen(buffer), MSG_CONFIRM,
               (struct sockaddr *)&client_addr, len);
        
        fclose(file);
    }
    
    close(server_fd);
    return 0;
}
