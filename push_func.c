#include "monty.h"

void cute_cats(void);

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
	(void)line_number;
	char *endptr;
	long int num;

	/* Read the integer input */
	char *token = strtok(NULL, " \t\n");

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		close_error();
	}

	/* Convert token to integer */
	num = strtol(token, &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		close_error();
	}

	n = (int)num;

	/* Allocate memory for new node */
	new_node = malloc(sizeof(instruction_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close_error();
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
