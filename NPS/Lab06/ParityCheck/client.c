#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int calcpar(unsigned char data) {
    int count = 0;
    for(int i = 0; i < 8; i++) {
        if(data & (1 << i)) count++;
    }
    return count % 2;
}

int main() {
    int sockfd;
    struct sockaddr_un addr;
    unsigned char data[] = {0b10010011, 0b11001100, 0b01010101};
    int len = sizeof(data);    
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);    
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "sock");    
    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));    
    for(int i = 0; i < len; i++) {
        unsigned char byte = data[i];
        int parity = calcpar(byte);
        unsigned short packet = (byte << 1) | parity;        
        write(sockfd, &packet, sizeof(packet));
        printf("Sent: %02X with parity: %d\n", byte, parity);
    }    
    close(sockfd);
    return 0;
}
