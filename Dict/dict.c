#include "dict.h"

Dict *init_dict(const size_t capacity)
{
    Dict *dict = (Dict *)malloc(sizeof(Dict));
    if (!dict)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    dict->length = 0;
    dict->capacity = capacity;
    dict->data = (Node **)malloc(dict->capacity * sizeof(Node *));

    if (!dict->data)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return dict;
}

void resize_dict(Dict *dict, size_t new_capacity)
{
    dict->capacity = new_capacity;
    dict->data = (Node **)realloc(dict->data, dict->capacity * sizeof(Node *));
    if (!dict->data)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void add(Dict *dict, char *key, void *value)
{
    if (dict->length == dict->capacity)
        resize_dict(dict, dict->capacity * 2);

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = (void *)value;
    dict->data[dict->length] = new_node;
    dict->length++;
}

void pop(Dict *dict, const char *key)
{
    for (int i = 0; i < dict->length; i++)
    {
        if (strcmp(dict->data[i]->key, key) == 0)
        {
            for (int j = i; j < dict->length - 1; j++)
                dict->data[j] = dict->data[j + 1];
            dict->length--;
            return;
        }
    }
}

void *get(Dict *dict, char *key)
{
    for (int i = 0; i < dict->length; i++)
    {
        if (strcmp(dict->data[i]->key, key) == 0)
            return dict->data[i]->value;
    }
    return NULL;
}

char **keys(Dict *dict)
{
    char **res = (char **)malloc(dict->length * sizeof(char *));
    if (!res)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < dict->length; i++)
        res[i] = dict->data[i]->key;

    return res;
}

void **values(Dict *dict)
{
    void **res = (void **)malloc(dict->length * sizeof(void *));
    if (!res)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < dict->length; i++)
        res[i] = dict->data[i]->value;
    return res;
}

void clear(Dict *dict)
{
    for (int i = 0; i < dict->length; i++)
        free(dict->data[i]);

    dict->length = 0;
    resize_dict(dict, 10);
}

void display_dict(Dict *dict)
{
    int displayed = 0;
    printf("{");
    for (int i = 0; i < dict->length; i++)
    {
        printf("\"%s\": %s, ", dict->data[i]->key, dict->data[i]->value);
        displayed = 1;
    }
    if (displayed)
        printf("\b\b");
    printf("}\n");
}

void free_dict(Dict *dict)
{
    if (dict)
    {
        for (int i = 0; i < dict->length; i++)
        {
            free(dict->data[i]);
        }
        free(dict->data);
        free(dict);
    }
}