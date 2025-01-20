#include "set.h"

int main()
{
    Set *set = init_set(10);
    set->add_set(set, 10);
    set->add_set(set, 12);
    set->add_set(set, 13);
    set->remove_set(set, 13);
    printf("Size: %d, Capacity: %d\n", set->length, set->capacity);
    set->add_set(set, 13);
    set->add_set(set, 14);
    set->add_set(set, 15);
    set->remove_at_index(set, 2);
    // set->remove_at_index(set, 2);

    set->display_set(set);

    if (set->set_contains(set, 15))
        puts("Set contains 15");
    else
        puts("Set does not contain 15");

    printf("Value at index 2: %d\n", set->set_index(set, 2));
    printf("Value at index 3: %d\n", set->set_index(set, 3));

    set->display_set(set);

    set->clear_set(set);
    set->display_set(set);
    free_set(set);

    // --------- Set major operations --------------

    Set *set1 = init_set(6);
    Set *set2 = init_set(6);

    add_set(set1, 1);
    add_set(set1, 2);
    add_set(set1, 3);
    add_set(set1, 4);

    add_set(set2, 3);
    add_set(set2, 4);
    add_set(set2, 5);
    add_set(set2, 6);

    printf("Set 1: ");
    set1->display_set(set1);

    printf("Set 2: ");
    set2->display_set(set2);

    Set *difference = set1->set_difference(set1, set2);
    printf("Set Difference (Set1 - Set2): ");
    difference->display_set(difference);

    Set *intersection = set1->set_intersection(set1, set2);
    printf("Set Intersection: ");
    intersection->display_set(intersection);

    set1->remove_set(set1, 1);
    set1->remove_set(set1, 2);
    if (set1->set_is_subset(set1, set2))
    {
        puts("Set 1 is subset of Set 2");
    }
    else
    {
        puts("Set 1 is NOT subset of Set 2");
    }

    free_set(set1);
    free_set(set2);
    free_set(difference);
    free_set(intersection);
    return 0;
}
