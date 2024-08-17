#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<pthread.h>

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
	pthread_t mythread;
	pthread_create(&mythread, NULL,thread,NULL);
	while(1)
	{
		printf("Hi main\n");
	}
}