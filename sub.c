#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sub - subtracts the top element from the second top element of the stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the Monty bytecode file
 *
 * Return: Nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
