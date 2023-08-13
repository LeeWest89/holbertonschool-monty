#include "monty.h"

/**
 * free_stack - frees the stack
 *
 * @stack: the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *c = *stack;

	while (c)
	{
		if (!c->next)
		{
			free(c);
			break;
		}
		c = c->next;
		free(c->prev);
		}
}

/**
 * free_array - frees the array
 *
 * @array: the array
 */

void free_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
