// #include "../DynamicArray/array.h"
#include <stdio.h>

#define SIZE 20

// // Returns an index of the found element
// int search_array(IntArray *array, int value)
// {
//     for (int i = 0; i < array->length; i++)
//     {
//         if (array->data[i] == value)
//             return i;
//     }
//     return -1;
// }

// // Just for testing purposes, so commented out

// int main_n(void)
// {

//     IntArray *array = init_array(10);
//     array->append_int_array(array, 10);
//     array->append_int_array(array, 20);
//     array->append_int_array(array, 35);
//     array->append_int_array(array, 40);
//     array->append_int_array(array, 45);

//     array->display_int_array(array);
//     printf("Found at index: %d\n", search_array(array, 20));
//     free_int_array(array);

//     return 0;
// }

int linear_search(const int *array, const size_t size, const int value)
{
    for (size_t i = 0; i < size; i++)
        if (array[i] == value)
            return i;
}

int main(void)
{
    int array[] = {5, 2, 9, 10, 8, 7, 4, 6, 3, 1};
    int size = sizeof(array) / sizeof(*array);
    printf("Size: %d\n", size);
    int target = 7;
    printf("Found %d at index %d\n", target, linear_search(array, size, target));

    return 0;
}
