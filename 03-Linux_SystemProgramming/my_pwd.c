#include <unistd.h>
#include <stdio.h>

int main()
{
	char cwd[200];

	if(getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd");
		return 1;
	}

	return 0;

}
