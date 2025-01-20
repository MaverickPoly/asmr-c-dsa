#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct String
{
    char *data;
    size_t length;
    size_t capacity;

    void (*resize_string)(struct String *string, size_t new_capacity);
    void (*append_string)(struct String *string, const char *suffix);
    void (*set_string)(struct String *string, const char *new_value);
    char *(*get_substring)(struct String *string, size_t start, size_t end);
    void (*stringToUppercase)(struct String *string);
    void (*stringToLowercase)(struct String *string);
    int (*findIndexString)(struct String *string, const char target);
    int (*stringStartsWith)(struct String *string, const char *target);
    int (*stringEndsWith)(struct String *string, const char *target);
    int (*stringIsDigit)(struct String *string);
    int (*stringIsAlpha)(struct String *string);
} String;

String *init_string(const char *initial);
void resize_string(struct String *string, size_t new_capacity);
void append_string(struct String *string, const char *suffix);
void set_string(struct String *string, const char *new_value);
char *get_substring(struct String *string, size_t start, size_t end);
void stringToUppercase(struct String *string);
void stringToLowercase(struct String *string);
int findIndexString(struct String *string, const char target);
int stringStartsWith(struct String *string, const char *target);
int stringEndsWith(struct String *string, const char *target);
int stringIsDigit(struct String *string);
int stringIsAlpha(struct String *string);
void free_string(String *string);

#endif