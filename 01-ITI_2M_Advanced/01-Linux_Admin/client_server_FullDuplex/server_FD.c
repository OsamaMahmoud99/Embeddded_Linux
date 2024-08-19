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
	char buff[BUFFER_SIZE];
	int bytes_read;
	
	
	while((bytes_read = read(sock , buff , BUFFER_SIZE)) > 0) {
		
		buff[bytes_read] = '\0';
		printf("From Client: %s", buff);
		
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
	int server_fd, new_socket;
	struct sockaddr_in servaddr;
	
	int addrlen = sizeof(servaddr);
	pthread_t recv_thread, send_thread;

	if((server_fd = socket(AF_INET, SOCK_STREAM , 0)) == 0){
		
		perror("socket failed");
		exit(0);
	}


	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if((bind(server_fd, (SA*)&servaddr, sizeof(servaddr))) != 0){
		printf("socket bind failed...\n");
		close(server_fd);
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	if(listen(server_fd , 3) != 0) {
		printf("Listen failed...\n");
		close(server_fd);
		exit(0);
	}
	else
		printf("server is listening on port %d\n",PORT);

	

	if((new_socket = accept(server_fd, (SA*)&servaddr, (socklen_t*)&addrlen)) < 0){
			printf("server accetpt failed...\n");
			close(server_fd);
			exit(0);
	}
	else
		printf("server accept the client...\n");

	
	pthread_create(&recv_thread , NULL, receive_messages, (void *)&new_socket);
	pthread_create(&send_thread, NULL, send_messages, (void *)&new_socket);
	
	pthread_join(recv_thread, NULL);
	pthread_join(send_thread, NULL);
	
	
	

	close(new_socket);
	close(server_fd);
	
	return 0;
}
