#include "monty.h"

/**
 * cleanstr - removes newline chars from user input
 * @line: pointer to user input
 * Return: 0/1
 */
int cleanstr(char *line)
{
	int x = 0;

	/* Continue to run until null byte is found */
	while (line[x])
	{
		/* If new line character is found */
		if (line[x] == '\n')
		{
			/* Replace with null byte */
			line[x] = '\0';
		}
		x++;
	}
	return (0);
}
