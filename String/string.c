#include "string.h"

String *init_string(const char *initial)
{
    String *string = (String *)malloc(sizeof(String));
    if (!string)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    string->length = initial ? strlen(initial) : 0;
    string->capacity = (string->length + 1) * 2;
    string->data = (char *)malloc(string->capacity * sizeof(char));

    if (!string->data)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        free(string);
        exit(EXIT_FAILURE);
    }

    if (initial)
    {
        strcpy(string->data, initial);
    }
    else
    {
        string->data[0] = '\0';
    }

    string->resize_string = resize_string;
    string->append_string = append_string;
    string->set_string = set_string;
    string->get_substring = get_substring;
    string->stringToUppercase = stringToUppercase;
    string->stringToLowercase = stringToLowercase;
    string->findIndexString = findIndexString;
    string->stringStartsWith = stringStartsWith;
    string->stringEndsWith = stringEndsWith;
    string->stringIsDigit = stringIsDigit;
    string->stringIsAlpha = stringIsAlpha;

    return string;
}

// Resize string, make it bigger/smaller in capacity
void resize_string(String *string, size_t new_capacity)
{
    string->capacity = new_capacity;
    string->data = (char *)realloc(string->data, string->capacity * sizeof(char));
    if (!string->data)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Append at the end of the string
void append_string(String *string, const char *suffix)
{
    size_t suffix_length = strlen(suffix);
    if (string->length + suffix_length + 1 > string->capacity)
    {
        resize_string(string, (string->length + suffix_length + 1) * 2);
    }
    strcat(string->data, suffix);
    string->length += suffix_length;
}

// Set string to smth else
void set_string(String *string, const char *new_value)
{
    size_t new_length = strlen(new_value);
    if (new_length + 1 > string->capacity)
    {
        resize_string(string, (new_length + 1) * 2);
    }
    strcpy(string->data, new_value);
    string->length = new_length;
}

// Get the substring
char *get_substring(String *string, size_t start, size_t end)
{
    if (start >= end || start >= string->length || end >= string->length)
    {
        return NULL;
    }

    size_t sub_length = end - start;
    char *sub = (char *)malloc(sub_length + 1);
    if (!sub)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    strncpy(sub, string->data + start, sub_length);
    sub[sub_length] = '\0';
    return sub;
}

// Free up the memory of 'malloc's
void free_string(String *string)
{
    if (string)
    {
        free(string->data);
        free(string);
    }
}

// Convert String to
void stringToUppercase(String *string)
{
    for (int i = 0; i < string->length; i++)
    {
        string->data[i] = toupper(string->data[i]);
    }
}

// Convert string to lowercase
void stringToLowercase(String *string)
{
    for (int i = 0; i < string->length; i++)
    {
        string->data[i] = tolower(string->data[i]);
    }
}

// Find the index of the character in string
int findIndexString(String *string, const char target)
{
    for (int i = 0; i < string->length; i++)
    {
        if (string->data[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// String starts with smth
int stringStartsWith(String *string, const char *target)
{
    size_t target_length = strlen(target);
    if (target_length > string->length)
    {
        return 0;
    }

    for (size_t i = 0; i < target_length; i++)
    {
        if (string->data[i] != target[i])
        {
            return 0;
        }
    }
    return 1;
}

// String ends with smth
int stringEndsWith(String *string, const char *target)
{
    size_t target_length = strlen(target);
    if (target_length > string->length)
    {
        return 0;
    }
    size_t string_start = string->length - target_length;
    for (size_t i = 0; i < target_length; i++)
    {
        if (string->data[string_start + i] != target[i])
        {
            return 0;
        }
    }
    return 1;
}

// String only consists of digits
int stringIsDigit(String *string)
{
    if (!string || string->data[0] == '\0')
    {
        return 0;
    }

    for (size_t i = 0; i < string->length; i++)
    {
        if (!isdigit(string->data[i]))
        {
            return 0;
        }
    }
    return 1;
}

int stringIsAlpha(String *string)
{
    if (!string || string->data[0] == '\0')
    {
        return 0;
    }

    for (size_t i = 0; i < string->length; i++)
    {
        if (!isalpha(string->data[i]))
        {
            return 0;
        }
    }
    return 1;
}