#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 *
 * Description: Prints key/value pairs in the order they appear in the array.
 *              Format: {'key1': 'value1', 'key2': 'value2', ...}
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    int first = 1;
    hash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (!first)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            first = 0;
            node = node->next;
        }
    }

    printf("}\n");
}
