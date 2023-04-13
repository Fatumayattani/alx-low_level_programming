#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers using the
 * Binary search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @size: array in element numbers
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not present
 * in array or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, start, end;

	if (array == NULL)
		return (-1);

	start = 0;
	end = size - 1;

	while (start <= end)
	{
		printf("Searching in array: ");
		print_array(array, start, end);
		mid = (start + end) / 2;
		if (value == array[mid])
			return (mid);
		else if (value < array[mid])
			end = mid - 1;
		else if (value > array[mid])
			start = mid + 1;
	}
	return (-1);
}

/**
 * print_array -This will Print an array of integers
 *
 * @array: The array to be printed
 * @start: The first element in array
 * @end: The last element in array
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
