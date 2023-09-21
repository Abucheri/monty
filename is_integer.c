#include "monty.h"
#include <ctype.h>

/**
 * is_integer - Checks if a string represents a valid integer
 *
 * @str: The string to check
 *
 * Return: 1 if the string is a valid integer
 * else, 0
 */

int is_integer(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
