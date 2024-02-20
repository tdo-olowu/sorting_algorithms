#include "sort.h"


/**
 * insertion_sort_list - insertion sort with a doubly-linked list
 *
 * @list: pointer to the address of some node in the list.
 * Return: don't bother none.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pre_node, *crt_node, *nxt_node;
	listint_t *head;
	int crt_val, nxt_val;
	size_t i;

	if (list == NULL) || (*list == NULL)
		return;
	crt_node = *list;
	while (crt_node->prev != NULL)
		crt_node = crt_node->prev;
	head = crt_node;

	i = 0;
	/* while crt isn't tail, there's stuff ahead */
	while (crt_node->next != NULL)
	{
		nxt_node = crt_node->next;
		crt_val = crt_node->n;
		nxt_val = nxt_node->n;
		/* the comparison step */
		if (crt_val > nxt_val)
			insert(&crt_node, &head);
		crt_node = crt_node->next;
	}
}



/**
 * insert - a subroutine to aid insertion_sort
 * essentially finds the place of the node in the head of the list.
 * no need for error-checking here. main should handle that.
 *
 * @head: address of the head of the doubly-linked list
 * @node: the node to place in its proper place.
 * Return: no return value
 */
void insert(listint_t **node, listint_t **head)
{
	listint_t *crt_node, *pre_node;

	crt_node = *head;
	while (crt_node != NULL)
	{
		pre_node = crt_node->prev;
		if (*node->n <= crt_node->n)
		{
			/* rewire then leave */
			*node->prev = crt_node->prev;
			if (pre_node != NULL)
				pre_node->next = *node;
			*node->next = crt_node;
			crt_node->prev = *node;
			return;
		}
		crt_node = crt_node->next;
	}

	return;
}
