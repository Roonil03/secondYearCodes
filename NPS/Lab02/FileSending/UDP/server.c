#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAXSIZE 150
#define PORT 3388

int countInLine(const char *line, const char *word) {
    int count = 0;
    const char *pos = line;
    int word_len = strlen(word);
    
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += word_len;
    }
    return count;
}

int replace(FILE* f, const char* str1, const char* str2) {
    char* text = NULL;
    long length;
    int found = 0;
    
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    text = (char *)malloc(length + 1);
    if (!text) return 0;
    
    fread(text, 1, length, f);
    text[length] = '\0';
    
    char *result = (char *)malloc(length * 2);
    if (!result) {
        free(text);
        return 0;
    }
    
    char *pos = text;
    char *current = result;
    
    while ((pos = strstr(pos, str1)) != NULL) {
        found = 1;
        int len = pos - text;
        strncpy(current, text, len);
        current += len;
        strcpy(current, str2);
        current += strlen(str2);
        text = pos + strlen(str1);
        pos = text;
    }
    
    strcpy(current, text);
    
    if (found) {
        fseek(f, 0, SEEK_SET);
        fputs(result, f);
        ftruncate(fileno(f), strlen(result));
    }
    
    free(text);
    free(result);
    return found;
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(FILE* f) {
    char *lines[1024];
    char buffer[1024];
    int line_count = 0;
    
    fseek(f, 0, SEEK_SET);
    
    while (fgets(buffer, sizeof(buffer), f) && line_count < 1024) {
        buffer[strcspn(buffer, "\n")] = '\0';
        lines[line_count] = strdup(buffer);
        if (!lines[line_count]) return;
        line_count++;
    }
    
    qsort(lines, line_count, sizeof(char *), compare);
    
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < line_count; i++) {
        fprintf(f, "%s\n", lines[i]);
        free(lines[i]);
    }
    ftruncate(fileno(f), ftell(f));
}

int main() {
    int sockfd;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[MAXSIZE];
    socklen_t client_len = sizeof(clientaddr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) return -1;
    
    memset(&serveraddr, 0, sizeof(serveraddr));
    memset(&clientaddr, 0, sizeof(clientaddr));
    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
        close(sockfd);
        return -1;
    }
    
    printf("UDP Server running on port %d...\n", PORT);
    
    while(1) {
        memset(buff, '\0', sizeof(buff));
        int n = recvfrom(sockfd, buff, sizeof(buff), 0,
                        (struct sockaddr*)&clientaddr, &client_len);
        
        if(n <= 0) continue;
        
        FILE* f = fopen(buff, "r+");
        if(!f) {
            sendto(sockfd, "File not present", 15, 0,
                   (struct sockaddr*)&clientaddr, client_len);
            continue;
        }
        
        sendto(sockfd, "File found", 9, 0,
               (struct sockaddr*)&clientaddr, client_len);
        
        while(1) {
            memset(buff, '\0', sizeof(buff));
            n = recvfrom(sockfd, buff, sizeof(buff), 0,
                        (struct sockaddr*)&clientaddr, &client_len);
            if(n <= 0) break;
            
            if(buff[0] == '1') {
                char word[MAXSIZE];
                recvfrom(sockfd, word, sizeof(word), 0,
                        (struct sockaddr*)&clientaddr, &client_len);
                int count = 0;
                char line[1000];
                
                fseek(f, 0, SEEK_SET);
                while(fgets(line, sizeof(line), f)) {
                    count += countInLine(line, word);
                }
                
                sprintf(buff, count ? "Found %d occurrences" : "String not found", count);
                sendto(sockfd, buff, strlen(buff), 0,
                       (struct sockaddr*)&clientaddr, client_len);
            }
            else if(buff[0] == '2') {
                char str1[MAXSIZE], str2[MAXSIZE];
                recvfrom(sockfd, buff, sizeof(buff), 0,
                        (struct sockaddr*)&clientaddr, &client_len);
                sscanf(buff, "%s %s", str1, str2);
                
                int result = replace(f, str1, str2);
                sendto(sockfd, result ? "String replaced" : "String not found", 15, 0,
                       (struct sockaddr*)&clientaddr, client_len);
            }
            else if(buff[0] == '3') {
                sort(f);
                sendto(sockfd, "File reordered", 13, 0,
                       (struct sockaddr*)&clientaddr, client_len);
            }
            else if(buff[0] == '4') {
                sendto(sockfd, "Goodbye", 7, 0,
                       (struct sockaddr*)&clientaddr, client_len);
                fclose(f);
                break;
            }
        }
    }
    
    close(sockfd);
    return 0;
}
