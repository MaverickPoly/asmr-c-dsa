#include "dict.h"

int main(void)
{
    Dict *dict = init_dict(10);
    add(dict, "Job", "Programmer");
    add(dict, "Age", "30");
    add(dict, "Country", "Russia");
    add(dict, "Language", "Persian");
    add(dict, "Hobby", "Chess");

    pop(dict, "Country");
    pop(dict, "Hobby");
    printf("Value: %s\n", get(dict, "Age"));
    printf("Value: %s\n", get(dict, "Hobby"));

    display_dict(dict);

    puts("Keys:");
    char **keys_res = keys(dict);
    for (int i = 0; i < dict->length; i++)
    {
        printf("%s, ", keys_res[i]);
        free(keys_res[i]);
    }
    free(keys_res);

    puts("\n\nValues:");
    void **val_res = values(dict);
    for (int i = 0; i < dict->length; i++)
    {
        printf("%s ", val_res[i]);
        free(val_res[i]);
    }
    free(val_res);

    puts("\nClearing:");
    display_dict(dict);
    clear(dict);
    display_dict(dict);

    free_dict(dict);

    return 0;
}
