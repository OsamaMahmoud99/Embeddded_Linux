#include <stdio.h>

int main(int argc, char *argv[]) {
   
    printf("num of argc %d\n", argc);
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

