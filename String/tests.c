#include "string.h"

int main()
{
    // Initialize
    String *string = init_string("Hello world");
    printf("String: %s, Length: %zu, Capacity: %zu\n", string->data, string->length, string->capacity);

    // Append String
    string->append_string(string, "!!!");
    printf("After append: %s, Length: %zu, Capacity: %zu\n", string->data, string->length, string->capacity);

    // Set string
    string->set_string(string, "String in C");
    printf("After set: %s, Length: %zu, Capacity: %zu\n", string->data, string->length, string->capacity);

    // Substrings
    char *sub1 = string->get_substring(string, 8, 15);
    printf("Substring: %s\n", sub1);
    free(sub1);

    char *sub2 = string->get_substring(string, 3, 8);
    printf("Substring: %s\n", sub2);
    free(sub2);

    // Lowercase / Uppercase
    string->stringToUppercase(string);
    printf("After Uppercase: %s, Length: %zu, Capacity: %zu\n", string->data, string->length, string->capacity);

    string->stringToLowercase(string);
    printf("After Lowercase: %s, Length: %zu, Capacity: %zu\n", string->data, string->length, string->capacity);

    // Find element
    int index = string->findIndexString(string, 'i');
    printf("Found at index: %d\n", index);

    // Starts with
    char startsStr[] = "stri";
    if (string->stringStartsWith(string, startsStr))
    {
        printf("Starts with\n");
    }
    else
    {
        printf("Not starts with\n");
    }

    // EndsWith
    char endStr[] = "in c";
    if (string->stringEndsWith(string, endStr))
    {
        printf("Ends with\n");
    }
    else
    {
        printf("Not ends with\n");
    }

    // Is Digit
    string->set_string(string, "1234");
    if (string->stringIsDigit(string))
    {
        printf("String is digit\n");
    }
    else
    {
        printf("String is not digit\n");
    }

    // Is Alpha
    string->set_string(string, "Helloworld");
    if (string->stringIsAlpha(string))
    {
        printf("String is alpha\n");
    }
    else
    {
        printf("String is not alpha\n");
    }

    // Call it at the end
    free_string(string);
    return 0;
}
