#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1234  // Define the port on which the server will listen

int main() {
    int server_fd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    int num1, num2, result, choice;

    // Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);  // Convert to network byte order
    server_addr.sin_addr.s_addr = INADDR_ANY; // Allow any incoming address
    memset(server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) == 0) {
        printf("Server is listening on port %d...\n", PORT);
    } else {
        perror("Error in listening");
        exit(1);
    }

    addr_size = sizeof(client_addr);
    new_sock = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
    if (new_sock < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Communicate with the client
    while(1) {
        recv(new_sock, &choice, sizeof(choice), 0);  // Receive the operation choice from the client
        recv(new_sock, &num1, sizeof(num1), 0);      // Receive first number
        recv(new_sock, &num2, sizeof(num2), 0);      // Receive second number

        switch(choice) {
            case 1:  // Addition
                result = num1 + num2;
                send(new_sock, &result, sizeof(result), 0);
                break;
            case 2:  // Subtraction
                result = num1 - num2;
                send(new_sock, &result, sizeof(result), 0);
                break;
            case 3:  // Multiplication
                result = num1 * num2;
                send(new_sock, &result, sizeof(result), 0);
                break;
            case 4:  // Division
                if (num2 == 0) {
                    char *error_msg = "Error: Division by zero!";
                    send(new_sock, error_msg, strlen(error_msg), 0);
                } else {
                    result = num1 / num2;
                    send(new_sock, &result, sizeof(result), 0);
                }
                break;
            case 5:  // Exit the server
                close(new_sock);
                close(server_fd);
                exit(0);
        }
    }

    return 0;
}
