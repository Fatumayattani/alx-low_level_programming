#include "main.h"

/**
* print_last_digit - prints the last digit of a number
* @ld: the last digit
*
* Return: the value of the last digit
*/
int print_last_digit(int ld)
{
if (ld > 0)
{
ld = ld % 10;
_putchar(ld + '0');
}
else
{
ld = ld % 10 * -1;
_putchar(ld + '0');
}
return (ld);
}
