#include "monty.h"
char *args[2];
/**
 ** pop - removes the top element of the stack.
 ** @stack: head stack
 ** @line_number: line number
 **/

void	pop(stack_t **stack, unsigned int line_number)
{
	stack_t	*tmp;

	if (*stack == NULL)
	{
		if (args[0] != NULL)
			free(args[0]);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
