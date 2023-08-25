#include "monty.h"
char *args[2];
/**
 * pall - function that prints all the value of stack
 * from the top of the stack.
 * @stack: head
 * @line_number: unused
 * Return: void
 */

void	pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t	*current = *stack;


	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	if (args[0] != NULL)
		free(args[0]);
}
