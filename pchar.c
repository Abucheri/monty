#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar - prints the character at the top of the stack
 *
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value is negative\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
