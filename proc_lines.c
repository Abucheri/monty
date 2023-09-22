#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void process_opcode(char *opcode, unsigned int line_number,
		instruction_t *instructions, stack_t **stack);
void process_line(char *line, unsigned int line_number,
		instruction_t *instructions, stack_t **stack);

opcode_mapping_t opcode_mappings[] = {
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", my_div},
	{"mul", multi},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{NULL, NULL}
};

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
	int i;

	opcode = strtok(line, " \t\n\r$");
	if (opcode == NULL || *opcode == '#')
		return;
	for (i = 0; opcode_mappings[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcode_mappings[i].opcode) == 0)
		{
			opcode_mappings[i].func(stack, line_number);
			return;
		}
	}

	process_opcode(opcode, line_number, instructions, stack);
}
