#include "monty.h"

/**
 * push_func - adds a node to the list
 * @stack: pointer to the list
 * @line_number: int
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	/* Create pointer to new node */
	stack_t *new_node;
	int n = 0;

	if (tok_num(NULL, " \t\n") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(tokstr(NULL, "t \t\n")[0]);

	/* Allocate memory for new node */
	new_node = malloc(sizeof(instruction_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
	}

	/* Add new node to list */
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	/* If the list isn't empty, update prv to new node */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	/* Make new node the stack */
	*stack = new_node;
}
