#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>

#define NUM_OPCODES 15

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct opcode_mapping_s - maps opcodes to their associated functions
 *
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its associated function
 */

typedef struct opcode_mapping_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
} opcode_mapping_t;

/* global */
extern stack_t *stack;

/* Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void process_line(char *line, unsigned int line_number,
		instruction_t *instructions, stack_t **stack);
void free_stack(void);
int is_integer(const char *str);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void multi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
