#include "monty.h"

/**
 * pop_func - removes top element of the stack
 * @stack: pointer to the list
 * @line_number: int
 */

void pop_func(stack_t **stack, unsigned int line_number)
{
	/* Define and Initialize Variables */
	stack_t *current = *stack;

	if (*stack == NULL)
	{ /* print error, close, free, and exit */
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		fclose(fd);
		free(stack);
		exit(EXIT_FAILURE);
	}

	*stack = current->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(current);
}
