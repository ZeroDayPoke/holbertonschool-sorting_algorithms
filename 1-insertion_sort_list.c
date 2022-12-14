#include "sort.h"

/**
 * insertion_sort_list - sorts DLL int list asc
 * @list: pointer to top node
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *search, *nodeA, *nodeB;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	search = *list;
	while (search->next)
	{
		if (search->n > search->next->n)
		{
			nodeA = search;
			nodeB = search->next;
			nodeB->prev = nodeA->prev;
			if (nodeA->prev)
				nodeA->prev->next = nodeB;
			else
				*list = nodeB;
			if (nodeB->next)
				nodeB->next->prev = nodeA;
			nodeA->prev = nodeB;
			nodeA->next = nodeB->next;
			nodeB->next = nodeA;
			search = search->prev;
			print_list(*list);
			if (search->prev && search->prev->n > search->n)
			{
				search = search->prev;
				continue;
			}
		}
		search = search->next;
	}
}
