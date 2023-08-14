#include "monty.h"

/**
 * main - entry point
 *
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, **tokens = NULL;
	unsigned int ln = 1;
	stack_t *stack = NULL;
	size_t l = 0;

	if (argc != 2)
		arg_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		o_error(argv);
	while (getline(&line, &l, file) != -1)
	{
		tokens = tokenize(line);
		if (tokens)
		{
			opcall(&stack, tokens, ln);
			free(tokens);
		}
		ln++;
	}
	free(line);
	fclose(file);
	free_stack(&stack);
	return (0);
}
