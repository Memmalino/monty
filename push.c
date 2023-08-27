#include "monty.h"
char *args[2];
int validity(int line_number);
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
		value = validity(line_number);

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	if (strcmp(args[1], "queue") == 0)
		rotl(stack, line_number);
}
/**
 * validity - function that checks if the argument is number
 * @line_number: the index of the current line
 * Return: the converted number or exit with exit_failure
 */
int validity(int line_number)
{
	int valid, len, i, value;

	valid = 1;
	len = strlen(args[0]);
	if (len > 0 && (args[0][0] == '-' || args[0][0] == '+'))
	{
		for (i = 1; i < len; i++)
		{
			if (!isdigit(args[0][i]))
			{
				valid = 0;
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			if (!isdigit(args[0][i]))
			{
				valid = 0;
				break;
			}
		}
	}
	if (!valid)
	{
		free(args[0]);
		print_error(3, NULL, "push", line_number);
	}

	value = atoi(args[0]);
	return (value);
}
