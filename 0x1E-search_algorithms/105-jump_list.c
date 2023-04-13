#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers using the
 * Jump search algorithm
 *
 * @list: a pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: search for the value
 * Return: return a pointer to the first node where value is located OR NULL
 * if value is not present in head or if head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_size, i;
	listint_t *curr = NULL, *prev = NULL;

	if (list == NULL)
		return (NULL);

	/*find jump size*/
	jump_size = sqrt(size);

	curr = list;
	prev = list;
	i = 0;

	while (curr != NULL && i < jump_size)
	{
		curr = curr->next;
		i++;
	}

	/*find jump block containing target value*/
	while (curr != NULL && curr->n < value)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int)curr->index, curr->n);
		if (curr->n == value)
		{
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)(prev->index),
			       (int)curr->index);
			return (curr);
		}
		else if (curr->next == NULL)
		{
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)(prev->index),
			       (int)curr->index);
			return (jumplist_linear_search(list, prev->index,
						       size, value));
		}
		prev = curr;
		for (i = 0; curr->next != NULL && i < jump_size; i++)
			curr = curr->next;
	}

	/*perform linear search in block*/
	if (curr->index >= size || curr->n >= value)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int)curr->index, curr->n);
		printf("Value found between indexes [%d] and [%d]\n",
		       (int)(prev->index), (int)curr->index);
		return (jumplist_linear_search(list, prev->index, size, value));
	}
	return (NULL);
}

/**
 * jumplist_linear_search - searches for a value in an array of integers using
 * the Linear search algoritm
 *
 * @list: a pointer to the first element of the array to search in
 * @start: index of upper end of jump block + 1
 * @size: number of elements in array from breakpoint
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not present
 * in array or if array is NULL
 */


listint_t *jumplist_linear_search(listint_t *list, size_t start,
				  size_t size, int value)
{
	size_t i;
	listint_t *temp = NULL;

	if (list == NULL)
		return (NULL);

	temp = list;

	for (i = 0; temp != NULL && temp->index < start; i++)
		temp = temp->next;

	for (i = temp->index; temp != NULL && i < size; i++)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int)temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
