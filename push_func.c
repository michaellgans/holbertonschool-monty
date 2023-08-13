#include "monty.h"

/**
 * push_func - adds a node to the list
 * @stack: pointer to the list
 * @line_number: int
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	/* Create pointer to new node */
	instruction_t *new_node;
	
	/* If line_number isn't an int */
	if (line_number < '48' || line_number > '57' || line_number == NULL)
	{
		perror("L<line_number>: usage: push integer\n");
		exit (EXIT_FAILURE);
	}

	/* Allocate memory for new node */
	new_node = malloc(sizeof(instruction_t));
	if (new_node == NULL)
	{
		free(new_node);
	}

	/* Add new node to list */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* If the list isn't empty, update prv to new node */
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	/* Make new node the head */
	*head = new_node;
}
