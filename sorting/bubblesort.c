#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500 //Define max array size to sort through

int* shuffleArray()
{
    int i;
    static int array[MAX];
    for (i=0;i<MAX;i++)
        array[i]=rand()%MAX*1.5;
    return array;
}

int printArray(int array[])
{
    int i;
    for (i=0;i<MAX;i++)
        printf("%d, ",array[i]);
    printf("\n");
    return 0;
}

int sortArray(int array[])
{
    int i,temp,moves=0;
    for (i=0;i<MAX;i++)
    {
        if (array[i]>array[i+1])
        {
            temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
            moves+=1;
        }
        if (moves>0) sortArray(array);
    }
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
    printf("\n DONE SORTING \n");
    printf("\n--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
    printArray(array);
    return 0;
}
