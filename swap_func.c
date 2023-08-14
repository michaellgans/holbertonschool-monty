#include "monty.h"

/**
 * swap_func - swaps the top two elements of the stack
 * @stack: pointer to the list
 * @line_number: int
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if(*stack == NULL || (*stack)->next == NULL)
	{ /*print error, close, exit */
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
