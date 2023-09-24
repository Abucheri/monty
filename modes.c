#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * queue - sets the format of the data to a queue (FIFO)
 *
 * @stack: pointer to the stack
 * @line_number: line number in Monty ByteCode file
 *
 * Return: Nothing
 */

void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *new_queue = NULL;
	stack_t *current = *stack;
	stack_t *temp = NULL;

	(void)line_number;

	if (*stack == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (*stack != NULL)
	{
		if (new_queue == NULL)
		{
			new_queue = *stack;
			new_queue->prev = NULL;
			new_queue->next = NULL;
			current = new_queue;
		} else
		{
			temp = *stack;
			current->next = temp;
			temp->prev = current;
			temp->next = NULL;
			current = temp;
		}
		*stack = (*stack)->next;
	}
	*stack = new_queue;
}

/**
 * stack_op - sets the format of the data to a stack (LIFO)
 *
 * @stack: pointer to the stack
 * @line_number: line number in Monty ByteCode file
 *
 * Return: Nothing
 */

void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
