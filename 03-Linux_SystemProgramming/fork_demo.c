#include <stdio.h>
#include <unistd.h>

int main()
{
	getchar();

	pid_t pid = fork();
	if(pid > 0)
	{
		printf("Parent: my pid = %d, my child pid = %d\n", getpid() , pid);
	}
	else if(pid == 0)
	{
		printf("Child: my pid = %d, my parent pid = %d\n", getpid() , getppid());
	}
	else
	{
		printf("Parent: failed to fork\n");
	}

	getchar();
	return 0;

}
