#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample();
//To run code: ./ex5 &
/*This example will show you PID of each process and its parent */
void forkexample()
{
	pid_t PID;
    PID=fork();
	// child process because return value zero
	if ( 0 == PID )
	{

		printf("Hello from Child! my PID is: %d\n",getpid());
		printf("Hello from Child! my PPID is: %d\n",getppid());
		while(1);
	// parent process because return value non-zero.
	}
	else if (0 < PID)
	{
		printf(" *PID* is: %d!\n",PID);
		printf("Hello from Parent my PID is: %d!\n",getpid());
		printf("Hello from Parent my PPID is: %d!\n",getppid());
		while(1);
	}

	else
		printf("fork failed!\n");
}
int main(int argc, int *argv[]) 
{ 
	forkexample();
	printf("Fork finished\n");
	return 0;
}
