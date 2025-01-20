#include "queue.h"

int main()
{
    Queue *queue = init_queue();

    if (queue->is_queue_empty(queue))
        puts("Queue is empty");
    else
        puts("Queue is Not empty");

    queue->enqueue(queue, 10);
    queue->enqueue(queue, 20);
    queue->enqueue(queue, 30);
    queue->enqueue(queue, 40);

    queue->display_queue(queue);
    printf("Dequed: %d\n", queue->dequeue(queue));
    printf("Dequed: %d\n", queue->dequeue(queue));
    printf("Peek: %d\n", queue->peek(queue));
    printf("Peek: %d\n", queue->peek(queue));
    printf("Back: %d\n", queue->back_queue(queue));
    queue->enqueue(queue, 50);
    printf("Back: %d\n", queue->back_queue(queue));

    if (queue->is_queue_empty(queue))
        puts("\nQueue is empty");
    else
        puts("Queue is Not empty");

    if (queue->queue_contains(queue, 60))
        puts("Queue contains 60");
    else
        puts("Queue does not contain 60");

    queue->display_queue(queue);

    queue->clear_queue(queue);
    queue->enqueue(queue, 29);
    queue->display_queue(queue);

    free_queue(queue);
    return 0;
}
