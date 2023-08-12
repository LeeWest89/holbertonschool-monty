#include "monty.h"

/**
 */

void tokenize(char *line, stack_t **stack, unsigned int line_number)
{
	char *arg_s = strtok(NULL, " \t\n");

	if (opcode)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg_s)
			{
				int arg = atoi(arg_s);
				push(stack, arg);
			}
			else
			{
				fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else
		{
			fprintf(stderr, "Error: L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}


/**
 */

int main(int argc, char *argv[])
{
	FILE *file;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	*file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *temp, *stack;

	*stack = NULL;
	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		tokenize(line, &stack, line_number);
		line_number++;
	}
	fclose(file);
	if (line)
		free(line);
	while (stack)
	{
		*temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
