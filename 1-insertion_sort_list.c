#include "sort.h"


/**
 * insertion_sort_list - insertion sort with a doubly-linked list
 *
 * @list: pointer to the address of some node in the list.
 * Return: don't bother none.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pre_node, *crd_node, *nxt_node;
	int crt_val, nxt_val;
	size_t i;

	if (list == NULL) || (*list == NULL)
		return;
	crt_node = *list;
	while (crt_node->prev != NULL)
		crt_node = crt_node->prev;
	i = 0;
	while (crt_node != NULL)
	{
		nxt_node = crt_node->next;
		/* do the sorting here */
		crt_val = crt_node->n;
		if (nxt_node != NULL)
			nxt_val = crt_node->next->n;
		else
			return;
	}
}



/**
 * swap_dll - a swap procedure for a doubly-linked list
 * actually rearranges the 'connections' of the list.
 *
 * @n1: address of the first node
 * @n2: address of the second node
 * Return: no return value
 */
void swap_dll(listint_t *n1, listint_t *n2)
{
	listint_t *n1_next, *n1_prev, *n2_next, *n2_prev;

	n1_next = n1->next;
	n1_prev = n1->prev;
	n2_next = n2->next;
	n2_prev = n2->prev;

	n1->next = n2_next;
	n1->prev = n2_prev;
	n2->next = n1_next;
	n2->prev = n2_prev;

	return;
}
