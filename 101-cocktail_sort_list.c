#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap1 - SWAP
 * @list: list
 * @node1: list
 * @node2: list
 * return: void
 */

void swap1(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	node1->prev = node2, node2->next = node1;
	if (!node2->prev)
		*list = node2;
	print_list(*list);
}
/**
 * cocktail_sort_list - insertion sort algorithm
 * @list: list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next_n, *prev_n;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;
	do {
		swapped = 0;
		for (; node->next; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swapped = 1;
				next_n = node->next;
				swap1(list, node, next_n);
				node = next_n;
			}
		}
		if (!swapped)
			break;
		for (; node->prev; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swapped = 1;
				prev_n = node->prev;
				swap1(list, prev_n, node);
				node = prev_n;
			}
		}
	} while (swapped);
}
