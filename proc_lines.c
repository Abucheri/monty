#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void process_opcode(char *opcode, unsigned int line_number,
		instruction_t *instructions, stack_t **stack);
void process_line(char *line, unsigned int line_number,
		instruction_t *instructions, stack_t **stack);

/**
 * process_opcode - process an opcode and execute the operation
 *
 * @opcode: opcode to process
 * @line_number: line number in Monty ByteCode file
 * @stack: pointer to the stack
 * @instructions: array of instruction structures
 *
 * Return: Nothing
 */

static void process_opcode(char *opcode, unsigned int line_number,
		instruction_t *instructions, stack_t **stack)
{
	instruction_t instruction;
	int i;

	for (i = 0; i < NUM_OPCODES; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instruction = instructions[i];
			instruction.f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

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

	opcode = strtok(line, " \t\n\r$");
	if (opcode == NULL || *opcode == '#')
		return;
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
	} else if (strcmp(opcode, "div") == 0)
	{
		my_div(stack, line_number);
		return;
	} else if (strcmp(opcode, "mul") == 0)
	{
		multi(stack, line_number);
		return;
	} else if (strcmp(opcode, "mod") == 0)
	{
		mod(stack, line_number);
		return;
	}
	process_opcode(opcode, line_number, instructions, stack);
}
