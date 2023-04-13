#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of
 * integers using the Exponential search algorithm
 *
 * @array: a pointer to the first element of the sorted array to search
 * @size: number of elements in array
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is
 * not present in array or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	i = 1;
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)i, array[i]);
		i = i * 2;
	}

	if (i >= size)
	{
		printf("Value found between indexes [%d] and [%d]\n",
		       (int)(i / 2), (int)i - 1);
		return (exp_binary_search(array, i / 2, find_min(i - 1, size),
					  value));
	}
	else
	{
		printf("Value found between indexes [%d] and [%d]\n",
			     (int)(i / 2), (int)i);
		return (exp_binary_search(array, i / 2, find_min(i, size),
					  value));
	}
}

/**
 * exp_binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @start: index of starting element
 * @end: This is the index of last element
 * @value: search of the value
 * Return:  first index where value is located or -1 if value is not present
 * in array or if array is NULL
 */
int exp_binary_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (array == NULL)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");
		print_array(array, start, end);
		mid = (start + end) / 2;
		if (value == array[mid])
		{

			return (mid);
		}
		else if (value < array[mid])
			end = mid - 1;
		else if (value > array[mid])
			start = mid + 1;
	}
	return (-1);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: prints the array
 * @start: First element in array
 * @end: Last element in array
 */
void print_array(const int *array, size_t start, size_t end)
{
	size_t i;

	i = start;
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * find_min - find minimum value
 *
 * @a: This is the first value
 * @b: This is the second value
 * Return: This returns the minimum value
 */
int find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
