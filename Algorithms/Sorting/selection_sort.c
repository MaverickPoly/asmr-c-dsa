#include <stdio.h>

void selection_sort(int *array, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

int main(void)
{
    int array[] = {29, 2, 7, 25, 18, 9, 18, 24};
    size_t size = sizeof(array) / sizeof(*array);

    printf("Original:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    selection_sort(array, size);
    printf("\n\nSorted:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}