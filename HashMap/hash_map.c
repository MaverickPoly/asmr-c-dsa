#include "hash_map.h"

// Init
HashMap *init_hashmap(const size_t capacity)
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->capacity = capacity;
    map->size = 0;
    map->buckets = (Node **)calloc(capacity, sizeof(Node *));
    return map;
}

Node *create_node(const char *key, void *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

void put_hashmap(HashMap *map, const char *key, void *value)
{
    unsigned int index = hash_key(key, map->capacity);
    Node *current = map->buckets[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    Node *new_node = create_node(key, value);
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
    map->size++;
}

unsigned int hash_key(const char *key, size_t capacity)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash + *key++) % capacity;
    }
    return hash;
}

int hashmap_contains(HashMap *map, const char *key)
{
    unsigned int index = hash_key(key, map->capacity);
    Node *current = map->buckets[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void hashmap_remove(HashMap *map, const char *key)
{
    unsigned int index = hash_key(key, map->capacity);
    Node *current = map->buckets[index];
    Node *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                map->buckets[index] = current->next;
            }
            free(current->key);
            free(current);
            map->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    fprintf(stderr, "Key not found: %s\n", key);
}

void display_hashmap(HashMap *map)
{
    for (size_t i = 0; i < map->capacity; i++)
    {
        Node *current = map->buckets[i];
        if (current)
        {
            printf("Bucket %zu: ", i);
            while (current)
            {
                printf("(%s: %s) ", current->key, (char *)current->value);
                current = current->next;
            }
            printf("\n");
        }
    }
}

void free_hashmap(HashMap *map)
{
    for (size_t i = 0; i < map->capacity; i++)
    {
        Node *current = map->buckets[i];
        while (current)
        {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}