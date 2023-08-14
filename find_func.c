#include "monty.h"

/**
 * get_func - matches up call with function
 * @stack: current node
 * @operation: function call name
 * @line: line number
 * Return: function matched
 */

void (*get_func(stack_t **stack, int line, char *operation))(stack_t **, unsigned int)
{
	instruction_t array[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func}
	};
	int x = 0;

	while (strcmp(operation, array[x].opcode) != 0)
	{ /* look for matching operation and function */
		x++;
		if (x > 7)
		{ /* If function isn't listed */
			fprintf(stderr, "L%d: unknown instruction %s\n", line, operation);
			free_stack(stack);
			close_error();
		}
	}
	return (array[x].f);
}
