#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: double pointer to the stack
 * @line_number: line number in Monty ByteCode file
 *
 * Return: Nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL, *second_last = NULL;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		last = second_last = *stack;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
