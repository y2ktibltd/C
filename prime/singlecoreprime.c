#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int main(int argc, char *argv[])
{
int num = atoi(argv[1]);
int i,j,square;
clock_t start = clock();
printf("2, ");
for(i=3;i<num;i+=2)
    {
    square=(sqrt(i)+1);
    for(j=2;j<=square;j++)
    if(!(i%j)) break; 
    if(j>square) printf("%d, ", i);
    }
clock_t stop = clock();
printf("\n--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
return 0;
}
