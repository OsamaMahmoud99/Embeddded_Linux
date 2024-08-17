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
	while(idx <5)
	{
		printf("Hello world from thread \n");
		idx++;
	}
}

int main(int argc, int **argv)
{		
	pthread_t mythread;
	pthread_create(&mythread, NULL,thread,NULL);
	pthread_join(mythread,NULL); // pthread_join will block main thread to run untill given thread finish 
	while(idx1 <5)
	{
		printf("Hi main\n");
		idx1++;
	}
}
