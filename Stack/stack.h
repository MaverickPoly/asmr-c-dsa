#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *top;
    size_t size;

    void (*push_stack)(struct Stack *, const int);
    int (*pop_stack)(struct Stack *);
    int (*stack_contains)(struct Stack *, const int);
    int (*peek_stack)(struct Stack *);
    void (*clear_stack)(struct Stack *);
    int (*is_stack_empty)(struct Stack *);
    void (*display_stack)(struct Stack *);
    void (*free_stack)(struct Stack *);
} Stack;

Stack *init_stack();
void push_stack(Stack *, const int);
int pop_stack(Stack *);
int stack_contains(Stack *, const int);
int peek_stack(Stack *);
void clear_stack(Stack *);
int is_stack_empty(Stack *);
void display_stack(Stack *);
void free_stack(Stack *);

#endif