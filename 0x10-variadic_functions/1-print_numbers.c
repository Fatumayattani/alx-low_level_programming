#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
* print_numbers - prints integer with a separator
* @separator: print between numbers
* @n: number of arguments
*
* Return: void
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i;
int num;
va_list list;

va_start(valist, n);
for (i = 0; i < n; i++)
{	
num = va_arg(valist, int);
printf("%d", num);
if (i < n - 1 && separator)
printf("%s", separator);
}
printf("\n");
va_end(valist);
}
