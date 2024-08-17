#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<pthread.h>
int idx=0;
int idx1=1;
//run gcc example20.c -lpthread -o ex20
void *thread (void *data)
{	

	while(1)
	{
		printf("Hello world from thread \n");
	}
}

int main(int argc, int **argv)
{		
	int threadcancel, result=0;
	pthread_t mythread;
	pthread_create(&mythread, NULL,thread,NULL);
	sleep(1);
	printf("Cancelling the thread\n");
	threadcancel=pthread_cancel(mythread);
	pthread_join(mythread,&result);
	
	if(result == PTHREAD_CANCELED)
		printf("Created thread has been cancelled");

}
