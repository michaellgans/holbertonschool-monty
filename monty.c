#include "monty.h"

void cute_cats(void);
FILE *fd = NULL;

/**
 * main - monty python code
 * @argc: number of total arguments
 * @argv: each argument at index
 * Return: 0/1
 */

int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;
	char *line = NULL, *token = NULL;
	char tokens_array[50] = {'\0'}, push_array[50] = {'\0'};
	size_t length = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{ /* If the incorrect amount of arguments are passed */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open source file */
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{ /* If file can't be opened */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (; getline(&line, &length, fd) != EOF; line_number++)
	{
		token = strtok((line), " \t\n");
		if (token == NULL)
		{ /* If line is empty */
			free(line);
			line = NULL;
			continue;
		}

		strcpy(tokens_array, token);

		f = get_func(&stack, line_number, tokens_array);

		if (f == NULL)
		{ /* If no function is found */
			fprintf(stderr, "Error: malloc failed\n");
			close_error();
		}

		if (strcmp(tokens_array, "push") == 0)
		{ /* If the command is push */
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{ /* If token is empty */
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				close_error();
			}
			strcpy(push_array, token);
		}
		free(line);
		line = NULL;
		f(&stack, line_number);

		if (strcmp(tokens_array, "push") == 0)
		{ /* If the command is push */
			push_helper(&stack, line_number, push_array);
		}
	}
	free(line);
	fclose(fd);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
