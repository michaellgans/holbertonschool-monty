#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: pointer to the list
 * @line_number: int
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{ /* print error, free, close */
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free(stack);
		fclose(fd);
	}

	current->next->n += current->n;
	*stack = current->next;
	(*stack)->prev = NULL;

	free(current);
}
