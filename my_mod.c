#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod - computes the rest of the division of the second
 * top element by the top element
 *
 * @stack: pointer to the stack
 * @line_number: line no. in the Monty bytecode file
 *
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
