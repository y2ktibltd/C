#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 125000 //Define max array size to sort through

int* shuffleArray()
{
    int i;
    static unsigned int array[MAX];
    for (i=0;i<MAX;i++)
        array[i]=rand()%MAX*1.5;
    return array;
}

int printArray(int array[])
{
    int i;
    for (i=0;i<10;i++)
        printf("%d, ",array[i]);
    printf(" ... ");
    for (i=MAX-10;i<MAX;i++)
        printf("%d, ",array[i]);
    return 0;
}

int sortArray(int array[])
{
    int i,j,temp,moves=0;
    int new_max=MAX-1;
    unsigned long tot_moves=0;
    for (i=0;i<new_max;i++)
    {
        for (j=0;j<MAX;j++)
            if (array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                moves+=1;
                tot_moves+=1;
            }
            new_max-=1;
        if (moves>0) continue; //sortArray(array);
    }
    printf("\n\ntotal moves=%ld",tot_moves);
    return 0;
}

int main()
{
    int *array;
    array=shuffleArray();
    printArray(array);
    clock_t start=clock();
    sortArray(array);
    clock_t stop=clock();
    printf("\n\n DONE SORTING %d ELEMENTS IN\t %f seconds \n\n",MAX,(double)(start-stop)/CLOCKS_PER_SEC);
    printArray(array);
    return 0;
}
