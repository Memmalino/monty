#include "monty.h"
/**
 * pall - function that prints all the value of stack
 * from the top of the stack.
 * @stack: head
 * @line_number: unused
 * Return: void
 **/

void	pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t	*head;

	if (!stack || !(*stack))
		return;

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
