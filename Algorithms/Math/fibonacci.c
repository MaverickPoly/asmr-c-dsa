#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n < 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int *generate_seq(int n)
{
    int *sequence = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        sequence[i] = fibonacci(i + 1);

    return sequence;
}

int main(void)
{
    printf("Fibonacci: %d\n", fibonacci(4));

    size_t size = 8;
    printf("\nFibonacci Numbers:\n");
    int *res = generate_seq(size);
    for (int i = 0; i < size; ++i)
        printf("%d ", res[i]);

    free(res);

    return 0;
}
