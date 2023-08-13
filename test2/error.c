#include "monty.h"

/**
 * arg_error - handles error in the beginning
 */

void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * o_error - error on opening the file
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
 * i_error - unknown opcode
 *
 * @line_number: line number
 * @opcode: opcode
 */

void i_error(int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
