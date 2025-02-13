#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define MAXLINE 1024

// Structure to hold vowel counts
struct VowelCount {
    int a;
    int e;
    int i;
    int o;
    int u;
};

// Function to check if string is palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;
    
    // Convert to lowercase for comparison
    char *temp = (char *)malloc(len + 1);
    for(i = 0; i < len; i++) {
        temp[i] = tolower(str[i]);
    }
    temp[len] = '\0';
    
    for(i = 0, j = len - 1; i < j; i++, j--) {
        while(i < j && !isalnum(temp[i])) i++;
        while(i < j && !isalnum(temp[j])) j--;
        if(temp[i] != temp[j]) {
            free(temp);
            return 0;
        }
    }
    free(temp);
    return 1;
}

// Function to count vowels
struct VowelCount countVowels(char *str) {
    struct VowelCount count = {0, 0, 0, 0, 0};
    int i;
    for(i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        switch(c) {
            case 'a': count.a++; break;
            case 'e': count.e++; break;
            case 'i': count.i++; break;
            case 'o': count.o++; break;
            case 'u': count.u++; break;
        }
    }
    return count;
}

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;
    
    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
    // Server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    // Bind socket with server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is running...\n");
    
    while(1) {
        int len = sizeof(cliaddr);
        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0,
                        (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        
        // Check if client wants to halt
        if(strcmp(buffer, "Halt") == 0) {
            printf("Received halt command. Server shutting down...\n");
            break;
        }
        
        // Process the received string
        int isPal = isPalindrome(buffer);
        struct VowelCount vowels = countVowels(buffer);
        int strLen = strlen(buffer);
        
        // Prepare response
        char response[MAXLINE];
        sprintf(response, "String Length: %d\nIs Palindrome: %s\nVowel Counts:\na: %d\ne: %d\ni: %d\no: %d\nu: %d",
                strLen,
                isPal ? "Yes" : "No",
                vowels.a, vowels.e, vowels.i, vowels.o, vowels.u);
        
        // Send response back to client
        sendto(sockfd, response, strlen(response), 0,
               (const struct sockaddr *)&cliaddr, len);
        
        printf("Processed string: %s\n", buffer);
    }
    
    close(sockfd);
    return 0;
}
