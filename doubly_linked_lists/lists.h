#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list structure
 * @n: integer stored in the node
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: structure for doubly linked list nodes
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */
size_t print_dlistint(const dlistint_t *h);

#endif /* LISTS_H */
