#include "array.h"

int main()
{
    IntArray *array = init_array(2);

    printf("Length: %zu, Capacity: %zu\n", array->length, array->capacity);
    append_int_array(array, 5);
    append_int_array(array, 6);
    append_int_array(array, 8);
    append_int_array(array, 10);
    append_int_array(array, 20);
    printf("Length: %zu, Capacity: %zu\n", array->length, array->capacity);

    remove_int_array(array, 6);
    remove_int_array(array, 6);
    display_int_array(array);
    remove_index_int_array(array, 2);
    display_int_array(array);

    printf("Popped: %d\n", pop_int_array(array));
    printf("Popped: %d\n", pop_int_array(array));
    display_int_array(array);

    append_int_array(array, 2);
    append_int_array(array, 4);
    append_int_array(array, 5);
    append_int_array(array, 7);

    printf("Index of element: %d\n", element_index_int_array(array, 4));
    printf("Index of element: %d\n", element_index_int_array(array, 3));
    printf("\nBefore:\n");
    display_int_array(array);

    reverse_int_array(array);
    display_int_array(array);

    sort_int_array(array);
    display_int_array(array);

    clear_int_array(array);
    display_int_array(array);
    free_int_array(array);
}