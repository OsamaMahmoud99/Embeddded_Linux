#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
pid_t pid;
void sig_handler_parent(int signum){

	printf("Alarm Fired for parent PID=%d every 5 sec \n",pid);
	alarm(5);
}
void sig_handler_child(int signum){

	printf("Alarm Fired for child PID=%d every 10  sec \n",pid);
	alarm(10);
}
int main(int argc, int **argv)
{		
	printf("Parent of Parent: %d\n",getpid());

	pid = fork();

	if(pid == 0) // child
	{
		printf("Child with pid %d\n",pid);
		alarm(10);
		signal(SIGALRM,sig_handler_child);
	}
	else if (pid > 0) //parent
	{
		printf("Parent with pid %d\n",pid);
		alarm(5);
		signal(SIGALRM,sig_handler_parent);
	}
	else
	{
		perror("fork");
	}

	while(1);

	return 0;
}
