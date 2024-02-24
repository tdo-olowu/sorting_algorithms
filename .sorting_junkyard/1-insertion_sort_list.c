#include "sort.h"


/**
 * insertion_sort_list - insertion sort with a doubly-linked list
 *
 * @list: pointer to the address of some node in the list.
 * Return: don't bother none.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crt_node, *nxt_node;
	listint_t *head;

	if ((list == NULL) || (*list == NULL))
		return;
	crt_node = *list;
	while (crt_node->prev != NULL)
		crt_node = crt_node->prev;
	head = crt_node;

	/* while crt isn't tail, there's stuff ahead */
	while (crt_node->next != NULL)
	{
		nxt_node = crt_node->next;
		/* the comparison step */
		if (crt_node->n > nxt_node->n)
		{
			crt_node->next = nxt_node->next;
			if (nxt_node != NULL)
				nxt_node->next->prev = crt_node;
			insert(&nxt_node, &head);
			printf("Inserted successfully\n");
		}
		crt_node = crt_node->next;
	}
	insert(&crt_node, &head);
}


void print_node(listint_t *, char *);

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

	printf("in insert! node has value %d\n", (*node)->n); /* DEBUG */
	crt_node = *head;
	while (crt_node != NULL)
	{
		printf("current node has %d\n", crt_node->n); /* DEBUG */
		pre_node = crt_node->prev;
		if ((*node)->n <= crt_node->n)
		{
			/* rewire then leave */
			print_node((*node), "NODE"); /* DEBUG */
			print_node(crt_node, "CURRENT NODE"); /* DEBUG */
			(*node)->next = crt_node;
			(*node)->prev = crt_node->prev;
			if (pre_node != NULL)
				pre_node->next = *node;
			crt_node->prev = *node;
			break;
		}
		crt_node = crt_node->next;
	}
	/*
	if ((*node)->prev == NULL)
		*head = *node;
		*/

	print_list(*head);
	printf("leaving insert\n");

	return;
}


/* DEBUG */
void print_node(listint_t *node, char *name)
{
	printf("NAME: %s\n", name);
	printf("n: %d\n", node->n);
}
