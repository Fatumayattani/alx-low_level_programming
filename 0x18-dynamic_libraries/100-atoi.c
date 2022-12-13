#include "main.h"

/**
 * _atoi - find numbers
 * @s:char
 * Return: int
 */
int _atoi(char *s)
{
	int sign, my_num, teens;
	char find_num = 'N';

	my_num = 0;
	teens = 10;
	sign = 1;
	if (s)
	{
		while (*s)
		{
			if (*s == '-')
				sign *= -1;
			if (*s >= '0' && *s <= '9' && find_num == 'N')
			{
				find_num = 'Y';
				my_num = *s - '0';
			}
			else if (*s >= '0' && *s <= '9' && find_num == 'Y')
			{
				my_num *= teens;
				my_num += (*s - '0');
			}
			else if ((*s < '0' || *s > '9') && find_num == 'Y')
			{
				break;
			}
			s++;
		}
	}
	return (sign * my_num);
}
