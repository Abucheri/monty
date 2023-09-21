#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_div - divides the second top element of the stack by the top element
 *
 * @stack: pointer to the stack
 * @line_number: line no. of the opcode in the Monty file
 *
 * Return: Nothing
 */

void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
