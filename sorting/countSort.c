#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1500000 //Define max array size to sort through
#define RNS 1750000 //Random number size (0 to largest)

int* shuffleArray()
{
    int i;
    static unsigned int array[MAX];
    for (i=0;i<MAX;i++)
        array[i]=rand()%RNS;
    return array;
}

int printArray(int array[])
{
    int i;
    printf("FIRST ELEMENTS->\t");
    for (i=0;i<25;i++)
        printf("%d, ",array[i]);
    printf("\n...\n");
    for (i=MAX-10;i<MAX;i++)
        printf("%d, ",array[i]);
    printf("\t<-LAST ELEMENTS");
    printf("\n");
    return 0;
}

int sortArray(int array[])
{
    int i,k=0;
    int count_array[RNS];
    for (i=0;i<RNS;i++)     //Create count_array of all zeros
        count_array[i]=0;
    for (i=0;i<MAX;i++)     //increment number of occurences of each variable across array
        count_array[array[i]]+=1;
    for (i=0;i<=RNS;i++)     //Actual sort of data from count_array back into array
        while (count_array[i]>0)
        {
            array[k]=i;
            k++;
            count_array[i]-=1;
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
    printf("\nDONE SORTING %d ELEMENTS IN %f seconds \n\n",MAX,(double)(start-stop)/CLOCKS_PER_SEC);
    printArray(array);
    return 0;
}
