#include  <stdio.h>
#include  <signal.h>

#define   MAX_i    10000
#define   DIVISOR   1000
#define   MAX_j    20000

void  main(void)
{
     int            i;
     unsigned long  j, sum;
     /*Ignoring the signal*/
     signal(SIGINT, SIG_IGN);
     printf(" Pressing Ctrl-C has no effect....\n");
     for (i = 1; i <= MAX_i; i++)  {
          sum = 0;
          for (j = 0; j <= MAX_j; j++)
               sum += j;
          if (i % DIVISOR == 0)
               printf("Iteration %d, sum = %ld\n", i, sum);
     }
     printf("Computation is done.\n\n");
     /*using default signal handler */
     signal(SIGINT, SIG_DFL);     
     printf("Pressing Ctrl-C HAS effect now...\n");
     for (i = 1; i <= MAX_i; i++)  {
          sum = 0;
          for (j = 0; j <= MAX_j; j++)
               sum += j;
          if (i % DIVISOR == 0)
               printf("Iteration %d, sum = %ld\n", i, sum);
     }
     printf("Computation is done.\n");
}
