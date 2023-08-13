#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

extern int num;

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

/*monty functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
/*functions*/
void free_array(char **array);
char **tokenize(char *line);
int main(int argc, char *argv[]);
void number(char **tokens, unsigned int line_number);
void opcall(stack_t **stack, char **tokens, unsigned int line_number);
void free_stack(stack_t **stack);
/*error*/
void arg_error(void);
void o_error(char **argv);
void i_error(int line_number, char *opcode);
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void add_error(unsigned int line_number);
void swap_error(unsigned int line_number);
void push_error(unsigned int line_number);
void m_error(void);


#endif
