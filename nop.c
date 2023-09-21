#include "monty.h"

/**
 * nop - doesn't do anything
 *
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the Monty bytecode file
 *
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
