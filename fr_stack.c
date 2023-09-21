#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_stack - free all mem associated with the stack
 *
 * Return: Nothing
 */

void free_stack(void)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
