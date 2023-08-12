#include "monty.h"

/**
 */

int monty_calls(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opcall[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	for (;opcall[i].line; i++)
	{
		if (strcmp(line, opcall[i].line) == 0)
			return (opcall[i].f);
	}
	return (NULL);
}
