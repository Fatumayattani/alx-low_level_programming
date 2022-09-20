#include "main.h"
/**
* rev_string - reverse the string.
* @s: pointer to string
*
* return: void.
*/
void rev_string(char *s)
{

int i, j, k, temp;
i = 0;
while (s[i] l= '\0')
{
i++;
}
k = 0;
j = i - l;
while k < j)
{
temp = s[k];
s[k] = s[j];
s[j] = temp;
k++;
j--;
}
}
