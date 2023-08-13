#include "monty.h"

int tok_num(char *str, char *delims);
char **tokstr(char *line, char *delims);
int substrLen(char *str, char *delims);

/**
 * tok_num - calcs num of toks in str
 * @str: string to tokenize
 * @delims: delims to tokenize based on
 * Return: num of tokens in overall str
 */

int tok_num(char *str, char *delims)
{
	/* Declare and Initialize Variables */
	int tokTotal = 0, i, lineLen = 0;

	lineLen = strlen(str);

	/* Continue for the length of the string */
	for (i = 0; i < lineLen; i++)
	{
		/**
		 * Check if the current character is not:
		 * NULL, equal to the two delimiters
		 */

		if (str[i] && str[i] != delims[0] && str[i] != delims[1])
		{ /* Edge case for two delims */
			tokTotal++;
			i += substrLen(str + i, delims);
		}
	}
	return (tokTotal);
}

/**
 * substrLen - computes length of substr / token
 * @str: string in question
 * @delims: delims to tok based on
 * Return: length of substr
 */

int substrLen(char *str, char *delims)
{
	/* Declare and Initialize Variables */
	int i = 0;

	/**
	 * Continue looping while 'str' is not:
	 * null or equal to delimiter characters
	 */
	while (str[i] && str[i] != delims[0] && str[i] != delims[1])
	{
		i++;
	}
	return (i);
}

/**
 * tokstr - tokenizes str into substrs
 * @line: str to tokenize
 * @delims: delim to tokenize based on
 * Return: token array
 */

char **tokstr(char *line, char *delims)
{
	/* Declare and Initialize Variables */
	char **tokenStorage;
	int i, j = 0, k, tokTotal, ssLen = 0;

	/* Check if line is NULL or empty */
	if (!line)
		return (NULL);
	if (!(*line))
		return (NULL);

	/* Count number of tokens */
	tokTotal = tok_num(line, delims);

	/* Allocate Storage */
	tokenStorage = malloc(sizeof(char *) * (tokTotal + 1));

	/* Continue for each token */
	for (i = 0; i < tokTotal; i++)
	{
		/* Skip over delimiters at the start of line */
		while (line[j] == *delims || line[j] == delims[1])
			j++;

		/* Find length of what's left to tokenize */
		ssLen = substrLen(line + j, delims);

		/* Allocate memory */
		tokenStorage[i] = malloc(sizeof(char) * (ssLen + 1));

		/* Store substring into token storage */
		/* I: index of storage J: index of input K: index of substring */
		for (k = 0; k < ssLen; k++, j++)
			tokenStorage[i][k] = line[j];
		tokenStorage[i][k] = '\0';
	}

	/* set last character of storage to NULL */
	tokenStorage[i] = NULL;

	return (tokenStorage);
}
