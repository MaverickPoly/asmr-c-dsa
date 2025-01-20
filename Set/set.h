#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Set
{
    int *data;
    size_t length;
    size_t capacity;

    void (*add_set)(struct Set *, const int);
    void (*pop_set)(struct Set *);
    void (*remove_at_index)(struct Set *, int);
    int (*remove_set)(struct Set *, const int);
    int (*set_contains)(struct Set *, const int);
    int (*set_index)(struct Set *, const size_t);
    void (*clear_set)(struct Set *);
    void (*display_set)(struct Set *);
    struct Set *(*set_difference)(struct Set *, struct Set *);
    struct Set *(*set_intersection)(struct Set *, struct Set *);
    int (*set_is_subset)(struct Set *, struct Set *);
} Set;

Set *init_set(const size_t);
void add_set(Set *, const int);
void pop_set(Set *);
void remove_at_index(Set *, int);
int remove_set(Set *, const int);
int set_contains(Set *, const int);
int set_index(Set *, const size_t);
void clear_set(Set *);
void display_set(Set *);
Set *set_difference(Set *, Set *);
Set *set_intersection(Set *, Set *);
int set_is_subset(Set *, Set *);
void free_set(Set *set);

#endif