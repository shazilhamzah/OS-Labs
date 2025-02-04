#include <stdio.h>
#include <stdbool.h>

void sort(int arr[], bool order, int n)
{
    if (order)
    {
        printf("%s\n", "I was here");
        for (int i = 1; i < n; ++i)
        {
            int index = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > index)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = index;
        }
    }
    else
    {
        printf("%s\n", "I was here2");
        for (int i = 1; i < n; ++i)
        {
            int index = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < index)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = index;
        }
    }
}

int findHighest(int array[], int nth)
{
    for (int i = 0; i <= (sizeof(array) / sizeof(*array)); i++)
    {
        for (int j = i + 1; j <= (sizeof(array) / sizeof(*array)); j++)
        {

            if (array[j] > array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array[nth - 1];
}

void print(int array[])
{
    int n = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array[i]);
    }
}




void main()
{
    int arr[5] = {1, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, true, n);
    print(arr);
    int f = findHighest(arr,1);
    printf("%d\n", f);
}

// why it is not calculating right size in sort function