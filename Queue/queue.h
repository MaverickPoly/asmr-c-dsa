#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *head; // First in the queue
    size_t length;
    void (*enqueue)(struct Queue *, int);
    int (*dequeue)(struct Queue *);
    int (*peek)(struct Queue *);
    int (*back_queue)(struct Queue *);
    int (*is_queue_empty)(struct Queue *);
    int (*queue_contains)(struct Queue *, const int);
    void (*clear_queue)(struct Queue *);
    void (*display_queue)(struct Queue *);
} Queue;

Queue *init_queue();
void enqueue(Queue *, int);
int dequeue(Queue *);
int peek(Queue *);
int back_queue(Queue *);
int is_queue_empty(Queue *);
int queue_contains(Queue *, const int);
void clear_queue(Queue *);
void display_queue(Queue *);
void free_queue(Queue *);

#endif