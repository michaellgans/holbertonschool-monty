#include "monty.h"

void cats(void);

/**
 * main - driver file for monty
 * @argc: stuff
 * @argv: things
 * Return: 0/1
 */

int main(int argc, char **argv)
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
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL, *opcode = NULL;
	int y;

	if (argc != 2)
	{ /* If there are not 2 arguments, print error */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r"); /* open file */
	if (fd == NULL)
	{ /* If file can't be opened, print error */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length, fd) != -1)
	{ /* Take in input from user */
		tokens_array = tokstr(line, " \t\n");
		if (tokens_array == NULL)
		{ /* free and continue */
			free(tokens_array);
			tokens_array = NULL;
			continue;
		}
		y = 6;
		while (y >= 0)
		{
			if (strcmp(tokens_array[0], array[y].opcode) == 0)
			{
				array[y].f(&stack, line_number);
			}
			y--;
		}
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	/* Free and Return */
	free(tokens_array);
	if (line)
		free(line);

	return (0);
}
