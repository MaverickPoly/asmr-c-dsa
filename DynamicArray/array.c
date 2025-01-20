#include "array.h"

IntArray *init_array(const size_t initial_capacity)
{
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    if (!array)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    array->length = 0;
    array->capacity = initial_capacity;
    array->data = (int *)malloc(array->capacity * sizeof(int));

    if (!array->data)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return array;
}

// Resize Array
void resize_int_array(IntArray *array, size_t new_capacity)
{
    array->capacity = new_capacity;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    if (!array->data)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

// Add Element to array
void append_int_array(IntArray *array, const int value)
{
    if (array->length == array->capacity)
    {
        resize_int_array(array, array->capacity * 2);
    }
    array->data[array->length] = value;
    array->length++;
}

// Remove index of array
void remove_index_int_array(IntArray *array, int index)
{
    if (index < 0 || index >= array->length)
    {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    for (int i = index; i < array->length - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->length--;
    if (array->length < (int)array->capacity / 2)
    {
        resize_int_array(array, array->capacity / 2);
    }
}

// Remove element from array
int remove_int_array(IntArray *array, const int value)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->data[i] == value)
        {
            remove_index_int_array(array, i);
            return 1;
        }
    }
    return 0;
}

// Pop element from the end
int pop_int_array(IntArray *array)
{
    if (array->length <= 0)
    {
        return (int)NULL;
    }

    array->length--;
    return array->data[array->length];
}

// Index of element
int element_index_int_array(IntArray *array, const int value)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// Insert at position
// TODO

// Clear array
void clear_int_array(IntArray *array)
{
    array->length = 0;
    resize_int_array(array, 10);
}

// Display array
void display_int_array(IntArray *array)
{
    printf("[");
    int displayed = 0;
    for (int i = 0; i < array->length; i++)
    {
        displayed = 1;

        printf("%d, ", array->data[i]);
    }
    if (displayed)
    {
        printf("\b\b");
    }
    printf("]\n");
}

// Sort array -> Simple bubble sort
void sort_int_array(IntArray *array)
{
    int temp;
    for (int i = 0; i < array->length - 1; i++)
    {
        for (int j = 0; j < array->length - i - 1; j++)
        {
            if (array->data[j] > array->data[j + 1])
            {
                temp = array->data[j];
                array->data[j] = array->data[j + 1];
                array->data[j + 1] = temp;
            }
        }
    }
}

// Reverse
void reverse_int_array(IntArray *array)
{
    int start = 0;
    int end = array->length - 1;
    int temp;
    while (end > start)
    {
        temp = array->data[start];
        array->data[start] = array->data[end];
        array->data[end] = temp;
        start++;
        end--;
    }
}

// Free array
void free_int_array(IntArray *int_array)
{
    if (init_array)
    {
        free(int_array->data);
        free(int_array);
    }
}
