#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * process_line - process a line of Monty ByteCode and execute the operation
 *
 * @line: line of Monty ByteCode to process
 * @line_number: line no. in the Monty ByteCode file
 * @instructions: array of instruction structures
 * @stack: pointer to the stack
 *
 * Return: Nothing
 */

void process_line(char *line, unsigned int line_number,
		instruction_t *instructions, stack_t **stack)
{
	char *opcode;
	instruction_t instruction;
	int i;

	opcode = strtok(line, " \t\n\r$");
	if (opcode == NULL || *opcode == '#')
		return;
	for (i = 0; i < NUM_OPCODES; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instruction = instructions[i];
			instruction.f(stack, line_number);
			return;
		}
	}
	if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
		return;
	} else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
		return;
	} else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
		return;
	} else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
		return;
	} else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
