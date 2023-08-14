#include "monty.h"

/**
 * arg_error - error for if no file or wrong number of args
 */

void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * o_error - file opening error
 *
 * @argv: argument array
 */

void o_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * i_error - opcode is unknown
 *
 * @line_number: line number
 * @opcode: opcode
 */

void i_error(int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
