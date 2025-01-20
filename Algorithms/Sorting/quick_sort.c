#include <stdio.h>
#include <stdlib.h>

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i += 1;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    return i;
}

void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int part = partition(array, low, high);
        quick_sort(array, low, part - 1);
        quick_sort(array, part + 1, high);
    }
}

int main(void)
{
    int array[] = {29, 2, 7, 25, 18, 9, 18, 24};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    quick_sort(array, 0, size - 1);
    printf("\nSorted:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}