#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the Monty bytecode file
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
