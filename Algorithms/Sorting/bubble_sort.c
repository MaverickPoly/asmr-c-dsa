#include <stdio.h>

void bubble_sort(int *array, size_t size)
{
    // printf("Calculated: %d\n", sizeof(array) / sizeof(*array)); // <= Won't Work!
    // printf("Actual: %d\n", size);
    int temp;
    for (int i = 0; i < size; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int main(void)
{
    int array[] = {7, 8, 4, 5, 3, 9, 6, 2, 1, 10};
    size_t size = sizeof(array) / sizeof(*array);
    bubble_sort(array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
