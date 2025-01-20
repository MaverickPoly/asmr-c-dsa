#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct HashMap
{
    size_t capacity; // Total number of buckets
    size_t size;     // Number of values filled
    Node **buckets;  // [[Node, Node], [Node, Node]]
} HashMap;

HashMap *init_hashmap(const size_t);
void put_hashmap(HashMap *map, const char *key, void *value);
int hashmap_contains(HashMap *map, const char *key);
void hashmap_remove(HashMap *map, const char *key);
unsigned int hash_key(const char *key, size_t capacity);

void display_hashmap(HashMap *map);

void free_hashmap(HashMap *);

#endif