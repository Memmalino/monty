#include "monty.h"
/**
 * swap - funct that swaps the value of fisrt stack and second stack
 * @stack: pointer to the head of the stack
 * @line_number: the current index of the current line
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = current;

}
/**
 * add - computes the rest of the divideision of the second top element
 * of the stack by the top element of the stack
 * @stack: head stack
 * @line_number: line number
 **/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (args[0] != NULL)
			free(args[0]);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head  = *stack;
	*stack = (*stack)->next;
	(*stack)->n  += head->n;
	free(head);
}
