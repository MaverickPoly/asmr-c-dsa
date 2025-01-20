#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6;
    }
    return 1;
}

int *generatePrime(int n)
{
    int *array = (int *)malloc(n * sizeof(int));
    int size = 0;
    int i = 0;
    while (size != n)
    {
        if (is_prime(i))
        {
            array[size] = i;
            size++;
        }
        i++;
    }

    return array;
}

int main(void)
{
    printf("IsPrime: %d\n", is_prime(5));
    printf("IsPrime: %d\n", is_prime(6));

    size_t size = 10;
    printf("\n\nPrime Numbers:\n");
    int *prime_numbers = generatePrime(size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", prime_numbers[i]);
    }
    free(prime_numbers);

    return 0;
}