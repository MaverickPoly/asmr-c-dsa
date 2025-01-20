#include "linked_list.h"

int main()
{

    LinkedList *ll = init_ll();

    ll->add_ll_item(ll, 5);
    ll->add_ll_item(ll, 8);
    ll->add_ll_item(ll, 9);
    ll->add_ll_item(ll, 10);
    ll->add_ll_item(ll, 13);
    ll->add_ll_item(ll, 16);

    ll->remove_item_ll(ll, 8);
    ll->remove_item_ll(ll, 10);

    if (ll->contains_ll(ll, 11))
    {
        puts("List contains 11");
    }
    else
    {
        puts("List does not contain 11");
    }

    printf("First item: %d\n", ll->get_first_ll(ll));
    printf("Last item: %d\n", ll->get_last_ll(ll));
    printf("Item at index 2: %d\n", ll->get_index_ll(ll, 2));

    if (ll->is_ll_empty(ll))
    {
        puts("Linked list is empty!");
    }
    else
    {
        puts("Linked list is not empty!");
    }
    ll->display_ll(ll);

    ll->clear_ll(ll);
    if (ll->is_ll_empty(ll))
    {
        puts("Linked list is empty!");
    }
    else
    {
        puts("Linked list is not empty!\n\n");
    }

    ll->display_ll(ll);
    puts("\n\n");

    ll->add_ll_item(ll, 4);
    ll->add_ll_item(ll, 9);
    ll->add_ll_item(ll, 16);
    ll->add_ll_item(ll, 25);
    printf("Index of 9: %d\n", ll->index_of_ll(ll, 9));

    LinkedList *new_ll = ll->copy_ll(ll);
    new_ll->display_ll(new_ll);
    free_ll(new_ll);

    free_ll(ll);
}