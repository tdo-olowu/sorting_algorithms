#include "sort.h"
/* remember - insertion sort always inserts *behind* current ptr */


/**
 * insertion_sort_list - insertion sort with a doubly-linked list
 * this version generates a temporary new list
 *
 * @list: pointer to the address of some node in the list.
 * Return: don't bother none.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crt_node, *sorted_list, *head;

	if ((list == NULL) || (*list == NULL))
		return;
	crt_node = *list;
	while (crt_node->prev != NULL)
		crt_node = crt_node->prev;
	head = crt_node;
	(void)head;

	/* ask for memory for new list */
	sorted_list = malloc(sizeof(listint_t));
	if (sorted_list == NULL)
		return;
	/* memset */

	/* while crt isn't tail, there's stuff ahead */
	while (crt_node->next != NULL)
	{
		/* i will free this list progressively */
		insert(&crt_node, &sorted_list);
		crt_node = crt_node->next;
		free(crt_node->prev);
		/* ^---works even if prev is NULL */
	}
	insert(&crt_node, &sorted_list);
	free(crt_node);
}


void print_node(listint_t *, char *); /* DEBUG */

/**
 * insert - a subroutine to aid insertion_sort
 * essentially finds the place of the node in the head of the list.
 * no need for error-checking here. main should handle that.
 * this makes a new node, so make sure to free
 *
 * @head: address of the head of the doubly-linked list
 * @node: the node to place in its proper place.
 * Return: no return value
 */
void insert(listint_t **node, listint_t **head)
{
	listint_t *crt_node, *pre_node, *node_copy;

	node_copy = malloc(sizeof(listint_t));
	if (node_copy == NULL)
		return;
	/* copy over the data */
	node_copy->n = (*node)->n;
	node_copy->prev = (*node)->prev;
	node_copy->next = (*node)->next;
	if (*head == NULL)
		*head = node_copy;
	else
	{
		crt_node = *head;
		while (crt_node != NULL)
		{
			if (node_copy->n >= crt_node->n)
			{
				if (crt_node->prev == NULL)
				{
					crt_node->prev = node_copy;
					node_copy->prev = NULL;
					node_copy->next = crt_node;
					*head = node_copy;
				}
				else
				{
					pre_node = crt_node->prev;
					node_copy->prev = pre_node;
					crt_node->prev->next = node_copy;
					crt_node->prev = node_copy;
					node_copy->next = crt_node;
				}
				print_list(*head);
				return;
			}
			crt_node = crt_node->next;
		}
	}
}


/* DEBUG */
void print_node(listint_t *node, char *name)
{
	printf("NAME: %s\n", name);
	printf("n: %d\n", node->n);
}
