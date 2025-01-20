#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *head;
    size_t length;

    void (*add_ll_item)(struct LinkedList *, const int);
    int (*remove_item_ll)(struct LinkedList *, const int);
    int (*contains_ll)(struct LinkedList *, const int);
    int (*get_first_ll)(struct LinkedList *);
    int (*get_last_ll)(struct LinkedList *);
    int (*get_index_ll)(struct LinkedList *, const size_t);
    int (*is_ll_empty)(struct LinkedList *);
    struct LinkedList *(*copy_ll)(const struct LinkedList *);
    void (*clear_ll)(struct LinkedList *);
    void (*display_ll)(struct LinkedList *);
    int (*index_of_ll)(struct LinkedList *, const int);
} LinkedList;

LinkedList *init_ll();
void add_ll_item(LinkedList *, const int);
int remove_item_ll(LinkedList *, const int);
int contains_ll(LinkedList *, const int);
int get_first_ll(LinkedList *);
int get_last_ll(LinkedList *);
int get_index_ll(LinkedList *, const size_t);
int is_ll_empty(LinkedList *);
LinkedList *copy_ll(const LinkedList *);
void clear_ll(LinkedList *);
void display_ll(LinkedList *);
int index_of_ll(LinkedList *, const int);
void free_ll(LinkedList *);

#endif