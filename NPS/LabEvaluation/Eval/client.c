#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

#define PORT 8080  // Server port to connect to

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[2048*2];  // Buffer to store server response
	
	int recedbytes,sentbytes;
    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);  // Convert to network byte order
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP (localhost)
    memset(server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }
    while(1){
    
	memset(buffer, '\0', sizeof(buffer));
    	printf("Menu:\n");    	
    	printf("1. Insert Patient Record\n");
    	printf("2. Display all patient records\n");
    	printf("3. Count Patient\n");
    	printf("4. Average Age of Patients\n");
    	printf("5. Exit\n\n");
    	int choice = 0;
    	scanf("%d", & choice);
    	switch(choice){
    		case 1:
    		char memory[1024];
    		int id = 0;
    		char name[30];
    		int age = 0;
    		char disease[30];
    		printf("Enter ID: ");
    		scanf("%d", &id);
    		printf("Enter name: ");
    		scanf("%s", name);
    		//printf("%s\n", name);
    		printf("Enter Age: ");
    		scanf("%d", &age);
    		//printf("%d\n", age);
    		printf("Enter Disease: ");
    		scanf("%s", memory);
    		//printf("%s\n", memory);
    		sprintf(buffer, "%d %d %s %d %s", choice, id, name, age, memory);
    		printf("%s\n", buffer);
    		break;
    		case 2:
    		sprintf(buffer, "%d", choice);
    		break;
    		case 3:
    		printf("Enter name of disease: ");
    		char dis[30];
    		scanf("%s", dis);
    		sprintf(buffer, "%d %s", choice, dis);
    		break;
    		case 4:
    		printf("Enter name of disease: ");
    		char d[30];
    		scanf("%s", d);
    		sprintf(buffer, "%d %s", choice, d);
    		break;
    		case 5:
    		printf("Exiting program!");
    		sprintf(buffer, "%s", "exit");
    		sentbytes=send(sockfd,buffer,strlen(buffer)*sizeof(char),0);
    		close(sockfd);
    		return 0;
    		default:
    		printf("Incorrect choice, exiting program!");
    		exit(0);
    	}
		sentbytes=send(sockfd,buffer,strlen(buffer)*sizeof(char),0);		
		memset(buffer, '\0', sizeof(buffer));
		recedbytes=recv(sockfd,buffer,sizeof(buffer),0);
		printf ("%s \n", buffer);
    		}
   close(sockfd);
   return 0;
   }
