#include <stdio.h>

int binary_search(const int *array, const size_t size, const int target)
{
    size_t start = 0;
    size_t end = size - 1;
    while (start <= end)
    {
        size_t mid = start + (end - start) / 2;
        if (target == array[mid])
            return mid;
        else if (array[mid] < target)
            start = mid;
        else
            end = mid - 1;
    }
    // 10, 11, 12, 13, 14
    // 0   1   2   3   4
    return -1;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 100};
    size_t size = sizeof(array) / sizeof(*array);
    int target = 1;
    printf("Found value %d at index %d\n", target, binary_search(array, size, target));

    return 0;
}