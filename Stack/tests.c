#include "stack.h"

int main()
{
    Stack *stack = init_stack();

    stack->push_stack(stack, 10);
    stack->push_stack(stack, 20);
    stack->push_stack(stack, 30);
    stack->push_stack(stack, 40);
    stack->display_stack(stack);

    if (stack->stack_contains(stack, 30))
        puts("Stack contains 30");
    else
        puts("Stack Does not contain 30");

    printf("Popped: %d\n", stack->pop_stack(stack));
    printf("Popped: %d\n", stack->pop_stack(stack));

    if (stack->stack_contains(stack, 30))
        puts("Stack contains 30");
    else
        puts("Stack Does not contain 30");

    printf("Stack empty: %d\n", stack->is_stack_empty(stack));
    printf("Peeked value: %d\n", stack->peek_stack(stack));

    stack->display_stack(stack);

    stack->clear_stack(stack);
    printf("Stack empty: %d\n", stack->is_stack_empty(stack));

    stack->free_stack(stack);
    return 0;
}