#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: double ptr to head
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *liist;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	liist = (*list)->next;

	while (liist)
	{
	listint_t *key = liist;
	listint_t *unsorted = liist->prev;

	while (unsorted != NULL && unsorted->n > key->n)
	{
		unsorted->next = key->next;
			if (key->next != NULL)
			{
				key->next->prev = unsorted;
			}

		key->next = unsorted;
		key->prev = unsorted->prev;

		if (unsorted->prev != NULL)
		unsorted->prev->next = key;
		unsorted->prev = key;

		if (key->prev == NULL)
		{
			*list = key;
		}

			unsorted = key->prev;
			print_list(*list);
		}
		liist = liist->next;
	}
}