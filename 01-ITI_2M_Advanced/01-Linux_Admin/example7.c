
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
/*The execl() function replaces the current process image with a new process image specified by path. The new image is constructed from a regular,
executable file called the new process image file. No return is made because the calling process image is replaced by the new process image.*/
// use objdump -d ex7 to dump your code
int main(void)
{ 
	int x=1;
	printf("Before execl: x= %d\n",x);
	execl("/bin/ls","ls","-alh",NULL);
	x++;
	printf("After\n");
	while(1);
	return 0;
}
