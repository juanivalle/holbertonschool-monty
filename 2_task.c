#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: the line number of the pop instruction
 */
void pop(stack_t **stack, unsigned int n)
{
	(void) n;
	stack_t *top;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(top);
}

