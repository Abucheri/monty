#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * pstr - print the string starting at the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number in Monty ByteCode file
 *
 * Return: Nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && isprint(current->n))
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
