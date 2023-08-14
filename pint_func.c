#include "monty.h"

/**
 * pint_func - prints the value at the top of the stack
 * @stack: pointer to the list
 * @line_number: int
 */

void pint_func(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{ /* Print error, close, free, and exit */
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		fclose(fd);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%i\n", (*stack)->n);
	}
}
