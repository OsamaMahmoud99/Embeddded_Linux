// User-defined Signal Handler 
#include<stdio.h> 
#include<signal.h> 
#include <unistd.h>
// Handler for SIGINT, caused by 
// Ctrl-C at keyboard 
void singal_Handler(int sig) 
{ 
	printf("Caught signal inside signal handler, signo: %d\n", sig); 
	/*using sig handler after 2nd signal*/
	(void) signal(SIGINT,SIG_DFL);
} 

int main() 
{ 
	signal(SIGINT, singal_Handler); 
	while (1) 
	{
		printf("Hi\n");
		sleep(1);
	}		
	return 0; 
} 
