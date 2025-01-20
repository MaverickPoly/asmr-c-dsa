#include "hash_map.h"

#define SIZE 10

int main(void)
{
    HashMap *map = init_hashmap(8);

    put_hashmap(map, "Job", "Programming");
    put_hashmap(map, "Age", "∞");
    put_hashmap(map, "City", "Moscow");
    put_hashmap(map, "Clever", "False");

    display_hashmap(map);

    hashmap_remove(map, "Job");
    printf("\nContains 'Job': %d\n", hashmap_contains(map, "Job"));
    printf("Contains 'City': %d\n", hashmap_contains(map, "City"));

    display_hashmap(map);
    free_hashmap(map);

    return 0;
}
