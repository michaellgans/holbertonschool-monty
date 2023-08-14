#include "monty.h"

/**
 * close_error - gracefully closes and exits
 */

void close_error(void)
{
	fclose(fd);
	exit(EXIT_FAILURE);
}
