#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * multi - multiplies the second top element of the stack with the top element
 *
 * @stack: pointer to the stack
 * @line_number: line no. in the Monty bytecode file
 *
 * Return: Nothing
 */

void multi(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
