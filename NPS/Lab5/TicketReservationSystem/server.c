#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 8080
typedef struct {
    int seats_available;
    int seats_booked;
    char source[50];
    char destination[50];
} route_t;
route_t route1 = {40, 0, "CityA", "CityB"};
route_t route2 = {40, 0, "CityC", "CityD"};
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *handle_client(void *arg) {
    int sock = *(int *)arg;
    free(arg);
    char buffer[1024];
    int route_no, seats_requested;
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer));
    route_no = atoi(buffer);
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer));
    seats_requested = atoi(buffer);
    char response[256];
    pthread_mutex_lock(&lock);
    route_t *r;
    if(route_no == 1)
        r = &route1;
    else if(route_no == 2)
        r = &route2;
    else {
        sprintf(response, "Invalid route selection.");
        write(sock, response, strlen(response));
        pthread_mutex_unlock(&lock);
        close(sock);
        return NULL;
    }
    if(r->seats_available >= seats_requested) {
        r->seats_available -= seats_requested;
        r->seats_booked += seats_requested;
        sprintf(response, "Booking successful. Route %d: %s->%s. Seats booked: %d, Seats available: %d", route_no, r->source, r->destination, r->seats_booked, r->seats_available);
    } else {
        sprintf(response, "Booking failed. Not enough seats available on Route %d: %s->%s. Seats available: %d", route_no, r->source, r->destination, r->seats_available);
    }
    pthread_mutex_unlock(&lock);
    write(sock, response, strlen(response));
    close(sock);
    return NULL;
}
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);
    while(1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        pthread_t tid;
        int *pclient = malloc(sizeof(int));
        *pclient = new_socket;
        pthread_create(&tid, NULL, handle_client, pclient);
        pthread_detach(tid);
    }
    close(server_fd);
    return 0;
}