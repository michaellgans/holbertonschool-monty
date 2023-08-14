#include "monty.h"

/**
 * push_helper - creates new node
 * @stack: where to push onto
 * @line_number: line number in file
 * @pushNum: what to add
 */

void push_helper(stack_t **stack, unsigned int line_number, char *pushNum)
{
	/* Declare Variables */
	char *endptr;
	long int num = strtol(pushNum, &endptr, 10);

	if (strcmp(pushNum, "0") == 0)
	{
		(*stack)->n = 0;
	}
	else
	{
		if (*endptr != '\0')
		{ /* If it's not 0 */
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			close_error();
		}
	(*stack)->n = (int)num;
	}
}
