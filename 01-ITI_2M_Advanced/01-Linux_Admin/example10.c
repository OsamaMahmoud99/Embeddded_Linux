
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 

int main(int argc, int **argv)
{
		pid_t pid;
		pid= fork();
		unsigned int i =1;
		while(i>0)
		{	
			printf("%d",i);
			if(pid>0)
			{
				printf("parent id %d \n",pid);
				printf("parent of parent id %d \n",getppid());

			}
			else if(pid ==0)
			{
				printf("child id %d \n",pid);
				printf("parent of child id %d \n",getppid());
				while(1);						
			}
			else
			{
				perror("fork");
			}
			i--;
		}
		printf("end of prog  PID= %d\n",pid);
		//while(1);
		return 0;
}
