#ifndef DICT_H
#define DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *key;
    void *value;
} Node;

typedef struct Dict
{
    Node **data;
    size_t length;
    size_t capacity;
} Dict;

Dict *init_dict(const size_t capacity);
void resize_dict(Dict *dict, size_t new_capacity);
void add(Dict *dict, char *key, void *value);
void pop(Dict *dict, const char *key);
void *get(Dict *dict, char *key);
char **keys(Dict *dict);
void **values(Dict *dict);
void clear(Dict *dict);
void display_dict(Dict *dict);

void free_dict(Dict *dict);

#endif