#include "stack.h"

Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    stack->size = 0;

    stack->push_stack = push_stack;
    stack->pop_stack = pop_stack;
    stack->stack_contains = stack_contains;
    stack->peek_stack = peek_stack;
    stack->clear_stack = clear_stack;
    stack->is_stack_empty = is_stack_empty;
    stack->display_stack = display_stack;
    stack->free_stack = free_stack;

    return stack;
}

// Add Item
void push_stack(Stack *stack, const int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++; // (*stack).size++;
}

// Remove Top Item
int pop_stack(Stack *stack)
{
    if (!stack->top)
    {
        fprintf(stderr, "Stack is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = stack->top;
    stack->top = current->next;
    int value = current->data;
    free(current);
    return value;
}

// Contains
int stack_contains(Stack *stack, const int value)
{
    if (!stack->top)
    {
        fprintf(stderr, "Stack is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = stack->top;
    while (current)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

// Top value
int peek_stack(Stack *stack)
{
    return stack->top->data;
}

// Clear Stack
void clear_stack(Stack *stack)
{
    if (!stack->top)
    {
        fprintf(stderr, "Stack is empty!");
        exit(EXIT_FAILURE);
    }

    Node *current = stack->top;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    stack->top = NULL;
    stack->size = 0;
}

// Is Stack Empty
int is_stack_empty(Stack *stack)
{
    return stack->size == 0;
}

// Display Full Stack
void display_stack(Stack *stack)
{
    Node *current = stack->top;
    while (current)
    {
        printf("---- %d ----\n", current->data);
        current = current->next;
    }
}

void free_stack(Stack *stack)
{
    Node *current = stack->top;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}