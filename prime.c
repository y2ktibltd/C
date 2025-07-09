#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int main(int argc, char *argv[])
{
    unsigned int numPrimes;
        if(argv[1] == NULL){
        numPrimes = 1000000;
    } else {
        numPrimes = atoi(argv[1]);
    }

    //unsigned int numPrimes = atoi(argv[1]);
        unsigned int i,j,k=0,square;
        unsigned int primes[numPrimes+1];
        clock_t start = clock();
        for(i=2;k<=numPrimes;i++)
            {
            square=(sqrt(i));
            for(j=2;j<=square;j++)
            if(!(i%j))
                break;
            if(j>square){
                primes[k]=i;
                k++;
            }
        }
        clock_t stop = clock();

    for (i=0;i<5;i++)
        printf("%u,\n",primes[i]);

    printf(".\n.\n.\n.\n.\n");

    for (i=k-5;i<numPrimes;i++)
        printf("%u,\n",primes[i]);

    printf("\n--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
        return 0;
}
