#include <stdio.h>

typedef enum
{
    false = 0,

    true = 1,
} Bool;

Bool int_to_bool(int value)
{
    return value != 0 ? true : false;
}

Bool float_to_bool(float value)
{
    return value != 0.0f ? true : false;
}

Bool ptr_to_bool(void *ptr)
{
    return ptr != NULL ? true : false;
}

Bool str_to_bool(const char *str)
{
    return (str != NULL && str[0] != '\0' ? true : false);
}

void print_bool(Bool value)
{
    printf(value ? "true\n" : "false\n");
}

int main(void)
{
    Bool isClever = false;
    Bool isProgrammer = true;

    printf("isClever: %d\n", isClever);
    printf("isProgrammer: %d\n", isProgrammer);

    int int_val1 = 10, int_val2 = 0;
    printf("----- Integer to Bool -----\n");
    print_bool(int_to_bool(int_val1));
    print_bool(int_to_bool(int_val2));

    float float_val1 = 3.14f, float_val2 = 0.0f;
    printf("----- Float to Bool -----\n");
    print_bool(float_to_bool(float_val1));
    print_bool(float_to_bool(float_val2));

    int some_val = 2029;
    int *ptr1 = &some_val, *ptr2 = NULL;
    printf("----- Pointer to Bool -----\n");
    print_bool(ptr_to_bool(ptr1));
    print_bool(ptr_to_bool(ptr2));

    const char *str1 = "Hello World!", *str2 = "";
    printf("----- String to Bool -----\n");
    print_bool(str_to_bool(str1));
    print_bool(str_to_bool(str2));

    return 0;
}