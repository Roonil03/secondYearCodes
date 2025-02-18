#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080
#define BUFFER_SIZE 1024
char* lookup_domain(const char* domain) {
    FILE* fp = fopen("database.txt", "r");
    if (!fp) return NULL;
    char line[256];
    static char ip[64];
    while (fgets(line, sizeof(line), fp)) {
        char dname[128], dip[64];
        if (sscanf(line, "%s %s", dname, dip) == 2) {
            if (strcmp(domain, dname) == 0) {
                strcpy(ip, dip);
                fclose(fp);
                return ip;
            }
        }
    }
    fclose(fp);
    return NULL;
}
int main(){
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) exit(1);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) exit(1);
    listen(sockfd, 5);
    while(1){
        clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if(newsockfd < 0) continue;
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));
        read(newsockfd, buffer, sizeof(buffer));
        char *ip = lookup_domain(buffer);
        char response[BUFFER_SIZE];
        memset(response, 0, sizeof(response));
        if(ip)
            snprintf(response, sizeof(response), "Domain %s resolved to %s", buffer, ip);
        else
            snprintf(response, sizeof(response), "Domain %s not found", buffer);
        write(newsockfd, response, strlen(response));
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}