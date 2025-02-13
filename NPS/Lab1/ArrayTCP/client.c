#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024

void display_menu() {
    printf("\n=== Menu ===\n");
    printf("1. Search a number\n");
    printf("2. Sort in ascending order\n");
    printf("3. Sort in descending order\n");
    printf("4. Split into odd and even numbers\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};
    char message[MAX_BUFFER] = {0};
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }
    
    printf("Connected to server\n");
    
    while(1) {
        display_menu();
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 5) {
            send(sock, "exit", 4, 0);
            printf("Disconnecting from server...\n");
            break;
        }
        
        if(choice < 1 || choice > 4) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        // Clear input buffer
        while(getchar() != '\n');
        
        memset(message, 0, MAX_BUFFER);
        memset(buffer, 0, MAX_BUFFER);
        
        // Format: choice numbers
        sprintf(message, "%d ", choice);
        
        if(choice == 1) {
            printf("Enter the number to search: ");
            int target;
            scanf("%d", &target);
            char temp[20];
            sprintf(temp, "%d ", target);
            strcat(message, temp);
            
            printf("Enter numbers (space-separated, end with newline): ");
            while(getchar() != '\n');  // Clear buffer
            
            char numbers[MAX_BUFFER];
            fgets(numbers, MAX_BUFFER, stdin);
            strcat(message, numbers);
        } else {
            printf("Enter numbers (space-separated, end with newline): ");
            char numbers[MAX_BUFFER];
            fgets(numbers, MAX_BUFFER, stdin);
            strcat(message, numbers);
        }
        
        // Remove trailing newline
        message[strcspn(message, "\n")] = 0;
        
        // Send message to server
        send(sock, message, strlen(message), 0);
        
        // Receive response
        int valread = read(sock, buffer, MAX_BUFFER);
        printf("\nServer response: %s\n", buffer);
    }
    
    close(sock);
    return 0;
}
