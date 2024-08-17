#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
//#include <sys/time.h>
// run in terminal time ./ex18, to prove that linux is not hard real time
//setitimer (1);  // Scheduled alarm after 1 seconds
void sig_handler(int signum){

	printf("Alarm Fired with signum %d\n",signum);
	exit(0);
}

int main()
{

	signal(SIGALRM,sig_handler); //  signal handler
	alarm(1);
	while(1)
	{
		sleep(1);
	}
	return 0;
}


