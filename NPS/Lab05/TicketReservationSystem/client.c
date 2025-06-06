#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
int main() {
    int sock;
    struct sockaddr_in serv_addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    int route_no, seats;
    char buffer[1024];
    printf("Available Routes:\n1: CityA -> CityB (40 seats available)\n2: CityC -> CityD (40 seats available)\n");
    printf("Enter route number: ");
    scanf("%d", &route_no);
    printf("Enter number of seats to book: ");
    scanf("%d", &seats);
    sprintf(buffer, "%d", route_no);
    write(sock, buffer, strlen(buffer) + 1);
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%d", seats);
    write(sock, buffer, strlen(buffer) + 1);
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("Server response: %s\n", buffer);
    close(sock);
    return 0;
}