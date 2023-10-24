#include "sort.h"

/**
 * cocktail_sort_list - This function sorts a doubly linked list of integers
 * in ascending order using an cocktail shaker sort algorithm
 * @list: This is the doubly linked list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped_f, swapped_b;
	int shake_range = 1000000, checks;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		swapped_f = swapped_b = false;
		for (checks = 0; temp->next && checks < shake_range; checks++)
		{
			if (temp->next->n < temp->n)
			{
				dll_adj_swap(list, temp, temp->next);
				swapped_f = true;
			}
			else
				temp = temp->next;
		}
		if (!temp->next)
			shake_range = checks;
		if (swapped_f)
			temp = temp->prev;
		shake_range--;
		for (checks = 0; temp->prev && checks < shake_range; checks++)
		{
			if (temp->n < temp->prev->n)
			{
				dll_adj_swap(list, temp->prev, temp);
				swapped_b = true;
			}
			else
				temp = temp->prev;
		}
		if (swapped_b)
			temp = temp->next;
	} while (swapped_f || swapped_b);
}
