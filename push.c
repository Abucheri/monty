#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - pushes elem into stack
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line no. in the Monty bytecode file
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *data = NULL;
	stack_t *new_node;

	data = strtok(NULL, " \t\n\r$");
	if (!data || !is_integer(data))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(data);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
