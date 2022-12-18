#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number of the push instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *new;

	if (!stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the stack
 * @line_number: the line number of the pall instruction (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

