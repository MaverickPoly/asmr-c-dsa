#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct IntArray
{
    int *data;
    size_t length;
    size_t capacity;

    void (*resize_int_array)(struct IntArray *, size_t);
    void (*append_int_array)(struct IntArray *, const int);
    void (*remove_index_int_array)(struct IntArray *, int);
    int (*remove_int_array)(struct IntArray *, const int);
    int (*pop_int_array)(struct IntArray *);
    int (*element_index_int_array)(struct IntArray *, const int);
    void (*clear_int_array)(struct IntArray *);
    void (*display_int_array)(struct IntArray *);
    void (*reverse_int_array)(struct IntArray *);
    void (*sort_int_array)(struct IntArray *);
} IntArray;

IntArray *init_array(const size_t);
void resize_int_array(struct IntArray *, size_t);
void append_int_array(struct IntArray *, const int);
void remove_index_int_array(struct IntArray *, int);
int remove_int_array(struct IntArray *, const int);
int pop_int_array(struct IntArray *);
int element_index_int_array(struct IntArray *, const int);
void clear_int_array(struct IntArray *);
void display_int_array(IntArray *int_array);
void free_int_array(IntArray *int_array);
void reverse_int_array(IntArray *);
void sort_int_array(IntArray *);

#endif
