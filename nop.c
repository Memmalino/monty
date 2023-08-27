#include "monty.h"

/**
 * nop - function that does nothing
 * @stack: pointer to the head of the stack
 * @line_number: the index of the current line
 * Return: void
 */

void    nop(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;
}
