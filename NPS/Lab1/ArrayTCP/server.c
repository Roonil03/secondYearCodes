#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024
#define MAX_NUMBERS 100

// Function to sort numbers in ascending order
void sort_ascending(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to sort numbers in descending order
void sort_descending(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};
    char response[MAX_BUFFER] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("New client connected\n");
        
        while(1) {
            memset(buffer, 0, MAX_BUFFER);
            memset(response, 0, MAX_BUFFER);
            
            // Receive data from client
            int valread = read(new_socket, buffer, MAX_BUFFER);
            if (valread <= 0 || strcmp(buffer, "exit") == 0) {
                printf("Client disconnected\n");
                break;
            }
            
            // Parse the received data
            int choice, numbers[MAX_NUMBERS], count = 0;
            char *token = strtok(buffer, " ");
            choice = atoi(token);
            
            while ((token = strtok(NULL, " ")) != NULL && count < MAX_NUMBERS) {
                numbers[count++] = atoi(token);
            }
            
            // Process based on choice
            switch(choice) {
                case 1: { // Search
                    int target = numbers[0];
                    int found = 0;
                    for(int i = 1; i < count; i++) {
                        if(numbers[i] == target) {
                            sprintf(response, "Number %d found at position %d", target, i);
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        sprintf(response, "Number %d not found", target);
                    }
                    break;
                }
                case 2: { // Sort ascending
                    sort_ascending(numbers, count);
                    sprintf(response, "Sorted ascending: ");
                    for(int i = 0; i < count; i++) {
                        char num[20];
                        sprintf(num, "%d ", numbers[i]);
                        strcat(response, num);
                    }
                    break;
                }
                case 3: { // Sort descending
                    sort_descending(numbers, count);
                    sprintf(response, "Sorted descending: ");
                    for(int i = 0; i < count; i++) {
                        char num[20];
                        sprintf(num, "%d ", numbers[i]);
                        strcat(response, num);
                    }
                    break;
                }
                case 4: { // Split odd/even
                    char odds[MAX_BUFFER] = "";
                    char evens[MAX_BUFFER] = "";
                    for(int i = 0; i < count; i++) {
                        char num[20];
                        sprintf(num, "%d ", numbers[i]);
                        if(numbers[i] % 2 == 0)
                            strcat(evens, num);
                        else
                            strcat(odds, num);
                    }
                    sprintf(response, "Odd numbers: %s\nEven numbers: %s", odds, evens);
                    break;
                }
                default:
                    strcpy(response, "Invalid choice");
            }
            
            // Send response back to client
            send(new_socket, response, strlen(response), 0);
        }
        close(new_socket);
    }
    return 0;
}
