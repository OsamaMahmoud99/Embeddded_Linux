
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
		int status;
		int x=5;
		int y=10;
		
			if(pid>0)
			{
				printf("Parent pid %d \n",getpid());
				/*Wait for a child to die*/
				pid=wait(&status);
			}
			else if(pid ==0)
			{
				printf("child pid %d \n",getpid());
				return (x+y);
			}
			else
			{
				perror("fork");
			}
		printf("parent PID is %d\n",getpid());
		printf("valus is : %d\n ",WEXITSTATUS(status));
		return 0;
}
