#include <unistd.h>
#include "main.h"

/**
*
* _putchar - prints the character c to stdout
*
* @c: the character to print
*
* On error, -1 is returned, and error is set appropriately.
*
*/

int _putchar(char c)

{

	return (write(1, &c, 1));

}
