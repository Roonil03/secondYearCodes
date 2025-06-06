#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int calcpar(unsigned char data) {
    int count = 0;
    for(int i = 0; i < 8; i++) {
        if(data & (1 << i)){
            count++;
        }
    }
    return count % 2;
}

int main() {
    int srvfd, clifd;
    struct sockaddr_un srvaddr, cliaddr;
    socklen_t clilen;    
    unlink("sock");    
    srvfd = socket(AF_UNIX, SOCK_STREAM, 0);    
    srvaddr.sun_family = AF_UNIX;
    strcpy(srvaddr.sun_path, "sock");    
    bind(srvfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr));
    listen(srvfd, 5);    
    printf("Server waiting...\n");    
    clilen = sizeof(cliaddr);
    clifd = accept(srvfd, (struct sockaddr*)&cliaddr, &clilen);    
    unsigned short packet;
    while(read(clifd, &packet, sizeof(packet)) > 0) {
        unsigned char data = packet >> 1;
        int recpar = packet & 1;
        int exppar = calcpar(data);
        
        printf("Received: %02X, Parity: %d, Expected: %d", 
               data, recpar, exppar);
        
        if(recpar == exppar) {
            printf(" - OK\n");
        } else {
            printf(" - CORRUPT\n");
        }
    }    
    close(clifd);
    close(srvfd);
    unlink("sock");
    return 0;
}
