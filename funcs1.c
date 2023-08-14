#include "monty.h"

/**
 * push - pushes the node
 *
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = num;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->next->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints the stack
 *
 * @stack: stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *n;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;
	n = *stack;
	while (n)
	{
		printf("%d\n", n->n);
		n = n->next;
	}
}
