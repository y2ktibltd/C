#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50 //Define max array size to sort through

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
    printf("FIRST ELEMENTS->\t");
    for (i=0;i<25;i++)
        printf("%d, ",array[i]);
    printf("\n...\n");
    for (i=MAX-25;i<MAX;i++)
        printf("%d, ",array[i]);
    printf("\t<-LAST ELEMENTS");
    printf("\n");
    return 0;
}

int sortArray(int array[])
{
    int i,j=0,k=0;
    int new_MAX=MAX*1.5;
    int count_array[new_MAX];
    for (i=0;i<new_MAX;i++)     //Create count_array of all zeros
        count_array[i]=0;
    for (i=0;i<MAX;i++)     //increment number of occurences of each variable across array
        count_array[array[i]]+=1;
///*
    printf("\ncount_array counts: ");
    for (i=0;i<new_MAX;i++)     //prints number of counts of each integer
        printf("%d, ",count_array[i]);
    printf("\n");

    printf("\n%d new_MAX <-> %d MAX values",new_MAX,MAX);
//*/
///*
    for (i=0;i<=new_MAX;i++)     //Actual sort of data from count_array back into array
        if (count_array[i]>0)
            for (j=0;j<count_array[i];j++)
                {
                array[k]=i;
                k++;
                count_array[i]-=1;
                }
//*/
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
    printf("\n\nDONE SORTING %d ELEMENTS IN %f seconds \n\n",MAX,(double)(start-stop)/CLOCKS_PER_SEC);
    printArray(array);
    return 0;
}
