#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
///int primes[]={1,2};
int main(int argc, char *argv[]){
int num = atoi(argv[1]);
    int i,j,v;
    int p=2;
    int square;
    int primes[]={1,2};
    clock_t start = clock();
    for (i=3;i<num;i+=2)
    {
        printf("%d loops\n",i);
        square=sqrt(i);
        for (j=3;j<(square+1);j+=2)
            {
            if (i%j==0)
                {
                break;
                }
        else
            {
            printf("%d is a prime \n",i);
            ++p;
            primes[p]=i;
            }
        }
    }
    clock_t stop = clock();
    for (v=(p-100);v<p;++v)
        {
        printf("%d \n",primes[v]);
        }
    printf("--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
}
