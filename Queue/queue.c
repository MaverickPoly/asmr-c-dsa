#include "queue.h"

Queue *init_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    queue->length = 0;
    queue->head = NULL;

    queue->enqueue = enqueue;
    queue->dequeue = dequeue;
    queue->peek = peek;
    queue->back_queue = back_queue;
    queue->is_queue_empty = is_queue_empty;
    queue->queue_contains = queue_contains;
    queue->clear_queue = clear_queue;
    queue->display_queue = display_queue;

    return queue;
}

// Add to end
void enqueue(Queue *queue, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;
    queue->length++;

    if (!queue->head)
    {
        queue->head = new_node;
        return;
    }

    Node *current = queue->head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_node;
}

// Remove first
int dequeue(Queue *queue)
{
    if (!queue->head)
    {
        fprintf(stderr, "Queue is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = queue->head;
    int value = current->data;
    queue->head = queue->head->next;
    free(current);
    queue->length--;
    return value;
}

// Return first
int peek(Queue *queue)
{
    if (!queue->head)
    {
        fprintf(stderr, "Queue is empty!");
        exit(EXIT_FAILURE);
    }
    return queue->head->data;
}

// Return last
int back_queue(Queue *queue)
{
    if (!queue->head)
    {
        fprintf(stderr, "Queue is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = queue->head;
    while (current->next)
        current = current->next;
    return current->data;
}

// Is empty or not
int is_queue_empty(Queue *queue)
{
    return queue->length == 0;
}

// Value in Queue
int queue_contains(Queue *queue, const int value)
{
    if (!queue->head)
    {
        fprintf(stderr, "Queue is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = queue->head;
    while (current)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

// Clear Queue
void clear_queue(Queue *queue)
{
    if (!queue->head)
        return;

    Node *current = queue->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    queue->head = NULL;
    queue->length = 0;
}

// Display queue
void display_queue(Queue *queue)
{
    int displayed = 0;
    Node *current = queue->head;
    while (current)
    {
        displayed = 1;
        printf("%d <- ", current->data);
        current = current->next;
    }
    if (displayed == 1)
        puts("\b\b\b\b");
}

void free_queue(Queue *queue)
{
    Node *current = queue->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}