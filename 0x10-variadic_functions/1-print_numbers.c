#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
* print_numbers - prints integer with a separator
* @separator: print between numbers
* @n: number of arguments
*
* Return: void
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
char *separator;
unsigned int i;
va_list list;
if (separator == NULL || *separator == 0)
separator = "";
else
seperator = (char *) separator;
va_start(list, n);
if (n > 0)
printf("%d", va_arg(list, int));
for (i = 1; i < n; i++)
printf("%s%d", separator, va_arg(list, int));
printf("\n");
va_end(list);
}
