#include "monty.h"
char *args[2];

/**
 * stacks - function that switch to default LIFO
 * @stack: double pointer to the head of the stack
 * @line_number: the index of the current line we ar working on
 * Return: void
 */
void stacks(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;

	args[1] = "stack";
}

/**
 * queue - function that switch to default FIFO
 * @stack: double pointer to the head of the stack
 * @line_number: the index of the current line we ar working on
 * Return: void
 */
void queue(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;

	args[1] = "queue";
}
