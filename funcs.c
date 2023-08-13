#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		pint_error(line_number);
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: stack
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	else
	{
		t = (*stack)->next;
		free((*stack));
		(*stack) = t;
	}
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: stack
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	if (*stack == NULL || (*stack)->next == NULL)
		add_error(line_number);
	s = (*stack);
	s->next->n = (((*stack)->n) + ((*stack)->next->n));
	(*stack) = s->next;
	free(s);
}

/**
 * swap - swaps top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int s;

	if (!(*stack) || !(*stack)->next)
		swap_error(line_number);
	s = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = s;
}

/**
 * nop - does nothing
 *
 * @stack: stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
