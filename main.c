#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

instruction_t *initialize_instructions(void);
void free_instructions(instruction_t *instructions);

stack_t *stack = NULL;

/**
 * initialize_instructions - initializes the instructions array
 *
 * Return: array of instruction_t structs
 */

instruction_t *initialize_instructions(void)
{
	instruction_t *instructions = malloc(NUM_OPCODES * sizeof(instruction_t));

	if (!instructions)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
	instructions[4].opcode = "swap";
	instructions[4].f = swap;
	return (instructions);
}

/**
 * free_instructions - frees memory from instructions array
 *
 * Return: Notning
 */

void free_instructions(instruction_t *instructions)
{
	free(instructions);
}

/**
 * main - entry point for Monty ByteCode interpreter
 *
 * @argc: no. of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	instruction_t *instructions = initialize_instructions();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		process_line(line, line_number, instructions, &stack);
	}
	fclose(file);
	if (line)
	{
		free(line);
	}
	free_instructions(instructions);
	free_stack();
	return (EXIT_SUCCESS);
}
