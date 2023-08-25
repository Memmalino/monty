#include "monty.h"
char *args[2];
/**
 * push - function that push data to the stack
 * @stack: pointer to the head of the stack
 * @line_number: the index of the current line being executed
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	if (!args[0])
		print_error(3, NULL, "push", line_number);
	else
	{
		value = atoi(args[0]);
		if  (value == 0 && strcmp(args[0], "0") != 0)
		{
			free(args[0]);
			print_error(3, NULL, "push", line_number);
		}
		free(args[0]);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

