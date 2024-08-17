#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<pthread.h>
int idx=0;
//run gcc example22.c -lpthread -o ex22
void *thread (void *data)
{	

	while(1)
	{
			printf("Hello world from thread \n");
	}
}

int main(int argc, int **argv)
{		
	pthread_t mythread;
	pthread_create(&mythread, NULL,thread,NULL);
	sleep(3);
	pthread_join(mythread,NULL); // pthread_join will block main thread to run untill given thread finish 
	while(1)
	{
		printf("Hello world from main \n");
	}
}
