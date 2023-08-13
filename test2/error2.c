#include "monty.h"

/**
 * push_error - push error
 *
 * @line_number: line number
 */

void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * m_error - malloc error
 */

void m_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
