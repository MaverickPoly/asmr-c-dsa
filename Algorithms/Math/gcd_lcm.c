#include <stdio.h>

int gcd(int a, int b)
{
    int temp;
    while (b)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main(void)
{
    int a = 2, b = 3;
    printf("GCD: %d\n", gcd(a, b));
    printf("LCM: %d\n", lcm(a, b));
    return 0;
}
