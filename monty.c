#include "monty.h"

/**
 * main - driver file for monty
 * Return: 0/1
 */

int main(void)
{
	/* Array of Structs */
	instruction_t array[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func}
	};

	/* Declare and Initilize Variables */
	char **tokens_array = NULL;
	size_t length = 0;
	char *line = NULL;

	while (true)
	{ /* Infinite loop that keeps monty going */

		if (getline(&line, &length, stdin) == -1)
		{ /* Take in input from user */
			break;
		}

		cleanstr(line); /* Edge case for just new line character */

		if (!tok_num(line, " "))
			continue;

		/* Tokenize */
		tokens_array = tokstr(line, " ");

		/* Run Built In */
		y = 6;
		while (y >= 0)
		{
			if(strcmp(tokens_array[0],array[y].opcode) == 0);
			{
				array[y].f(&stack, line_number);
			}
			y--;
		}

		/* Free and Return */
		free(tokens_array);
		if (line)
			free(line);

		return (0);
	}
}
