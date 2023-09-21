#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - prints all vals on the stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line no. in the Monty bytecode file
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
