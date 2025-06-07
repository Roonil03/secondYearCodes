#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 2048
#define PORT 8080

typedef struct data{
	int id;
	char name[30];
	int age;
	char disease[30];
}base;

int main()
{
	
	char sed[MAXSIZE*2];
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[MAXSIZE];
	
	int a=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("Server Running!\n");
	if(sockfd==-1)
	{
	printf("\nSocket creation error");
	}

	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(PORT);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}

	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);
	}
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
	if(newsockfd==-1)
	{
		close(sockfd);
	}
	base b[30];
	int t = 2;
	
	b[0].id = 101;
	strcpy(b[0].name, "John Doe");
	b[0].age = 50;
	strcpy(b[0].disease, "Asthma");
	
	b[1].id = 102;
	strcpy(b[1].name, "Alice Smith");
	b[1].age = 50;
	strcpy(b[1].disease, "Diabetes");
	
	b[2].id = 103;
	strcpy(b[2].name, "Mark Wilson");
	b[2].age = 50;
	strcpy(b[2].disease, "Asthma");
	/*
	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);
	}
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
	if(newsockfd==-1)
	{
		close(sockfd);
	}
	*/
	int s = 0;
	while(1){
		memset(buff, '\0', sizeof(buff));
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		if(recedbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		
		if (buff[0] == 'e' && buff[1] == 'x' && buff[2] == 'i' && buff[3] == 't')
		{
			break;
		}
		int choice = buff[0] - '0';
		memset(sed, '\0', sizeof(sed));
		switch(choice){
		case 1:
		printf("%s\n", buff);
		int i = 2;
		char n[30];
		int id = 0;
		int age = 0;
		char d1[30];
		while(buff[i] != ' '){
			id = id*10 + (buff[i]-'0');
			i++;
			}
			printf("%d\n", id);
		i++;
		int abc = 0;
		while(buff[i] != ' '){
		n[abc++] = buff[i];
		i++;
		}
		n[abc] = '\0';
		printf("%s\n", n);
		i++;
		while(buff[i] != ' '){
			age = age*10 + (buff[i]-'0');
			i++;
			}
			
			printf("%d\n", age);
		i++;
		t++;
		b[t].id = id;
		b[t].age = age;
		strcpy(b[t].name, n);
		abc = 0;
		while(buff[i] != '\0'){
		d1[abc++] = buff[i];
		i++;
		}
		d1[abc] = '\0';
		printf("%s\n", d1);
		strcpy(b[t].disease, d1);
		break;
			case 2:
			for (int i = 0; i <= t; i++){
				char temp[1024];
				sprintf(temp, "ID: %d|Name: %s|Age: %d|Disease: %s\n", b[i].id, b[i].name, b[i].age, b[i].disease);
				strcat(sed, temp);
				}
			s = strlen(sed) * sizeof(char);
		sentbytes=send(newsockfd,sed,s,0);
		if(sentbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		break;
		case 3:
		char d3[MAXSIZE];
		int len = strlen(buff);
		for (int i = 2, j = 0; i < len; i++, j++){
			d3[j] = buff[i];
			}
		d3[len-2] = '\0';
		int count = 0;
		for (int i = 0; i <t+1; i++){
			if (strcmp(b[i].disease, d3) == 0){
				count++;
				}
				}
		sprintf(sed, "Number of patients with %s: %d", d3, count);
		s = strlen(sed) * sizeof(char);
		sentbytes=send(newsockfd,sed,s,0);
		if(sentbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		break;
		case 4:
		char d4[MAXSIZE];
		int len1 = strlen(buff);
		for (int i = 2, j = 0; i < len1; i++, j++){
			d4[j] = buff[i];
			}
		d4[len-2] = '\0';
		float avg = 0;
		int sum = 0;
		int count1 = 0;
		for (int i = 0; i <t+1; i++){
			if (strcmp(b[i].disease, d4) == 0){
				sum += b[i].age;
				count1++;
				}
				}
		avg = (float)sum/count1;
		sprintf(sed, "Average age of patients with %s is: %f", d4, avg);
		s = strlen(sed) * sizeof(char);
		sentbytes=send(newsockfd,sed,s,0);
		if(sentbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		break;
		
		default:
		printf("Server side error!");
		exit(0);
		break;
		}
	}
	close(sockfd);
			close(newsockfd);
			return 0;
}
		
