#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
//case1: remove child while each process will run independently
//int main(int argc, int **argv)
//{
//		pid_t pid;
//		pid= fork();
//		unsigned int i = 3;
//		while(i--)
//		{
//			if(pid>0)
//			{
//				printf("parent id %d \n",getpid());
//				printf("parent of parent id %d \n",getppid());
//
//			}
//			else if(pid == 0)
//			{
//				printf("child id %d \n",getpid());
//				printf("parent of child id %d \n",getppid());
//				//while(1);
//			}
//			else
//			{
//				//Perror is used for
//				perror("fork");
//			}
//		}
//
//}

//case2: if parent dead > child will be adopted but by whom ??
int main(int argc, int **argv)
{
		pid_t pid;
		pid= fork();
		unsigned int i =3;
		while(i--)
		{
			if(pid>0)
			{
				printf("parent id %d \n",getpid());
				printf("parent of parent id %d \n",getppid());
				return 0;
			}
			else if(pid == 0)
			{
				while(1)
				{
					printf("child id %d \n",getpid());
					printf("parent of child id %d \n",getppid());
				}
			}
			else
			{
				//Perror is used for
				perror("fork");
			}
		}
		printf("*PID* %d\n",getpid());

}

