#include "monty.h"

/**
 * pint_error - pint error
 *
 * @line_number: line number
 */

void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - pop error
 *
 * @line_number: line number
 */

void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * add_error - add error
 *
 * @line_number: line number
 */

void add_error(unsigned int line_number)
{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
}

/**
 * swap_error - swap error
 *
 * @line_number: line number
 */

void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
