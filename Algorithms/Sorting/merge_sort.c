#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *left_array = (int *)malloc(n1 * sizeof(int));
    int *right_array = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        left_array[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_array[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }

    free(left_array);
    free(right_array);
}

void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int main(void)
{
    int array[] = {29, 2, 7, 25, 18, 9, 18, 24};
    size_t size = sizeof(array) / sizeof(int);

    printf("Original Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    merge_sort(array, 0, size - 1);

    printf("Merge Sort:\n");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    return 0;
}