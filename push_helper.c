#include "monty.h"

/**
 * push_helper - creates new node
 * @stack: where to push onto
 * @line_number: line number in file
 * @pushNum: what to add
 */

void push_helper(stack_t **stack, unsigned int line_number, char *pushNum)
{
	if (strcmp(pushNum, "0") == 0)
		(*stack)->n = 0;

	if (strcmp(pushNum, "0") != 0)
	{ /* If it's not 0 */
		(*stack)->n = atoi(pushNum);
		if ((*stack)->n == 0 || (pushNum[0] != '-' && (*stack)->n == -1))
		{ /* if it isn't an integer */
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			close_error();
                }
        }
}
