#include <stdio.h>

int sum(int *array, size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += array[i];
    return sum;
}

int mean(int *array, size_t size)
{
    return sum(array, size) / size;
}

int min(int *array, size_t size)
{
    int min_val = *array;
    for (int i = 0; i < size; ++i)
        if (array[i] < min_val)
            min_val = array[i];
    return min_val;
}

int max(int *array, size_t size)
{
    int max_val = *array;
    for (int i = 0; i < size; ++i)
        if (array[i] > max_val)
            max_val = array[i];
    return max_val;
}
int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const size_t size = sizeof(array) / sizeof(*array);
    printf("Sum: %d\n", sum(array, size));
    printf("Mean: %d\n", mean(array, size));
    printf("Min: %d\n", min(array, size));
    printf("Max: %d\n", max(array, size));
    return 0;
}