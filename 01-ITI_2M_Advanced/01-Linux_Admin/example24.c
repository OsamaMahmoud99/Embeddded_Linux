#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<pthread.h>
pthread_mutex_t fill_mutex;
int arr[10];
int flag=0;
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;
void *myfill()
{
	int i=0;
	for(i=0;i<4;i++)
	{
		pthread_mutex_lock(&fill_mutex);
		arr[i]=i;
		pthread_mutex_unlock(&fill_mutex);
		sleep(1);
		
	}
}
void *myread()
{
	int i=0;
	printf("The filled values are");
	for(i=0;i<4;i++)
	{	
		sleep(1);
		pthread_mutex_lock(&fill_mutex);
			printf("\n %d \n",arr[i]);
		pthread_mutex_unlock(&fill_mutex);
	}
}

int main(int argc, int **argv)
{		
	int result=0;
	pthread_t mythread1,mythread2;
	
	pthread_create(&mythread1, NULL,&myfill,NULL);
	pthread_create(&mythread2, NULL,&myread,NULL);
	printf("create the thread\n");
	pthread_join(mythread1,&result);
	pthread_join(mythread2,&result);
}