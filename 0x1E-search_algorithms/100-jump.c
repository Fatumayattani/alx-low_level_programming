#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @size: array in element numbers
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not
 * present in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump_size, i, target_idx;

	if (array == NULL)
		return (-1);

	/*find jump size*/
	jump_size = sqrt(size);

	/*find jump block containing target value*/
	i = 0;
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)i, array[i]);
		if (array[i] == value)
		{
			printf("Value found between indexes [%d] and [%d]\n",
			       (int)(i - jump_size), (int)i);
			return (i);
		}
		i = i + jump_size;
	}

	/*perform linear search in block*/
	if (i >= size || array[i] >= value)
	{
		printf("Value found between indexes [%d] and [%d]\n",
		       (int)(i - jump_size), (int)i);
		target_idx = jump_linear_search(array, i + 1, size,
						jump_size, value);
		return (target_idx);
	}
	return (-1);
}

/**
 * linear_search - searches for a value in an array of integers using the
 * Linear search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @start: index of upper end of jump block + 1
 * @size: number of elements in array from breakpoint
 * @jump_size: window size when interating through array
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not present
 * in array or if array is NULL
 */


int jump_linear_search(int *array, size_t start, size_t size,
		       size_t jump_size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = start - jump_size - 1; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
