#include <stdbool.h>

void sort(int array[], bool order, int n)
{
    if (order)
    {
        for (int i = 1; i < n; ++i)
        {
            int index = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > index)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = index;
        }
    }
    else
    {
        for (int i = 1; i < n; ++i)
        {
            int index = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] < index)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = index;
        }
    }
}

int findHighest(int array[], int nth, int size)
{
    for (int i = 0; i <= size; i++)
    {
        for (int j = i + 1; j <= size; j++)
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

void print(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}