#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *  using the Binary search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @size: element in array numbers
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not
 * present in array or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start, end;

	if (array == NULL)
		return (-1);

	start = 0;
	end = size - 1;
	return (adv_bin_helper(array, start, end, value));
}

/**
 * adv_bin_helper - searches for a value in a sorted array of integers using
 * recursive Binary Search
 *
 * @array: a pointer to the first element of the array to search in
 * @start: index of start of the element
 * @end: index of the end of the element
 * @value: search for the value
 * Return:  first index where value is located or -1 if value is not
 * present in array or if array is NULL
 */
int adv_bin_helper(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	printf("Searching in array: ");
	print_array(array, start, end);

	mid = start + (end - start) / 2;
	if (value == array[mid] && value != array[mid - 1])
		return (mid);
	else if (value <= array[mid])
		return (adv_bin_helper(array, start, mid, value));
	else
		return (adv_bin_helper(array, mid + 1, end, value));
}

/**
 * print_array - Prints an array of integers
 *
 * @array: prints the array
 * @start: This is the first element in array
 * @end: This is the Last element in array
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
