#include "linked_list.h"

LinkedList *init_ll()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list)
    {
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    list->length = 0;
    list->head = NULL;

    list->add_ll_item = add_ll_item;
    list->remove_item_ll = remove_item_ll;
    list->contains_ll = contains_ll;
    list->get_first_ll = get_first_ll;
    list->get_last_ll = get_last_ll;
    list->get_index_ll = get_index_ll;
    list->is_ll_empty = is_ll_empty;
    list->copy_ll = copy_ll;
    list->clear_ll = clear_ll;
    list->display_ll = display_ll;
    list->index_of_ll = index_of_ll;

    return list;
}

// Add item to LL
void add_ll_item(LinkedList *list, const int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
}

// Remove item from list
int remove_item_ll(LinkedList *list, const int value)
{
    if (!list->head)
    {
        return -1;
    }

    Node *current = list->head;
    Node *prev = NULL;
    // 2 -> 3 -> 5 -> 7
    while (current)
    {
        if (current->data == value)
        {
            if (prev)
                prev->next = current->next;
            else
                list->head = current->next;

            free(current);
            list->length--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}

// Contains element?
int contains_ll(LinkedList *list, const int value)
{
    if (!list->head)
        return 0;

    Node *current = list->head;
    while (current)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

// Get First
int get_first_ll(LinkedList *list)
{
    return list->head->data;
}

// Get Last
int get_last_ll(LinkedList *list)
{
    if (!list->head)
        return (int)NULL;

    Node *current = list->head;
    while (current->next)
    {
        current = current->next;
    }
    return current->data;
}

// Get at index
int get_index_ll(LinkedList *list, const size_t index)
{
    if (index > list->length - 1 || index < 0)
    {
        fprintf(stderr, "Index out of bounds!");
        return (int)NULL;
    }

    if (!list->head)
    {
        return (int)NULL;
    }

    Node *current = list->head;
    int i = 0;
    while (current->next)
    {
        if (i == index)
        {
            return current->data;
        }
        current = current->next;
        i++;
    }
}

// is Empty?
int is_ll_empty(LinkedList *list)
{
    return list->length == 0;
}

// Copy
LinkedList *copy_ll(const LinkedList *original)
{
    if (!original)
    {
        return NULL;
    }

    LinkedList *new_list = init_ll();
    Node *current = original->head;
    Node *tail = NULL;

    while (current)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (!new_node)
        {
            fprintf(stderr, "Memory allocation failed");
            free_ll(new_list);
            exit(EXIT_FAILURE);
        }
        new_node->data = current->data;
        new_node->next = NULL;

        if (!new_list->head)
        {
            new_list->head = new_node;
        }
        else
        {
            tail->next = new_node;
        }
        tail = new_node;
        current = current->next;
        new_list->length++;
    }
    return new_list;
}

// Clear
void clear_ll(LinkedList *list)
{
    if (!list)
        return;

    Node *current = list->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->length = 0;
}

// Display LL
void display_ll(LinkedList *list)
{
    Node *current = list->head;
    while (current)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Index of element
int index_of_ll(LinkedList *list, const int value)
{
    if (!list->head)
        return -1;

    Node *current = list->head;
    int i = 0;
    while (current)
    {
        if (current->data == value)
            return i;
        current = current->next;
        i++;
    }

    return -1;
}

// Free Linked List
void free_ll(LinkedList *list)
{
    Node *current = list->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}