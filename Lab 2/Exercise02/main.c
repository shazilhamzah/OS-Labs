#include <stdio.h>
#include <stdbool.h>
#include "Header.h"

int main(int argc, char *argv[])
{
    int arrSize = argc-3;
    int array[arrSize];
    for (int i = 1,x=0; i < argc-2; i++)
    {
        array[x] = atoi(argv[i]);
        x++;
    }

    printf("%s\n", "\nOriginal array: ");
    print(array,arrSize);

    printf("%s\n", "\nSorted array: ");
    sort(array, atoi(argv[argc-2]), arrSize);
    print(array,arrSize);

    int nth = atoi(argv[argc-1]);
    int heighest = findHighest(array,nth,arrSize);
    printf("%s", "\nnth highest: ");
    printf("%d\n",heighest);
}