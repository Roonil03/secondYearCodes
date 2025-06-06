#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT 8080
int isAnagram(char *s1, char *s2){
    int len1 = strlen(s1), len2 = strlen(s2), i;
    if(len1 != len2)return 0;
    int count[256]={0};
    for(i=0;i<len1;i++){
        count[(unsigned char)s1[i]]++;
    }
    for(i=0;i<len2;i++){
        count[(unsigned char)s2[i]]--;
    }
    for(i=0;i<256;i++){
        if(count[i]!=0)return 0;
    }
    return 1;
}
int main(){
    int server_fd,new_socket;
    struct sockaddr_in address, client_addr;
    int addrlen = sizeof(address);
    char str1[100], str2[100], clientAddrStr[100];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd,(struct sockaddr*)&address,sizeof(address));
    listen(server_fd,3);
    while(1){
        new_socket = accept(server_fd,(struct sockaddr*)&client_addr,(socklen_t*)&addrlen);
        time_t now = time(NULL);
        printf("%s - Connected with client: %s:%d\n", ctime(&now), inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        recv(new_socket, str1, sizeof(str1), 0);
        recv(new_socket, str2, sizeof(str2), 0);
        recv(new_socket, clientAddrStr, sizeof(clientAddrStr), 0);
        char res[100];
        if(isAnagram(str1,str2))
            strcpy(res,"Strings are anagrams");
        else
            strcpy(res,"Strings are not anagrams");
        send(new_socket, res, strlen(res), 0);
        close(new_socket);
    }
    close(server_fd);
    return 0;
}