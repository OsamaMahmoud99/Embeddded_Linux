

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 

static int datavalue=20;
int main(int argc, int **argv)
{		
		int stackvalue=10;
		pid_t pid;
		pid= fork();

			if(pid > 0)
			{
				stackvalue *=3;
				datavalue *=3;	

			}
			else if(pid == 0)
			{
				stackvalue *=2;
				datavalue *=2;					
			}
			else
			{
				perror("fork");
			}
			
			if(pid > 0)
			{
				printf("parent values %d %d \n",stackvalue,datavalue);
			}
			else if(pid == 0)
			{
				printf("Child values %d %d \n",stackvalue,datavalue);				
			}
		return 0;
}
