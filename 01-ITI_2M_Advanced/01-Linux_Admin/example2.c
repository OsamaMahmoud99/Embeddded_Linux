#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
/*This example to show you Nested fork */
int main() 
{ 
	fork(); 
	fork(); 
	fork(); 
	printf("hello\n"); 
	return 0; 
} 

//run this on you terminal to know number of nested processes
//./ex2 | wc -w
/*		  F0
       /   |   \
     F1    F3   F2
    /  \          \
  F2    F3         F5
 /
F3*/

