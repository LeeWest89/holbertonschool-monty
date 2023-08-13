#include "monty.h"

/**
 * tokenize - tokenizes the line
 *
 * @line: line
 * Return: array of tokens
 */

char **tokenize(char *line)
{
	char **a;
	char *token = NULL;
	char *delim = "\t \r\n";
	int i = 3;

	token = strtok(line, delim);
	if (!token)
		return (NULL);
	a = malloc(sizeof(char **) * 3);
	if (!a)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (--i)
		a[i - 1] = NULL;
	while (token)
	{
		if (i < 3)
			a[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	a[2] = NULL;
	return (a);
}
