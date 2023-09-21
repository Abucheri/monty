#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the Monty bytecode file
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
