#include "monty.h"

/**
 * add - add elements on the stack
 * @stack: the stack
 * @line_number: the line number of the add instruction
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't aad, stack too short\n",
			line_number);
		if (*stack)
			frees(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
}

