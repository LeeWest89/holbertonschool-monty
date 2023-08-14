#include "monty.h"

/**
 * number - checks if string is a number
 *
 * @tokens: array of tokens
 * @line_number: line number
 */

void number(char **tokens, unsigned int line_number)
{
	size_t i;

	if (!tokens[1])
	{
		push_error(line_number);
			return;
	}

	for (i = 0; i < strlen(tokens[1]); i++)
	{
		if (tokens[1][i] == '-' && i == 0)
			i++;
		if (isdigit(tokens[1][i]) == 0)
		{
			push_error(line_number);
				return;
		}
	}
}
