#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line no. in the Monty bytecode file
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
