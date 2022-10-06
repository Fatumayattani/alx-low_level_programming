#include <stdlib.h>
/**
*
* malloc_checked - creates an array of integers.
* @b: input.
*
* Return: Output.
*
*/
void *malloc_checked(unsigned int b)
{
void *p = malloc(b);
if (p == NULL)
exit(98);
return (p);
}
