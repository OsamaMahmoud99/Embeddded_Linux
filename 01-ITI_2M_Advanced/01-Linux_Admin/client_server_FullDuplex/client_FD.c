#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE  1024
#define PORT 8080
#define SA struct sockaddr

void *receive_messages(void *socket_desc) {
	
	int sock = *(int *) socket_desc;
	char buffer[BUFFER_SIZE];
	int bytes_read;
	
	
	while((bytes_read = read(sock , buffer , BUFFER_SIZE)) > 0) {
		
		buffer[bytes_read] = '\0';
		printf("From Server: %s", buffer);
		
	}

	return NULL;
	
}

void *send_messages(void *socket_desc) {
	
	int sock = *(int *)socket_desc;
	char buffer[BUFFER_SIZE];
	
	while(1){
		fgets(buffer, BUFFER_SIZE, stdin);
		send(sock, buffer, strlen(buffer), 0);
	}
	
	return NULL;
	
}
int main(void)
{
	int sock = 0;
	struct sockaddr_in servaddr;
	
	int addrlen = sizeof(servaddr);
	pthread_t recv_thread, send_thread;

	if((sock = socket(AF_INET, SOCK_STREAM , 0)) < 0){
		
		perror("socket creation error");
		exit(0);
	}


	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, "10.0.2.15", &servaddr.sin_addr)  <= 0){
		perror("Invalid address/  Address not supported");
		close(sock);
		exit(0);
	}


	if(connect(sock , (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connection failed");
		close(sock);
		exit(0);
	}
	


	pthread_create(&recv_thread , NULL, receive_messages, (void *)&sock);
	pthread_create(&send_thread, NULL, send_messages, (void *)&sock);
	
	pthread_join(recv_thread, NULL);
	pthread_join(send_thread, NULL);
	
	
	

	close(sock);

	
	return 0;
}
