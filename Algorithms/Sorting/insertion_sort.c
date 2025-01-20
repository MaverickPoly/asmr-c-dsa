#include <stdio.h>

void insertion_sort(int *array, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int value = array[i];
        int j = i - 1;

        while (j >= 0 && value < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = value;
    }
}

int main()
{
    int array[] = {29, 24, 25, 18, 9, 18, 7};
    size_t size = sizeof(array) / sizeof(*array);
    insertion_sort(array, size);

    printf("Sorted:\n");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    return 0;
}