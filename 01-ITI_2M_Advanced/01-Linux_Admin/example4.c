#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main(int argc, int *argv[]) 
{ 
	printf("My example PID is %d\n",getpid());
	printf("My Parent PID is %d\n",getppid());
	while(1);
} 

// run ./ex5 &
