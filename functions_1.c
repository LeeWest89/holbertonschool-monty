#include "monty.h"

/**
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg_s;
	int n;
	stack_t *nnod;

	arg_s = strtok(NULL, " \t\n");
	if (arg_s == NULL)
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg_s);
	*nnode = malloc(sizeof(stack_t));
	if (nnod == NULL)
	{
		fprintf(stderr, "Error: L%u: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	nnode->n = n;
	nnode->prev = NULL;
	nnode->next = *stack;

	if (*stack)
		(*stack)->prev = nnode;
	*stack = nnode;
}

/**
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	*current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
