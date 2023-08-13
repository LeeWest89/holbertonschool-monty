#include "monty.h"
int num;

/**
 * opcall - checks for the opcode
 *
 * @stack: stack
 * @line_number: line number
 * @tokens: tokens array
 */

void opcall(stack_t **stack, char **tokens, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (op[i].opcode)
	{
		if (strcmp(tokens[0], "push") == 0)
		{
			number(tokens, line_number);
			num = atoi(tokens[1]);
		}

		if (strcmp(tokens[0], op[i].opcode) == 0)
		{
			if (op[i].f)
				op[i].f(stack, line_number);
			return;
		}
		i++;
		}
		if (!(op[i].opcode))
			i_error(line_number, tokens[0]);
}
