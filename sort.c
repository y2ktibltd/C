#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 200 //Define max array size to sort through

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

int sortArray(int array[],int* tot_moves)
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
            tot_moves+=1;
//            printf("%d total moves inside loop\n",tot_moves);
        }
        if (moves>0)
        {
            sortArray(array,&tot_moves);
        }
    }
//    printf("%d total moves outside loop\n",tot_moves);
    return 0;
}

int main()
{
    int *array;
    int tot_moves=0;
    array=shuffleArray();
    printArray(array);
    clock_t start=clock();
    sortArray(array,&tot_moves);
    clock_t stop=clock();
    printf("\n DONE SORTING \n");
    printf("\n--- %f seconds ___\n", (double)(start-stop)/CLOCKS_PER_SEC);
    printf("%d total moves\n\n",tot_moves);
    printArray(array);
    return 0;
}
