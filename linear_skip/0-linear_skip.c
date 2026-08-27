#include "search.h"

/**
 * linear_skip - Search for a value in a sorted skip list
 *
 * @list: Head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start;
	skiplist_t *end;
	skiplist_t *current;

	if (list == NULL)
		return (NULL);

	start = list;
	end = NULL;
	while (start->express != NULL)
	{
		end = start->express;
		printf("Value checked at index [%lu] = [%d]\n",
			end->index, end->n);
		if (end->n >= value)
			break;
		start = end;
	}

	if (end == NULL || end->n < value)
	{
		end = start;
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		start->index, end->index);
	current = start;
	while (current != NULL && current->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			current->index, current->n);
		if (current->n == value)
			return (current);
		if (current->n > value)
			return (NULL);
		current = current->next;
	}

	return (NULL);
}
