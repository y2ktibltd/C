#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]){
    int num = atoi(argv[1]);
    int i,j;
    float square;
    clock_t start = clock();
    for (i=2;i<num;++i) 
    {
        square=sqrt(i);
        for (j=2;j<square;++j) 
            {
            if (i%j==0) 
                {
                break; 
                }
        else 
            {
            printf("%d is a prime \n",i); 
            }
        }
    }
    clock_t stop = clock();
    printf("--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
}
