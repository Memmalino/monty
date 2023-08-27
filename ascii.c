#include "monty.h"
char *args[2];

/**
 * pchar - function that prints the char at the top of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the inex of the current line
 * Return: void
 */

void    pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!(*stack))
	{
		if (args[0] != NULL)
			free(args[0]);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (!isascii(top->n))
	{
		if (args[0] != NULL)
			free(args[0]);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}
/**
 *  pstr - function that prints the string starting at the top of the stack
 *  @stack: double pointer to the top of the stack
 *  @line_number: the index of the current line
 *  Return: void
 */
void    pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top;

	if (!stack)
		return;

	top = *stack;

	while (top)
	{
		if (!top->n || !isascii(top->n))
			break;

		printf("%c", top->n);
		top = top->next;
	}

	printf("\n");
}
