#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number of the push instruction
 */
void push(stack_t **stack, unsigned int n)
{
	(void) n;
	stack_t *new = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees(stack);
		exit(EXIT_FAILURE);
	}

	new->prev = new->next = NULL;

	if (!(*stack))
		(*stack) = new;
	else
	{
		if (*stack)
			(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the stack
 * @line_number: the line number of the pall instruction (unused)
 */
void pall(stack_t **stack, unsigned int n)
{
	(void) n;
	stack_t *current, *head;

	if (!stack || !(*stack))
		return;

	current = head = *stack;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

