#include "monty.h"

/**
 * free_stack - free lists
 * @stack: pointer to beginning of linked list
 */

void free_stack(stack_t **stack)
{
	if (!(stack) || !(*stack))
	{
		return;
	}

	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
