#include "set.h"

Set *init_set(const size_t inital_capacity)
{
    Set *set = (Set *)malloc(sizeof(Set));
    if (!set)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    set->length = 0;
    set->capacity = inital_capacity;
    set->data = (int *)malloc(set->capacity * sizeof(int));

    if (!set->data)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    set->add_set = add_set;
    set->pop_set = pop_set;
    set->remove_at_index = remove_at_index;
    set->remove_set = remove_set;
    set->set_contains = set_contains;
    set->set_index = set_index;
    set->clear_set = clear_set;
    set->display_set = display_set;
    set->set_difference = set_difference;
    set->set_intersection = set_intersection;
    set->set_is_subset = set_is_subset;

    return set;
}

// Resize Set
void resize_set(Set *set, size_t new_capacity)
{
    set->capacity = new_capacity;
    set->data = (int *)realloc(set->data, set->capacity * sizeof(int));
    if (!set->data)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

// Add value to set
void add_set(Set *set, const int value)
{
    if (set->length == set->capacity)
        resize_set(set, set->capacity * 2);
    if (!set_contains(set, value))
    {
        set->data[set->length] = value;
        set->length++;
    }
    else
    {
        fprintf(stderr, "Value already exists in set!");
        exit(EXIT_FAILURE);
    }
}

// Pop value from set
void pop_set(Set *set)
{
    if (set->length == 0)
    {
        fprintf(stderr, "Set is empty!");
        exit(EXIT_FAILURE);
    }
    // set->data[set->length - 1] = NULL;
    set->length--;
}

// Remove element at specific index
void remove_at_index(Set *set, int index)
{
    if (index < 0 || index >= set->length)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < set->length - 1; i++)
        set->data[i] = set->data[i + 1];

    set->length--;
    if (set->length < (int)(set->capacity / 2))
        resize_set(set, set->capacity / 2);
}

// Remove value from set
int remove_set(Set *set, const int value)
{
    for (int i = 0; i < set->length; i++)
    {
        if (set->data[i] == value)
        {
            remove_at_index(set, i);
            return 1;
        }
    }

    return 0; // 0 - unsuccessful, 1 - successful
}

// Set contains item
int set_contains(Set *set, const int value)
{
    for (int i = 0; i < set->length; i++)
    {
        if (set->data[i] == value)
            return 1; // Contains
    }
    return 0; // Not contains
}

// Item at index
int set_index(Set *set, const size_t index)
{
    if (index < 0 || index > set->length - 1)
    {
        fprintf(stderr, "Index out of bounds!");
        exit(EXIT_FAILURE);
    }
    return set->data[index];
}

// Clear Set
void clear_set(Set *set)
{
    set->length = 0;
    resize_set(set, 10);
}

// Display set
void display_set(Set *set)
{
    printf("{");
    int displayed = 0;
    for (int i = 0; i < set->length; i++)
    {
        displayed = 1;
        printf("%d, ", set->data[i]);
    }
    if (displayed)
        printf("\b\b");
    printf("}\n");
}

// Set difference, with another set -> Set
Set *set_difference(Set *set1, Set *set2)
{
    Set *result = init_set(set1->length + 1);

    for (size_t i = 0; i < set1->length; i++)
    {
        if (!set2->set_contains(set2, set1->data[i]))
            result->add_set(result, set1->data[i]);
    }
    return result;
}

// Set intersection, with another set -> Set
Set *set_intersection(Set *set1, Set *set2)
{
    Set *result = init_set(set1->length < set2->length ? set1->length : set2->length);

    for (size_t i = 0; i < set1->length; i++)
    {
        if (set2->set_contains(set2, set1->data[i]))
            result->add_set(result, set1->data[i]);
    }
    return result;
}

// Set is subset of another set
int set_is_subset(Set *subset, Set *set)
{
    for (int i = 0; i < subset->length; i++)
    {
        if (!set->set_contains(set, subset->data[i]))
            return 0;
    }
    return 1;
}

// Free Set
void free_set(Set *set)
{
    if (set)
    {
        free(set->data);
        free(set);
    }
}
