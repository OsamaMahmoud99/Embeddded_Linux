#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>

/*This example to show you how fork is work*/
/*use strace .ex1 to debug your code running in linux and view your system calls*/
int main() 
{
	/*This code will be called only one time*/
	printf("*Befor Fork*\n");
	pid_t PID;
    PID=fork();
    /*After fork 2 proccesses will be created, parent and its child*/
   	printf("Hello world!\n");
	while(1);
    return 0;
} 
