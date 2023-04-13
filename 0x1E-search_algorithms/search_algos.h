#ifndef __SEARCH__
#define __SEARCH__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Points to the next node
 * @express: Points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_array(const int *array, size_t start, size_t end);
int jump_search(int *array, size_t size, int value);
int jump_linear_search(int *array, size_t start, size_t size,
		       size_t jump_size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int exp_binary_search(int *array, size_t start, size_t end, int value);
int find_min(int a, int b);
int advanced_binary(int *array, size_t size, int value);
int adv_bin_helper(int *array, size_t start, size_t end, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
listint_t *jumplist_linear_search(listint_t *list, size_t start,
				  size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);
size_t list_len(skiplist_t *h);
#endif /*__SEARCH__*/
