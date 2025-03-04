#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cwd = getcwd(NULL, 0); // Dynamically allocate buffer
    if (cwd != NULL) {
        printf("%s\n", cwd);
        free(cwd); // Free allocated memory
    } else {
        perror("getcwd failed");
        return 1;
    }
    return 0;

}
