#include "main.h"
#include <stdlib.h>

/**
*
* malloc_checked - creates an array of integers.
*
* @b: input.
*
* Return: Output.
*
*/

void *malloc_checked(unsigned int b)

{
void *f = malloc(b);
if (f == NULL)

{
exit(98);
}

return (f);

}
