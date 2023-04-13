#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: a pointer to the head of the list to search in
 * @value: value to search for
 * Return: return a pointer to the first node where value is located OR NULL
 * if value is not present in head or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipper = NULL, *runner = NULL;
	size_t len;

	if (list == NULL)
		return (NULL);

	runner = list;
	skipper = list;

	while (skipper != NULL)
	{
		if (skipper->express != NULL)
			printf("Value checked at index [%d] = [%d]\n",
			       (int)(skipper->express->index), skipper->express->n);

		if (value == skipper->n)
			return (skipper);

		if (skipper->express != NULL && value <= skipper->express->n)
		{
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)skipper->index,
			       (int)skipper->express->index);

			runner = skipper;

			while (runner != NULL)
			{
				printf("Value checked at index [%d] = [%d]\n",
				       (int)runner->index, runner->n);

				if (value == runner->n)
					return (runner);
				runner = runner->next;
			}
		}

		if (skipper->express == NULL)
		{
			len = list_len(list);
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)skipper->index,
			       (int)(len - 1));

			runner = skipper;
			while (runner != NULL)
			{
				printf("Value checked at index [%d] = [%d]\n",
				       (int)runner->index, runner->n);
				if (value == runner->n)
					return (runner);
				runner = runner->next;
			}
		}
		skipper = skipper->express;
	}

	return (NULL);
}

/**
 * list_len - find number of elements in linked list_t list
 * @h: string to be assessed
 * Return: number of elements in a linked list_t list
 */

size_t list_len(skiplist_t *h)
{
	int n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
