#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
/*This example to show you how to assign code to each process */
/*Run code multiple times to know that child could run before parent*/
void forkExample(void);
void forkExample(void)
{
	pid_t PID;
    PID=fork();
	// child process because return value zero 
	if ( 0 == PID )
	{
		printf("Hello from Child!\n"); 
		return 0; //for zombie proccess
	}

	// parent process because return value non-zero. 
	else if (0 < PID)
	{
		printf("Hello from Parent!\n"); 
		sleep(10); //for zombie process
		//while(1);
	}
	else
		printf("fork failed!\n");
} 
int main(void)
{ 
	forkExample();
	printf("After fork\n");
	return 0; 
} 
