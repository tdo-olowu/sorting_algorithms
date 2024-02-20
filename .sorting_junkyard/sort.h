#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/**
 * struct ordering_t - binds names and comparators
 * @name: the name of the comparator e.g. "geq"
 * @comparator: the function which compares numbers
 *
 * Description
 * sorting algorithms may use different ways of comparing
 * elements (e.g. is A(i) <= A(i+1)? is A(i) > A(i+i)?, etc.
 * This data structure is for the sake of generality.
 * By default the <= relation will be used.
 */
typedef struct ordering_s
{
	char *name;
	int (*comparator)(int, int);
} ordering_t;


/* COMPARATORS */
int leq_ord(int, int);
int geq_ord(int, int);
int eq_ord(int, int);
int div_ord(int, int);


/* PRINTING FUNCTIONS */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* SORTING FUNCTIONS */
/* mandatory */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* advanced */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif SORT_H /* SORT_H */
