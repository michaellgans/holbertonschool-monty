#include "monty.h"

/**
 * pall_func - prints all nodes
 * @stack: pointer to the list
 * @line_number: int
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	/* Define and Initiazlie Variables */
	const stack_t *current = *stack;
	int x;
	(void)line_number;

	for (x = 0; current != NULL; x++)
	{ /* traverse the list and print */
		printf("%d\n", current->n);
		current = current->next;
	}
}
