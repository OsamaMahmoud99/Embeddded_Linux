#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
// Handler for SIGINT, caused by 
// Ctrl-C at keyboard 
void handle_sigint(int sig) 
{ 
	printf("Caught signal %d\n", sig); 
	exit(0);
} 

int main() 
{ 
	signal(SIGINT, handle_sigint); 
	while (1) 
	{
		printf("Hi\n");
	}		
	return 0; 
} 
