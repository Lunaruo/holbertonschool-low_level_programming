#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_value - updates value of an existing key
 * @node: node to update
 * @value: new value
 *
 * Return: 1 if success, 0 if fail
 */
int update_value(hash_node_t *node, const char *value)
{
	char *dup;

	dup = strdup(value);
	if (dup == NULL)
		return (0);

	free(node->value);
	node->value = dup;

	return (1);
}

/**
 * add_new_node - adds a new node at index
 * @ht: hash table
 * @index: index to insert
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int add_new_node(hash_table_t *ht, unsigned long int index,
		 const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);

	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}

	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (0);
	}

	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key (cannot be empty)
 * @value: value associated with key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (update_value(node, value));
		node = node->next;
	}

	return (add_new_node(ht, index, key, value));
}
