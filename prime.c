#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int main(int argc, char *argv[])
{
int num = atoi(argv[2]);
int min = atoi(argv[1]);
int i,j,k=0,square;
int primes[1000000];
clock_t start = clock();
printf("2, ");
for(i=min;i<num;i++)
    {
    square=(sqrt(i)+1);
    for(j=2;j<=square;j++)
    if(!(i%j)) break; 
    if(j>square){
        primes[k]=i; // printf("%d, ", i);
        k++;
        }
    }
clock_t stop = clock();
for (i=0;i<k;i++)
    printf("%d, ",primes[i]);
printf("\n--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
return 0;
}
