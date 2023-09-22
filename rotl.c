#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * rotl - rotates the stack to the top
 *
 * @stack: pointer to the stack
 * @line_number: line number in Monty ByteCode file
 *
 * Return: Nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *last = NULL;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		last = first = *stack;
		while (last->next)
			last = last->next;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}
