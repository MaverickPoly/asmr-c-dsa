#include <stdio.h>
#include <stdlib.h>

long long factorial(int n)
{
    if (n <= 1)
        return n;
    return n * factorial(n - 1);
}

int *generateSeq(size_t size)
{
    int *result = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        result[i] = factorial(i + 1);
    }
    return result;
}

int main(void)
{
    printf("%lld\n", factorial(10));

    size_t size = 10;
    int *result = generateSeq(size);
    printf("Factorial sequence of %d:\n", size);
    for (int i = 0; i < 10; i++)
        printf("%d ", result[i]);
    free(result);
    return 0;
}