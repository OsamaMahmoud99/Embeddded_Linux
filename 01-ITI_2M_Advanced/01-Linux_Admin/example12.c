#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 

/*By using wait we will wait till child die*/
int main(int argc, int **argv)
{		
		printf("Parent of Parent: %d\n",getppid());
		pid_t pid;
		pid= fork();

			if(pid == 0)
			{
				printf("Child with pid %d\n",getpid());
				sleep(5); // child  will sleep for 5 sec
				printf("Child finished\n");
				exit(0);// finishing child
			}
			else if(pid > 0)
			{
				printf("Parent PID: %d\n",getpid());
			}
			else
			{

			}
			
			wait(NULL);
			printf("I am called only from parent and pid is %d\n",getpid());

		return 0;
}
